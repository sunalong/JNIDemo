#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_itcode_jnidemo_utils_NativeEngine_encryptInCpp(JNIEnv *env, jobject instance, jstring rawStr_) {
    jint size = env->GetStringUTFLength(rawStr_);
    const char *rawStr = env->GetStringUTFChars(rawStr_, 0);
    char * retValue = new char[size+1];
    strcpy(retValue,rawStr);
    for(int i=0;i<size;i++){
        *(retValue+i) = *(rawStr+i)+1;
        LOGD("【jni_log】encryptInCpp,rawStr:%d,%s", i, retValue);
    }
    env->ReleaseStringUTFChars(rawStr_, rawStr);

    return env->NewStringUTF(retValue);
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_itcode_jnidemo_utils_NativeEngine_decryptInCpp(JNIEnv *env, jobject instance, jstring cipherText_) {
    const char *cipherText = env->GetStringUTFChars(cipherText_, 0);
    jint size = env->GetStringUTFLength(cipherText_);
    std::string returnValue= "";
    for (int i = 0; i < size; i++) {
        returnValue += *(cipherText+i) - 1;
        LOGD("【jni_log】decryptInCpp,cipherText:%d,%s", i, returnValue.c_str());
    }
    env->ReleaseStringUTFChars(cipherText_, cipherText);
    return env->NewStringUTF(returnValue.c_str());

//    jstring returnValue = env->NewStringUTF("");
//    for (int i = 0; i < size; i++) {
//        returnValue += *(cipherText+i) - 1;
//        LOGD("【jni_log】decryptInCpp,cipherText:%d,%s", i, returnValue);
//    }
//    env->ReleaseStringUTFChars(cipherText_, cipherText);
//    return returnValue;

//    return env->NewStringUTF(returnValue.c_str());
}