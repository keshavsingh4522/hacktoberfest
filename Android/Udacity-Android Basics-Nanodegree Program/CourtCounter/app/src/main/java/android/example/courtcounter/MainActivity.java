package android.example.courtcounter;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public TextView textView3;
    public TextView textView4;
    int pointA = 0;
    int pointB = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView3 = findViewById(R.id.textView3);
        textView4 = findViewById(R.id.textView4);
    }
    public void A_point3(View view){
        pointA += 3;
        displayA(pointA);
    }
    public void A_point2(View view){
        pointA += 2;
        displayA(pointA);
    }
    public void A_Free(View view){
        pointA += 1;
        displayA(pointA);
    }

    public void B_point3(View view){
        pointB += 3;
        displayB(pointB);
    }
    public void B_point2(View view){
        pointB += 2;
        displayB(pointB);
    }
    public void B_Free(View view){
        pointB += 1;
        displayB(pointB);
    }

    public void displayB(int point){
        textView4.setText(""+point);
    }
    public void displayA(int point){
        textView3.setText(""+point);
    }

    public void reset(View view){
        pointA = 0;
        pointB = 0;
        displayA(pointA);
        displayB(pointB);
    }
}