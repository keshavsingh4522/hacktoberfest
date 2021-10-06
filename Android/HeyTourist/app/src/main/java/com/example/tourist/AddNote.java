package com.example.tourist;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.example.tourist.Model.UserNotes;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class AddNote extends AppCompatActivity {
    private String country ;
    private TextView country_test,user_test;
    private TextView addNoteText;
    private Button addNoteBtn;
    private ProgressBar addNoteProgress;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_note);
        final DatabaseReference mDatabase;

        mDatabase = FirebaseDatabase.getInstance().getReference();

        addNoteBtn = (Button) findViewById(R.id.add_note_btn);
        addNoteText = (TextView) findViewById(R.id.add_note_text);
        addNoteProgress = (ProgressBar) findViewById(R.id.addNoteProgress);


        //getting new session and get userId value
        SessionManagement sessionManagement = new SessionManagement(AddNote.this);
        final String UserName = sessionManagement.getSession();

        Login LoginObj = new Login();

        if (savedInstanceState == null) {
            Bundle extras = getIntent().getExtras();
            if(extras == null){
                country=null;
            }
            else{
                country=extras.getString("Country"); //get values from extras from send by previous activity
            }
        }

        addNoteBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                addNoteProgress.setVisibility(View.VISIBLE);
                UserNotes newNote = new UserNotes(addNoteText.getText().toString());
                mDatabase.child("UserNotes").child(UserName).child(country).setValue(newNote);
                addNoteProgress.setVisibility(View.INVISIBLE);
                Toast.makeText(AddNote.this, "Note Added..!", Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(AddNote.this, Dashboard.class);startActivity(intent);

            }
        });
    }
}
