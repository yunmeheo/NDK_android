#include <jni.h>
#include <string>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>


extern "C" JNIEXPORT jlong JNICALL Java_com_example_yunmiheo_1or_ndk_1test_MainActivity_MicroSleep(JNIEnv *env, jobject /* this */) {
    jint iSleep = 60;
    struct timeval tv;
    if (iSleep > 70)
        iSleep -= 70;
    else
        iSleep = 0;

    tv.tv_sec = iSleep / 1000000;
    tv.tv_usec = iSleep % 1000000;

    jlong r = select(0, NULL, NULL, NULL, &tv);
    return r;
}


extern "C" JNIEXPORT jlong JNICALL Java_com_example_yunmiheo_1or_ndk_1test_MainActivity_TickCount(JNIEnv * env, jobject object) {
    struct timespec ts;

    long theTick = 0U;

    clock_gettime( CLOCK_MONOTONIC, &ts );

    theTick = ts.tv_sec * 1000000;
    theTick += ts.tv_nsec / 1000;

    return theTick;
}

extern "C" JNIEXPORT jlong JNICALL Java_com_example_yunmiheo_1or_ndk_1test_MainActivity_TickCountMilli(JNIEnv * env, jobject object) {
    struct timespec ts;

    long theTick = 0U;

    clock_gettime( CLOCK_MONOTONIC, &ts );

    theTick = ts.tv_sec * 1000;
    theTick += ts.tv_nsec / 1000000;

    return theTick;
}


extern "C" JNIEXPORT jint JNICALL Java_com_example_yunmiheo_1or_ndk_1test_MainActivity_SetFileSize(JNIEnv *env, jobject /*this*/, jstring strFile, jlong lSize) {

    const char *szFile =  env->GetStringUTFChars(strFile, 0);
    int fd;

    fd = open(szFile, O_WRONLY | O_CREAT, 0644);
    ftruncate(fd, lSize);
    close(fd);

    return 1;
}
