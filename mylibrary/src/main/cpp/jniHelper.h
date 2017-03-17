//
// Created by sunalong on 17/3/17 09:37.
// Email:466210864@qq.com
//

#ifndef JNIDEMO_JNIHELPER_H
#define JNIDEMO_JNIHELPER_H

#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class JNIHelper {
private:
//    设置为静态，以便全局唯一
    static JavaVM *jvmGlobal;
public:
    static JavaVM *getJvmGlobal();

    static void setJvmGlobal(JavaVM *jvmGlobal);
};

#endif //JNIDEMO_JNIHELPER_H
