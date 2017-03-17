//
// Created by sunalong on 17/3/17 10:24.
// Email:466210864@qq.com
//
#ifndef JNIDEMO_CPPCALLJAVA_H
#define JNIDEMO_CPPCALLJAVA_H

#include "jniHelper.h"

class CppCallJava {
public:
    JNIEnv *callJavaMethod(JNIEnv *jniEnv,const _jstring *nameJstr, const _jstring *toastJstr,jobject activity);

    JNIEnv *callJavaMethodStr(JNIEnv *jniEnv,const _jstring *nameJstr, const _jstring *toastJstr,jobject activity);
};

#endif //JNIDEMO_CPPCALLJAVA_H
