package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

import com.example.tourist.R;
import com.google.android.material.bottomnavigation.BottomNavigationView;

public class ProfielActivity extends AppCompatActivity implements BottomNavigationView.OnNavigationItemSelectedListener{
    Button btnLogout;
    protected BottomNavigationView navigationView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profiel);
        btnLogout = (Button)findViewById(R.id.logout);
        navigationView = (BottomNavigationView) findViewById(R.id.navigation);
        navigationView.setOnNavigationItemSelectedListener(this);
    }
    public void logout(View view) {
        //this method will remove session and open login screen
        SessionManagement sessionManagement = new SessionManagement(ProfielActivity.this);
        sessionManagement.removeSession();
        moveToLogin();
    }
    private void moveToLogin() {
        Intent intent = new Intent(ProfielActivity.this, Login.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK|Intent.FLAG_ACTIVITY_NEW_TASK);
        startActivity(intent);
    }

    @Override
    public boolean onNavigationItemSelected(@NonNull final MenuItem item) {
        navigationView.postDelayed(new Runnable() {
            @Override
            public void run() {
                int itemId = item.getItemId();
                if (itemId == R.id.action_home) {
                    ProfielActivity.this.startActivity(new Intent(ProfielActivity.this, Dashboard.class));
                } else if (itemId == R.id.action_profile) {
                    ProfielActivity.this.startActivity(new Intent(ProfielActivity.this, ProfielActivity.class));
                } else if (itemId == R.id.action_favorite) {
                    ProfielActivity.this.startActivity(new Intent(ProfielActivity.this, favourits.class));
                }
                ProfielActivity.this.finish();
            }
        }, 300);
        return true;
    }
}
