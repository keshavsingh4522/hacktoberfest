package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.example.tourist.Model.Tourist;
import com.example.tourist.Model.Users;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class Login extends AppCompatActivity {
    ImageView bgapp, clover;
    LinearLayout textsplash, texthome;
    ConstraintLayout menus;
    Animation frombottom;
    EditText edtPhone,edtPassword;
    Button btnSignIn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        frombottom = AnimationUtils.loadAnimation(this, R.anim.frombottom);bgapp = findViewById(R.id.bgapp);
        clover = findViewById(R.id.clover);menus = findViewById(R.id.menus);textsplash = findViewById(R.id.textsplash);
        texthome = findViewById(R.id.texthome);bgapp.animate().translationY(-1900).setDuration(1200).setStartDelay(800);
        clover.animate().alpha(0).setDuration(1500).setStartDelay(1000);textsplash.animate().translationY(140).alpha(0).setDuration(1000).setStartDelay(1000);
        texthome.startAnimation(frombottom);menus.startAnimation(frombottom);

        //Assign the texts and button ID to Variables
        edtPhone = (EditText)findViewById(R.id.edtEmail);
        btnSignIn = (Button) findViewById(R.id.btnSignIn);
        edtPassword = (EditText)findViewById(R.id.edtPassword);
        checkSession();
    }
    private void checkSession() {
        //check if user is logged in
        //if user is logged in --> move to mainActivity

        SessionManagement sessionManagement = new SessionManagement(Login.this);
        String userID = sessionManagement.getSession();

        if(userID != null){
            //user id logged in and so move to mainActivity
            moveToMainActivity();
        }
        else{
            login();
        }
    }

    private void moveToMainActivity() {
        Intent intent = new Intent(Login.this, Dashboard.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK|Intent.FLAG_ACTIVITY_NEW_TASK);
        startActivity(intent);
    }
    public void login()
    {
        //Init firebase and assign the Object
        final FirebaseDatabase database = FirebaseDatabase.getInstance();
        //Reffer a specific child
        final DatabaseReference table_User = database.getReference("Users");
        //set the onClick Listner to button
        btnSignIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final ProgressDialog mDialog = new ProgressDialog(Login.this);
                mDialog.setMessage("Please waiting.....");
                mDialog.show();
                table_User.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        //Check If User doesn't exist in db
                        if(dataSnapshot.child(edtPhone.getText().toString()).exists()) {
                            // Get User Info
                            mDialog.dismiss();
                            Users users = dataSnapshot.child(edtPhone.getText().toString()).getValue(Users.class);
                            if (users.getPassword().equals(edtPassword.getText().toString())) {
                                Toast.makeText(Login.this, "Sign In SuccessFully !", Toast.LENGTH_SHORT).show();
                                users.setPhone(edtPhone.getText().toString());
                                SessionManagement sessionManagement = new SessionManagement(Login.this);
                                sessionManagement.saveSession(users);
                                {Intent intent = new Intent(Login.this, Dashboard.class);startActivity(intent);}
                            }
                            else
                            { Toast.makeText(Login.this, "Sign In Failed !", Toast.LENGTH_SHORT).show();
                            }
                        }
                        else
                        {
                            mDialog.dismiss();
                            Toast.makeText(Login.this, "User not exist!", Toast.LENGTH_SHORT).show();
                        }
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) {

                    }
                });
            }
        });
    }
    public void Movesignup(View view)
    { Intent intent = new Intent(this, SignUp.class);startActivity(intent);}
}
