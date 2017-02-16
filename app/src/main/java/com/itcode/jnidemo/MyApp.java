package com.itcode.jnidemo;

import android.app.Application;

import org.xutils.x;

/**
 * Created by along on 17/2/16 11:48.
 * Email:466210864@qq.com
 */

public class MyApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        x.Ext.init(this);
        x.Ext.setDebug(BuildConfig.DEBUG); // 是否输出debug日志, 开启debug会影响性能.
    }
}
