//
// Created by sunalong on 17/3/17 09:37.
// Email:466210864@qq.com
//
#include "jniHelper.h"

JavaVM *JNIHelper::jvmGlobal = nullptr;
jclass JNIHelper::forNativeCallClassId = nullptr;

JavaVM *JNIHelper::getJvmGlobal() {
    return jvmGlobal;
}

void JNIHelper::setJvmGlobal(JavaVM *javaVM) {
    jvmGlobal = javaVM;
}

const jclass JNIHelper::getForNativeCallClassId() {
    return forNativeCallClassId;
}

void JNIHelper::setForNativeCallClassId(const jclass &forNativeCall) {
    forNativeCallClassId = forNativeCall;

}





//const jclass JNIHelper::getForNativeCallClassId() {
//    return forNativeCallClassId;
//}
//
//void JNIHelper::setForNativeCallClassId(jclass &forNativeCall) {
//    forNativeCallClassId = forNativeCallClassId;
//}










