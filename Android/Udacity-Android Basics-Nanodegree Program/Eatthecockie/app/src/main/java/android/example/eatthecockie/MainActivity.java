package android.example.eatthecockie;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView textView;
    private ImageView imageView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        imageView = findViewById(R.id.imageView);
        textView = findViewById(R.id.textView);
    }

    public void cockie(View view){
        textView.setText("I am so full!");
        imageView.setImageResource(R.drawable.after_cookie);
    }
    public void moreCockie(View view){
        textView.setText("I am so hungry!");
        imageView.setImageResource(R.drawable.before_cookie);
    }

}