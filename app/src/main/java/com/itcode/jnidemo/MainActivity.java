package com.itcode.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


import com.itcode.mylibrary.NativeEngine;

import org.xutils.view.annotation.ViewInject;
import org.xutils.x;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    @ViewInject(R.id.btnEncrypt)
    private Button btnEncrypt;
    @ViewInject(R.id.etRawStr)
    private EditText etRawStr;
    @ViewInject(R.id.etShowCipherText)
    private EditText etShowCipherText;
    @ViewInject(R.id.btnDecrypt)
    private Button btnDecrypt;
    @ViewInject(R.id.etdecrypt)
    private EditText etdecrypt;
    @ViewInject(R.id.etShowClearText)
    private EditText etShowClearText;
    NativeEngine nativeEngine;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        x.view().inject(this);
        setListener();
        nativeEngine = new NativeEngine();
        nativeEngine.register(this);
    }

    private void setListener() {
        btnEncrypt.setOnClickListener(this);
        btnDecrypt.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnEncrypt:
                if (TextUtils.isEmpty(etRawStr.getText())) {
                    Toast.makeText(this, "请输入要加密的字符串", Toast.LENGTH_SHORT).show();
                    return;
                }
                String cipherText = nativeEngine.encryptInCpp(etRawStr.getText().toString().trim());
                etShowCipherText.setText(cipherText);
                break;
            case R.id.btnDecrypt:
                if (TextUtils.isEmpty(etdecrypt.getText())) {
                    Toast.makeText(this, "请输入要解密的字符串", Toast.LENGTH_SHORT).show();
                    return;
                }
                String clearText = nativeEngine.decryptInCpp(etdecrypt.getText().toString().trim());
                etShowClearText.setText(clearText);
                break;
        }
    }
}
