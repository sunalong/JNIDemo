package com.itcode.mylibrary;

import android.app.Activity;
import android.util.Log;
import android.widget.Toast;

/**
 * Created by along on 17/2/16 11:22.
 * Email:466210864@qq.com
 * Android中的方法，供 Cpp 来调用
 */

public class ForNativeCall {
    private static final String TAG = ForNativeCall.class.getSimpleName();
    private String name;
    private long time;
    private Activity activity;

    public ForNativeCall(Activity activity) {
        this.activity = activity;
        Log.i(TAG,"ForNativeCall(Activity activity)");
    }

    public ForNativeCall(String name, Activity activity) {
        this.name = name;
        this.activity = activity;
        Log.i(TAG,"ForNativeCall(String name, Activity activity)");
    }

    public long getTime() {
        time = System.currentTimeMillis();
        return time;
    }

    /**
     * 供 Cpp 调用
     *
     * @param showStr
     * @return
     */
    private long showToast(String showStr) {
        Toast.makeText(activity, name + " :" + showStr+" "+getTime(), Toast.LENGTH_SHORT).show();
        return getTime();
    }
    public String getLoginUserInfo(){
        String str =  "getLoginUserInfo,Time:"+System.currentTimeMillis();
        Log.i(TAG,"Java:"+str);
        return str;
    }
}
