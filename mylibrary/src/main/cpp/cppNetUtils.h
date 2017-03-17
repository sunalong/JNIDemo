//
// Created by sunalong on 17/3/17 11:35.
// Email:466210864@qq.com
//

#ifndef JNIDEMO_CPPNETUTILS_H
#define JNIDEMO_CPPNETUTILS_H
#include "define.h"

class CppNetUtils{
public:
    /**
     * Todo:第一个参数为何强行加上 const?
     */
    bool getDeviceInfo(const CallbackFunc & callbackFunc,const char* deviceModel,int timeout);

};
#endif //JNIDEMO_CPPNETUTILS_H
