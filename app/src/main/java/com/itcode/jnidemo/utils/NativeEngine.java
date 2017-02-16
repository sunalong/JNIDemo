package com.itcode.jnidemo.utils;

/**
 * Created by along on 17/2/16 11:30.
 * Email:466210864@qq.com
 */

public class NativeEngine {
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
}
