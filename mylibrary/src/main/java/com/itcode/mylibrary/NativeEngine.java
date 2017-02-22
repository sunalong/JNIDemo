package com.itcode.mylibrary;

import android.app.Activity;

/**
 * Created by along on 17/2/16 11:30.
 * Email:466210864@qq.com
 */

public class NativeEngine {
    /**
     * 用于将上下文传给 Cpp 层
     * @param activity
     */
    public native void register(Activity activity);
    /**
     * 在 Cpp 中加密
     * @param rawStr 原始字符
     * @return 加密后的字符
     */
    public native String encryptInCpp(String rawStr);
    /**
     * 在 Cpp 中解密
     * @param cipherText 密文
     * @return 解密后的字符
     */
    public native String decryptInCpp(String cipherText);
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
