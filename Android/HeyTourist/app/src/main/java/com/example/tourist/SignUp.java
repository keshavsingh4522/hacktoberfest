package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.example.tourist.Model.Users;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class SignUp extends AppCompatActivity {
    EditText edtPhone,edtEmail,edtName,edtPassword;
    Button btnSignUp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup);

        //Assign Button and texts id to variables
        edtName = (EditText)findViewById(R.id.edtName);
        edtPhone = (EditText) findViewById(R.id.edtPhone);
        edtEmail =(EditText) findViewById(R.id.edtEmail);
        edtPassword = (EditText)findViewById(R.id.edtPassword);
        btnSignUp = (Button)findViewById(R.id.btnSignUp);

        //Init firebase object
        FirebaseDatabase database = FirebaseDatabase.getInstance();
        final DatabaseReference table_Tourist = database.getReference("Users");
        btnSignUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final ProgressDialog mDialog = new ProgressDialog(SignUp.this);
                mDialog.setMessage("Please waiting.....");
                mDialog.show();
                table_Tourist.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        if(dataSnapshot.child(edtPhone.getText().toString()).exists())
                        {
                            mDialog.dismiss();
                            Toast.makeText(SignUp.this, "Tourist already Registered !", Toast.LENGTH_SHORT).show();
                        }
                        else
                        {
                            mDialog.dismiss();
                            Users users = new Users(edtName.getText().toString(),edtPassword.getText().toString(),edtEmail.getText().toString(),null);
                            table_Tourist.child(edtPhone.getText().toString()).setValue(users);
                            Toast.makeText(SignUp.this, "Registration Complete !", Toast.LENGTH_SHORT).show();
                            {Intent intent = new Intent(SignUp.this, Dashboard.class);startActivity(intent);}
                        }
                    }
                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) { }
                });
            }
        });
    }
    public void BackSignin(View view)
    {Intent intent = new Intent(this, Login.class);startActivity(intent);}
}
