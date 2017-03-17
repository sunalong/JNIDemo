//
// Created by sunalong on 17/3/16 22:57.
// Email:466210864@qq.com
//

/**
 * JNI 启动时的入口
 */
#include "jniHelper.h"
extern "C" {
jint JNIEXPORT JNICALL  JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGD("【jni_log】JNI_OnLoad");
    JNIHelper::setJvmGlobal(vm);//保存全局的 javaVM,以便后来使用
    return JNI_VERSION_1_4;
}
}