package com.example.yunmiheo_or.ndk_test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.io.Console;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv1 = findViewById(R.id.sample_text1);
        TextView tv2 = findViewById(R.id.sample_text2);
        TextView tv3 = findViewById(R.id.sample_text3);

        tv1.setText(String.valueOf(MicroSleep(5000)));
        tv2.setText(String.valueOf(TickCount()));
        tv3.setText(String.valueOf(TickCountMilli()));
        int i = SetFileSize("FileName", 5000000);
        Log.i("SetFileSize :",String.valueOf(i));

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native long MicroSleep(int iSleep);
    public native long TickCount();
    public native long TickCountMilli();
    public native int SetFileSize(String strFile, long lSize);

}
