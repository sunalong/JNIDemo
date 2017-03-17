//
// Created by sunalong on 17/3/17 09:37.
// Email:466210864@qq.com
//
#include "jniHelper.h"
JavaVM *JNIHelper::jvmGlobal = nullptr;
JavaVM *JNIHelper::getJvmGlobal() {
    return jvmGlobal;
}

void JNIHelper::setJvmGlobal(JavaVM *javaVM) {
    jvmGlobal = javaVM;
}






