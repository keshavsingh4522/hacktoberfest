package com.example.currencyconverter;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
 public void buttonclick(View view)
 {
     EditText amount1=findViewById(R.id.amount);
     TextView converted=findViewById(R.id.textView2);

     float x = Float.parseFloat(amount1.getText().toString());
     double y=x*3.64;
     converted.setText(String.valueOf(y)+" QR");

 }
    public void clearb(View view) {
        EditText amount1=findViewById(R.id.amount);
        TextView converted=findViewById(R.id.textView2);

        amount1.setText(" ");
        converted.setText(" ");
    }
}