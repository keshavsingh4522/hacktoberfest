package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class CountryNote extends AppCompatActivity {
    private String country;
    private ImageView newNote;
    private TextView noteTitle;
    private String Note;
    private TextView noteField;
    DatabaseReference ref;

    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_country_note);
        newNote = (ImageView) findViewById(R.id.add_new_note_btn);
        noteTitle = (TextView) findViewById(R.id.noteTitle);
        noteField = (TextView) findViewById(R.id.viewNote);


        SessionManagement sessionManagement = new SessionManagement(CountryNote.this);
        final String UserName = sessionManagement.getSession();


        if (savedInstanceState == null) {
            Bundle extras = getIntent().getExtras();
            if(extras == null){

                country=null;
            }
            else{

                country=extras.getString("Country"); //get values from extras from send by previous activity
                noteTitle.setText("My Personal note about "+country);
            }
        }

        newNote.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent sendCountry = new Intent(CountryNote.this, AddNote.class);
                sendCountry.putExtra("Country",country);
                startActivity(sendCountry);
            }
        });

        ref= FirebaseDatabase.getInstance().getReference().child("UserNotes").child(UserName).child(country);
        this.Start();
    }

    private void Start() {

        ref.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {

                Note = dataSnapshot.child("userNote").getValue(String.class);
                noteField.setText(Note);

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {
                //......
            }
        });
    }
}
