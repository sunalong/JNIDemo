package com.itcode.jnidemo.utils;

import android.app.Activity;
import android.widget.Toast;

/**
 * Created by along on 17/2/16 11:22.
 * Email:466210864@qq.com
 * Android中的方法，供 Cpp 来调用
 */

public class ForNativeCall {
    private String name;
    private long time;
    private Activity activity;

    public ForNativeCall(String name, Activity activity) {
        this.name = name;
        this.activity = activity;
    }

    public long getTime() {
        time = System.currentTimeMillis();
        return time;
    }

    private long showToast(String showStr) {
        Toast.makeText(activity, showStr, Toast.LENGTH_SHORT).show();
        return getTime();
    }
}
