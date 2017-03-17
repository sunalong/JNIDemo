//
// Created by sunalong on 17/3/17 11:24.
// Email:466210864@qq.com
//
#ifndef JNIDEMO_DEFINE_H
#define JNIDEMO_DEFINE_H

/**
 * 回调返回类型
 */
enum ResponseType {
    enUploadType = 0, //上传类型
    enCryptType, //加密类型
    enDecryptType,//解密类型
};
/**
 * 返回值类型
 */
enum ResponseCode {
    FailtureCode = 0, //失败
    SuccessCodeCode,//成功
};
/**
 * 定义函数指针类型，作为回调
 */
typedef void(*CallbackFunc)(ResponseType responseType,ResponseCode responseCode,const char* dataPtr);

#endif //JNIDEMO_DEFINE_H
