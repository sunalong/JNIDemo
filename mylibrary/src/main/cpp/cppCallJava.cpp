//
// Created by sunalong on 17/3/17 10:24.
// Email:466210864@qq.com
//
#include "cppCallJava.h"

JNIEnv *CppCallJava::callJavaMethod(JNIEnv *jniEnv,const _jstring *nameJstr, const _jstring *toastJstr,jobject activity) {
    //找到 class 类
    jclass classId = jniEnv->FindClass("com/itcode/mylibrary/ForNativeCall");
    //获取类的构造函数
    jmethodID constructorMethodId = jniEnv->GetMethodID(classId, "<init>", "(Ljava/lang/String;Landroid/app/Activity;)V");
    //使用构造函数创建对象
    jobject forNativeCallObj = jniEnv->NewObject(classId, constructorMethodId, nameJstr, activity);
    //获取要调用的方法
    jmethodID showToastId = jniEnv->GetMethodID(classId, "showToast", "(Ljava/lang/String;)J");
    //对象调用方法
    jniEnv->CallLongMethod(forNativeCallObj, showToastId, toastJstr);
    return jniEnv;
}

JNIEnv *CppCallJava::callJavaMethodStr(JNIEnv *jniEnv,const _jstring *nameJstr, const _jstring *toastJstr,jobject activity) {
    //找到 class 类
    jclass classId = jniEnv->FindClass("com/itcode/mylibrary/ForNativeCall");
    //获取类的构造函数
    jmethodID constructorMethodId = jniEnv->GetMethodID(classId, "<init>", "(Ljava/lang/String;Landroid/app/Activity;)V");
    //使用构造函数创建对象
    jobject forNativeCallObj = jniEnv->NewObject(classId, constructorMethodId, nameJstr, activity);
    //获取要调用的方法
    jmethodID getLoginUserInfoId = jniEnv->GetMethodID(classId, "getLoginUserInfo", "()Ljava/lang/String;");
    //对象调用方法
    jstring retJstr = (jstring) jniEnv->CallObjectMethod(forNativeCallObj, getLoginUserInfoId);
    const char *retChar = jniEnv->GetStringUTFChars(retJstr, 0);
    LOGD("【jni_log】callJavaMethodStr:%s", retChar);
    jniEnv->ReleaseStringUTFChars(retJstr, retChar);
    return jniEnv;
}



