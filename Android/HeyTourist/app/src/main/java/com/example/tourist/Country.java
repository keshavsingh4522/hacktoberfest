package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import com.bumptech.glide.Glide;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;

import java.util.ArrayList;
import java.util.Map;

public class Country extends AppCompatActivity implements BottomNavigationView.OnNavigationItemSelectedListener{
    String countryKeyVar,capitalCityVar,languageVar,currencyVar,cntryImg;
    TextView countryName,capitalCity,language,currency;
    ImageView countryImg;
    ListView listView;
    ArrayList<String> cityArray = new ArrayList<>();;
    ArrayAdapter<String> myArrayAdapter;
    StorageReference mStorageRef;
    DatabaseReference ref;
    Context context;
    protected BottomNavigationView navigationView;
    ImageView country_add_note;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_country);
        myArrayAdapter = new ArrayAdapter<>(this,android.R.layout.simple_list_item_1,cityArray);
        //Set Layout compoents to variables
        capitalCity = (TextView)findViewById(R.id.CapitalCity);
        language = (TextView)findViewById(R.id.Language);
        currency= (TextView)findViewById(R.id.Currency);
        listView = (ListView)findViewById(R.id.listView);
        countryImg = (ImageView)findViewById(R.id.countryImg);
        country_add_note = (ImageView) findViewById(R.id.country_add_note);


        country_add_note.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent sendCountry = new Intent(getApplicationContext(), CountryNote.class);
                sendCountry.putExtra("Country",countryKeyVar);
                startActivity(sendCountry);

            }
        });

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(getApplicationContext(),City.class);
                intent.putExtra("City",cityArray.get(position));
                intent.putExtra("Country",countryKeyVar);
                startActivity(intent);
            }
        });
        countryName = (TextView)findViewById(R.id.CountryName);
        mStorageRef = FirebaseStorage.getInstance().getReference();
        SessionManagement sessionManagement = new SessionManagement(Country.this);
        String UserName = sessionManagement.getSession();

        //checking the passed Country value from previous acitvity and set it to text
        if (savedInstanceState == null) {
            Bundle extras = getIntent().getExtras();
            if(extras == null)
            {countryKeyVar= null;}
            else
            {countryKeyVar= extras.getString("CountryName");countryName.setText(countryKeyVar);}
        }
        else
        {countryKeyVar= (String) savedInstanceState.getSerializable("CountryName");}
        //create the reference to the selected country
        ref= FirebaseDatabase.getInstance().getReference().child("Country").child(countryKeyVar);
        this.Start();
        navigationView = (BottomNavigationView) findViewById(R.id.navigation);
        navigationView.setOnNavigationItemSelectedListener(this);
    }
    public void Start() {
        //add the ValueListener to the selected reference and set it to the textViews
        ref.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                Map<String, Object> map = (Map<String, Object>) dataSnapshot.getValue();
                capitalCityVar = dataSnapshot.child("CapitalCity").getValue(String.class);
                capitalCity.setText(capitalCityVar);
                languageVar = dataSnapshot.child("Language").getValue(String.class);
                language.setText(languageVar);
                currencyVar = dataSnapshot.child("Currencies").getValue(String.class);
                currency.setText(currencyVar);
                if(map.get("CountryImg")!=null){
                    cntryImg = map.get("CountryImg").toString();
                    Glide.with(getApplication()).load(cntryImg).override(600, 200).into(countryImg);
                }
                for (DataSnapshot snap : dataSnapshot.child("OtherCities").getChildren()){
                    cityArray.add(snap.getKey());
                }
                listView.setAdapter(myArrayAdapter);
                myArrayAdapter.notifyDataSetChanged();
            }
            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {}
        });
    }
    public void BackDashboard(View view)
    {Intent intent = new Intent(this, Dashboard.class);startActivity(intent);}

    @Override
    public boolean onNavigationItemSelected(@NonNull final MenuItem item) {
        navigationView.postDelayed(new Runnable() {
            @Override
            public void run() {
                int itemId = item.getItemId();
                if (itemId == R.id.action_home) {
                    Country.this.startActivity(new Intent(Country.this, Dashboard.class));
                } else if (itemId == R.id.action_profile) {
                    Country.this.startActivity(new Intent(Country.this, ProfielActivity.class));
                } else if (itemId == R.id.action_favorite) {
                    Country.this.startActivity(new Intent(Country.this, favourits.class));
                }
                Country.this.finish();
            }
        }, 300);
        return true;
    }
}
