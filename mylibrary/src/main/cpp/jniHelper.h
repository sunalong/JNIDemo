//
// Created by sunalong on 17/3/17 09:37.
// Email:466210864@qq.com
//

#ifndef JNIDEMO_JNIHELPER_H
#define JNIDEMO_JNIHELPER_H

#include <jni.h>
#include <string>
#include <android/log.h>
#include <iostream>
#include <thread>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class JNIHelper {
private:
//    设置为静态，以便全局唯一
    static JavaVM *jvmGlobal;
    static jclass  forNativeCallClassId;//子线程中无法 FindClass 所以先在主线程中 Find,然后保存

public:
    static JavaVM *getJvmGlobal();

    static void setJvmGlobal(JavaVM *jvmGlobal);

    static const jclass getForNativeCallClassId();

    static void setForNativeCallClassId(const jclass &forNativeCallClassId) ;
};

#endif //JNIDEMO_JNIHELPER_H
