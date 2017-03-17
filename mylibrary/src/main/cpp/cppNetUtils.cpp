//
// Created by sunalong on 17/3/17 11:35.
// Email:466210864@qq.com
//
#include "cppNetUtils.h"
#include "jniHelper.h"

bool CppNetUtils::getDeviceInfo(const CallbackFunc &callbackFunc, const char *deviceModel, int timeout) {
    std::thread threadNet(callbackFunc,enUploadType,SuccessCodeCode,"lala子线程executeing");
    threadNet.join();//不加这一句会报错：A/libc: Fatal signal 6 (SIGABRT), code -6 in tid 21533 (.itcode.jnidemo)
            //因为主线程先于子线程执行完，主线程执行完后子线程就挂了，会引起异常
    LOGD("【jni_log】CppNetUtils::getDeviceInfo: deviceModel:%s, timeout:%d",deviceModel,timeout);
    return true;
}

