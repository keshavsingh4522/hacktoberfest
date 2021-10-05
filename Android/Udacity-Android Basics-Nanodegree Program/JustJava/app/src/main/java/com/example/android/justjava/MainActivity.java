package com.example.android.justjava;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private CheckBox chocolate;
    private CheckBox whipped_cream;
    private TextView textView;
    private TextView textView4;
    private EditText editTextTextPersonName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.textView);
        textView4 = findViewById(R.id.textView4);
        whipped_cream = findViewById(R.id.whipped_cream);
        editTextTextPersonName = findViewById(R.id.editTextTextPersonName);
        chocolate = findViewById(R.id.chocolate);
    }
    int num = 2;
    int price = 10;
    int basePrice;
    public void submitOrder(View view){
        Toast.makeText(this, "Thanks for placing the order", Toast.LENGTH_SHORT).show();
        Intent intent = new Intent(Intent.ACTION_SENDTO);
        intent.setData(Uri.parse("mailto:")); // only email apps should handle this
        String name = editTextTextPersonName.getText().toString();
        String subject = "coffee order for "+ name;
        intent.putExtra(android.content.Intent.EXTRA_EMAIL,new String[] { "isha6verma@gmail.com" });
        intent.putExtra(Intent.EXTRA_SUBJECT, subject);
        intent.putExtra(intent.EXTRA_TEXT, orderSummary());
        if (intent.resolveActivity(getPackageManager()) != null) {
            startActivity(intent);
        }
    }
    public void increment(View view){
        if (num<100){
            num++;
        }else{
            Toast.makeText(this, "Sorry! we cannot deliver more than 100 cups", Toast.LENGTH_SHORT).show();
        }
        display(num);
        price = calculatePrice();
        displayPrice(basePrice);
    }
    public void decrement(View view){
        if (num>1){
            num--;
        }
        else{
            Toast.makeText(this, "Cannot order less than 1 cups!", Toast.LENGTH_SHORT).show();
        }
        display(num);
        price = calculatePrice();
        displayPrice(basePrice);
    }

    public int calculatePrice(){
        basePrice = 5;
        if (whipped_cream.isChecked()){
            basePrice +=1;
        }
        if (chocolate.isChecked()){
            basePrice +=2;
        }
        price = basePrice*num;
        return price;
    }

    public void chechBox(View view){
        calculatePrice();
        displayPrice(basePrice);
    }

    public String orderSummary(){
        String  message = "Order Summary: \nName : "+editTextTextPersonName.getText();
        if (whipped_cream.isChecked()){
            message += "\nWhipped cream included";
        }
        if (chocolate.isChecked()){
            message += "\nChocolate included";
        }
        message += "\nQuantity : "+num +"\nPrice per cup : "+basePrice+"\nTotal : $"+price+"\nThankyou!!";
        return message;
    }
    public void display(int num){
        textView.setText(""+num);
    }
    public void displayPrice(int price){
        textView4.setText("$"+ price);
    }
}