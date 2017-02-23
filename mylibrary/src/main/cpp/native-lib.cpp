#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
JavaVM *vmGlobal = NULL;
JNIEnv *envGlobal = NULL;
jobject activityGlobal = NULL;

JNIEnv *callJavaMethod(const _jstring *nameJstr, const _jstring *toastJstr);

JNIEnv *callJavaMethodStr(const _jstring *nameJstr, const _jstring *toastJstr);

extern "C"
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    vmGlobal = reinterpret_cast<JavaVM *>(vm);
    return JNI_VERSION_1_4;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_itcode_mylibrary_NativeEngine_register(JNIEnv *env, jobject instance, jobject activity) {
//    envGlobal = reinterpret_cast<JNIEnv *>(env);
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

    if (vmGlobal->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        LOGD("【jni_log】vmGlobal->GetEnv((void**)&env,JNI_VERSION_1_4)!=JNI_OK");
    }
    jstring nameJstr = env->NewStringUTF("encryptInCpp");
    jstring toastJstr = env->NewStringUTF("cpp加密成功");
    //调用 Java 的方法
    env = callJavaMethod(nameJstr, toastJstr);
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
    callJavaMethod(nameJstr, toastJstr);
    callJavaMethodStr(nameJstr, toastJstr);
    return env->NewStringUTF(returnValue.c_str());
}

JNIEnv *callJavaMethod(const _jstring *nameJstr, const _jstring *toastJstr) {
    //找到 class 类
    JNIEnv *env;
    env = envGlobal;
    jclass classId = envGlobal->FindClass("com/itcode/mylibrary/ForNativeCall");
    //获取类的构造函数
    jmethodID constructorMethodId = envGlobal->GetMethodID(classId, "<init>", "(Ljava/lang/String;Landroid/app/Activity;)V");
    //使用构造函数创建对象
    jobject forNativeCallObj = envGlobal->NewObject(classId, constructorMethodId, nameJstr, activityGlobal);
    //获取要调用的方法
    jmethodID showToastId = envGlobal->GetMethodID(classId, "showToast", "(Ljava/lang/String;)J");
    //对象调用方法
    envGlobal->CallLongMethod(forNativeCallObj, showToastId, toastJstr);
    return env;
}

JNIEnv *callJavaMethodStr(const _jstring *nameJstr, const _jstring *toastJstr) {
    //找到 class 类
    JNIEnv *env;
    env = envGlobal;
    jclass classId = envGlobal->FindClass("com/itcode/mylibrary/ForNativeCall");
    //获取类的构造函数
    jmethodID constructorMethodId = envGlobal->GetMethodID(classId, "<init>", "(Ljava/lang/String;Landroid/app/Activity;)V");
    //使用构造函数创建对象
    jobject forNativeCallObj = envGlobal->NewObject(classId, constructorMethodId, nameJstr, activityGlobal);
    //获取要调用的方法
    jmethodID getLoginUserInfoId = envGlobal->GetMethodID(classId, "getLoginUserInfo", "()Ljava/lang/String;");
    //对象调用方法
    jstring retJstr = (jstring) envGlobal->CallObjectMethod(forNativeCallObj, getLoginUserInfoId);
    const char *retChar = envGlobal->GetStringUTFChars(retJstr, 0);
    LOGD("【jni_log】callJavaMethodStr:%s", retChar);
    envGlobal->ReleaseStringUTFChars(retJstr, retChar);
    return env;
}