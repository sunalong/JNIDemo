//
// Created by sunalong on 17/3/17 10:24.
// Email:466210864@qq.com
//
#ifndef JNIDEMO_CPPCALLJAVA_H
#define JNIDEMO_CPPCALLJAVA_H

#include "jniHelper.h"
#include "define.h"

class CppCallJava {
public:
    JNIEnv *callJavaMethod(JNIEnv *jniEnv, const _jstring *nameJstr, const _jstring *toastJstr, jobject activity);

    JNIEnv *callJavaMethodStr(JNIEnv *jniEnv, const _jstring *nameJstr, const _jstring *toastJstr, jobject activity);

    void retDataToJava(ResponseType type, ResponseCode code, const char *dataPtr);
};
#endif //JNIDEMO_CPPCALLJAVA_H
