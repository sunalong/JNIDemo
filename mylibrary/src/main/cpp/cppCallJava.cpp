//
// Created by sunalong on 17/3/17 10:24.
// Email:466210864@qq.com
//
#include "cppCallJava.h"

JNIEnv *CppCallJava::callJavaMethod(JNIEnv *jniEnv, const _jstring *nameJstr, const _jstring *toastJstr, jobject activity) {
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

JNIEnv *CppCallJava::callJavaMethodStr(JNIEnv *jniEnv, const _jstring *nameJstr, const _jstring *toastJstr, jobject activity) {
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
    LOGD("cppCallJava callJavaMethodStr:%s", retChar);
    jniEnv->ReleaseStringUTFChars(retJstr, retChar);
    return jniEnv;
}

/**
 * 把数据从 Cpp 传到 Java
 * 有可能在子线程中调用
 */
void CppCallJava::retDataToJava(ResponseType type, ResponseCode code, const char *dataPtr) {
    JNIEnv *jniEnv;
    bool isAttached = false;
    if (!JNIHelper::getJvmGlobal()) {
        LOGD("CppCallJava::retDataToJava jvm is null");
        return;
    }
    jint retCode = JNIHelper::getJvmGlobal()->GetEnv((void **) &jniEnv, JNI_VERSION_1_4);
    if (retCode != JNI_OK) {
        jint res = JNIHelper::getJvmGlobal()->AttachCurrentThread(&jniEnv, nullptr);
        if (res < 0 || !jniEnv) {
            LOGD("CppCallJava::retDataToJava  retCode:%d !=JNI_OK:%d,AttachCurrentThread:%d", retCode, JNI_OK, res);
            return;
        }
        isAttached = true;
    }
    //找到 class 类
//    jclass classId = jniEnv->FindClass("com/itcode/mylibrary/ForNativeCall");//子线程中调用 FindClass 不会成功
    jclass classId = JNIHelper::getForNativeCallClassId();
    //获取类的构造函数
    jmethodID constructorMethodId = jniEnv->GetMethodID(classId, "<init>", "()V");
    //使用构造函数创建对象
    jobject forNativeCallObj = jniEnv->NewObject(classId, constructorMethodId);
    //获取要调用的方法
    jmethodID receiveDataFromC = jniEnv->GetMethodID(classId, "receiveDataFromC", "(IILjava/lang/String;)V");
    //对象调用方法
    jstring jstr;
    if (dataPtr == nullptr)
        jstr = jniEnv->NewStringUTF("nullStr");
    else
        jstr = jniEnv->NewStringUTF(dataPtr);
    jniEnv->CallVoidMethod(forNativeCallObj, receiveDataFromC, type, code, jstr);

    if (jstr) {
        jniEnv->DeleteLocalRef(jstr);
    }
    if (isAttached) {
        if (JNIHelper::getJvmGlobal()->DetachCurrentThread() < 0)
            LOGD("cppCallJava retDataToJava could not detach thread from jvm");
    }
}





