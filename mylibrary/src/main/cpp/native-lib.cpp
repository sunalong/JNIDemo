#include "jniHelper.h"
#include "cppCallJava.h"

JNIEnv *envGlobal = NULL;
jobject activityGlobal = NULL;


extern "C" {
JNIEXPORT void JNICALL
Java_com_itcode_mylibrary_NativeEngine_register(JNIEnv *env, jobject instance, jobject activity) {
    envGlobal = env;
//    activityGlobal = activity;//注意与下一句的区别，报错为：E/dalvikvm: JNI ERROR (app bug): attempt to use stale local reference 0x20d00021
    activityGlobal = env->NewGlobalRef(reinterpret_cast<jobject>(activity));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_itcode_mylibrary_NativeEngine_encryptInCpp(JNIEnv *env, jobject instance, jstring rawStr_) {
    jint size = env->GetStringUTFLength(rawStr_);
    const char *rawStr = env->GetStringUTFChars(rawStr_, 0);
    char *retValue = new char[size + 1];
    strcpy(retValue, rawStr);
    for (int i = 0; i < size; i++) {
        *(retValue + i) = *(rawStr + i) + 1;
        LOGD("【jni_log】encryptInCpp,rawStr:%d,%s", i, retValue);
    }
    env->ReleaseStringUTFChars(rawStr_, rawStr);

    if (JNIHelper::getJvmGlobal()->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        LOGD("【jni_log】vmGlobal->GetEnv((void**)&env,JNI_VERSION_1_4)!=JNI_OK");
    }
    jstring nameJstr = env->NewStringUTF("encryptInCpp");
    jstring toastJstr = env->NewStringUTF("cpp加密成功");
    //调用 Java 的方法
    CppCallJava cppCallJava;
    env = cppCallJava.callJavaMethod(env, nameJstr, toastJstr, activityGlobal);
    return env->NewStringUTF(retValue);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_itcode_mylibrary_NativeEngine_decryptInCpp(JNIEnv *env, jobject instance, jstring cipherText_) {
    const char *cipherText = env->GetStringUTFChars(cipherText_, 0);
    jint size = env->GetStringUTFLength(cipherText_);
    std::string returnValue = "";
    for (int i = 0; i < size; i++) {
        returnValue += *(cipherText + i) - 1;
        LOGD("【jni_log】decryptInCpp,cipherText:%d,%s", i, returnValue.c_str());
    }
    env->ReleaseStringUTFChars(cipherText_, cipherText);

    //调用 Java 的方法
    jstring nameJstr = env->NewStringUTF("decryptInCpp");
    jstring toastJstr = env->NewStringUTF("cpp解密成功");
    CppCallJava cppCallJava;
    cppCallJava.callJavaMethod(env, nameJstr, toastJstr, activityGlobal);
    cppCallJava.callJavaMethodStr(env, nameJstr, toastJstr, activityGlobal);
    return env->NewStringUTF(returnValue.c_str());
}
}