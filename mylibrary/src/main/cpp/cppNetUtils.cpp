//
// Created by sunalong on 17/3/17 11:35.
// Email:466210864@qq.com
//
#include "cppNetUtils.h"
#include "jniHelper.h"

bool CppNetUtils::getDeviceInfo(const CallbackFunc &callbackFunc, const char *deviceModel, int timeout) {
    callbackFunc(enUploadType,SuccessCodeCode,"lala");
    LOGD("【jni_log】CppNetUtils::getDeviceInfo: deviceModel:%s, timeout:%d",deviceModel,timeout);
    return true;
}

