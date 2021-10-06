package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.SearchView;
import android.widget.Toast;

import com.example.tourist.Adapters.AdapterClass;
import com.example.tourist.Model.Tourist;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;

import java.util.ArrayList;

public class Dashboard extends AppCompatActivity implements BottomNavigationView.OnNavigationItemSelectedListener {

    DatabaseReference ref; // Create database reference object
    ArrayList<Tourist> list; // Create a array list to store firebase data
    ArrayList<String> names= new ArrayList<>();
    RecyclerView recyclerView; // create object for the Recycler View
    SearchView searchView; // create the object for the SearchView
    protected BottomNavigationView navigationView;
    String UserName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);
        ref= FirebaseDatabase.getInstance().getReference().child("Country"); // Refer to the country node in firebase database
        recyclerView = findViewById(R.id.rv);
        searchView = findViewById(R.id.searchView); // Assign the recycler view and search view to the objects
        navigationView = (BottomNavigationView) findViewById(R.id.navigation);
        SessionManagement sessionManagement = new SessionManagement(Dashboard.this);
        UserName = sessionManagement.getSession();

    }
    // set the Listener to the RecyclerView
    AdapterClass.RecyclerViewClickListener listener = new AdapterClass.RecyclerViewClickListener() {
        @Override
        public void onClick(View view, int position) {
            Intent intent = new Intent(Dashboard.this, Country.class);
            intent.putExtra("CountryName", names.get(position));
            startActivity(intent);
        }
    };
    @Override
    protected void onStart() {
        super.onStart();
        if(ref!=null){
            ref.addValueEventListener(new ValueEventListener() {
                @Override
                public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                    if(dataSnapshot.exists())
                    {   list= new ArrayList<>();
                        for(DataSnapshot ds : dataSnapshot.getChildren())
                        {   names.add(ds.getKey());
                            list.add(ds.getValue(Tourist.class)); // store firebase data to a list using tourist class
                        }
                        //Pass the Image with getApplicationContext,List and Listener to the recyclerview adapter
                        AdapterClass adapterClass = new AdapterClass(names,getApplicationContext(),list,listener,UserName);
                        recyclerView.setAdapter(adapterClass);
                    }
                }
                @Override
                public void onCancelled(@NonNull DatabaseError databaseError) {
                    Toast.makeText(Dashboard.this,databaseError.getMessage(),Toast.LENGTH_SHORT).show();
                }
            });
        }

        //Code for the Search function
        if(searchView != null)
        {
            searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
                @Override
                public boolean onQueryTextSubmit(String query) {return false;}
                @Override
                public boolean onQueryTextChange(String newText) {
                    search(newText);
                    return true;
                }
            });
        }
        navigationView.setOnNavigationItemSelectedListener(this);
    }
    private void search(String str){
        ArrayList<Tourist> myList = new ArrayList<>();
        if(list!=null)
        {
            for(Tourist object : list)
            {
                if(object.getCountryName().toLowerCase().contains(str.toLowerCase()))
                {myList.add(object);}
            }
        }
        AdapterClass adapterClass = new AdapterClass(names,getApplicationContext(),myList,listener,UserName);
        recyclerView.setAdapter(adapterClass);
    }

    @Override
    public boolean onNavigationItemSelected(@NonNull final MenuItem item) {
        navigationView.postDelayed(new Runnable() {
            @Override
            public void run() {
                int itemId = item.getItemId();
                if (itemId == R.id.action_home) {
                    Dashboard.this.startActivity(new Intent(Dashboard.this, Dashboard.class));
                } else if (itemId == R.id.action_profile) {
                    Dashboard.this.startActivity(new Intent(Dashboard.this, ProfielActivity.class));
                } else if (itemId == R.id.action_favorite) {
                    Dashboard.this.startActivity(new Intent(Dashboard.this, favourits.class));
                }
                Dashboard.this.finish();
            }
        }, 300);
        return true;
    }
}
