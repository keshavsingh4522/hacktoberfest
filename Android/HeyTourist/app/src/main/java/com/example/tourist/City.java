package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.StrictMode;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
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

import org.jetbrains.annotations.NotNull;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.Map;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class City extends AppCompatActivity implements BottomNavigationView.OnNavigationItemSelectedListener{
    String cityKeyVar,countryKeyVar,pop,air,ctyImg;
    TextView textView,view_city,view_temp,view_desc,population,airport;
    ImageView cityImg,view_weather;
    StorageReference mStorageRef;
    DatabaseReference ref;
    Context context;
    protected BottomNavigationView navigationView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_city);
        navigationView = (BottomNavigationView) findViewById(R.id.navigation);
        navigationView.setOnNavigationItemSelectedListener(this);
        
        //Assign Component ID to variables
        textView = (TextView)findViewById(R.id.cityName);
        view_city=findViewById(R.id.town);view_city.setText("");
        view_temp=findViewById(R.id.temp);view_temp.setText("");
        view_desc=findViewById(R.id.desc);view_desc.setText("");
        view_weather=findViewById(R.id.wheather_image);
        cityImg = (ImageView)findViewById(R.id.cityImg);
        population = (TextView)findViewById(R.id.population);
        airport = (TextView)findViewById(R.id.airport);
        //Create storage reference to retrive images from firebase
        mStorageRef = FirebaseStorage.getInstance().getReference();
        //checking the passed Country value from previous activity and set it to text
        if (savedInstanceState == null) {
            Bundle extras = getIntent().getExtras();
            if(extras == null)
            {
                cityKeyVar= null;
                countryKeyVar=null;
            }
            else
            {
                cityKeyVar= extras.getString("City");
                textView.setText(cityKeyVar);
                countryKeyVar=extras.getString("Country");
            
            }
        }
        else
        {
            cityKeyVar= (String) savedInstanceState.getSerializable("City");
        }
        
        //Passing the city to retrieve relevant weather information 
        api_key(cityKeyVar);
        //creating the firebase reference to retrieve relevant city information from its child value
        ref= FirebaseDatabase.getInstance().getReference().child("Country").child(countryKeyVar).child("OtherCities").child(cityKeyVar);
        //fire the start function
        this.Start();
        //setup a on click listener to airport to open Maps
        airport.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Uri gmmIntentUri = Uri.parse("geo:0,0?q='"+air+"'");
                Intent mapIntent = new Intent(Intent.ACTION_VIEW, gmmIntentUri);
                mapIntent.setPackage("com.google.android.apps.maps");
                startActivity(mapIntent);
            }
        });
    }
    public void Start() {

        //add the ValueListener to the selected reference and set it to the textViews
        ref.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                //Set firebase values into text views
                Map<String, Object> map = (Map<String, Object>) dataSnapshot.getValue();
                if(map.get("cityImg")!=null){
                    ctyImg = map.get("cityImg").toString();
                    Glide.with(getApplication()).load(ctyImg).override(600, 200).into(cityImg);
                }
                pop = dataSnapshot.child("population").getValue(String.class);
                population.setText(pop);
                air = dataSnapshot.child("nearestAirport").getValue(String.class);
                airport.setText(air);

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {
            }
        });
    }

    //Retrieve weather information from openweathermap service 
    private void api_key(final String City) {
        OkHttpClient client=new OkHttpClient();
        Request request=new Request.Builder()
                .url("https://api.openweathermap.org/data/2.5/weather?q="+City+"&appid=a6f41d947e0542a26580bcd5c3fb90ef&units=metric")
                .get()
                .build();
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
        try {
            Response response= client.newCall(request).execute();
            client.newCall(request).enqueue(new Callback() {
                @Override
                public void onFailure(@NotNull Call call, @NotNull IOException e) {}
                @Override
                public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                    String responseData= response.body().string();
                    try {
                        JSONObject json=new JSONObject(responseData);
                        JSONArray array=json.getJSONArray("weather");
                        JSONObject object=array.getJSONObject(0);
                        String description=object.getString("description");
                        String icons = object.getString("icon");
                        JSONObject temp1= json.getJSONObject("main");
                        Double Temperature=temp1.getDouble("temp");
                        setText(view_city,City);
                        String temps=Math.round(Temperature)+" °C";
                        setText(view_temp,temps);
                        setText(view_desc,description);
                        setImage(view_weather,icons);

                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
            });
        }catch (IOException e){
            e.printStackTrace();
        }
    }
    private void setText(final TextView text, final String value){
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                text.setText(value);
            }
        });
    }
    private void setImage(final ImageView imageView, final String value){
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                //paste switch
                switch (value){
                    case "01d": imageView.setImageResource(R.drawable.d01d);
                        break;
                    case "01n": imageView.setImageResource(R.drawable.d01d);
                        break;
                    case "02d": imageView.setImageResource(R.drawable.d02d);
                        break;
                    case "02n": imageView.setImageResource(R.drawable.d02d);
                        break;
                    case "03d": imageView.setImageResource(R.drawable.d03d);
                        break;
                    case "03n": imageView.setImageResource(R.drawable.d03d);
                        break;
                    case "04d": imageView.setImageResource(R.drawable.d04d);
                        break;
                    case "04n": imageView.setImageResource(R.drawable.d04d);
                        break;
                    case "09d": imageView.setImageResource(R.drawable.d09d);
                        break;
                    case "09n": imageView.setImageResource(R.drawable.d09d);
                        break;
                    case "10d": imageView.setImageResource(R.drawable.d10d);
                        break;
                    case "10n": imageView.setImageResource(R.drawable.d10d);
                        break;
                    case "11d": imageView.setImageResource(R.drawable.d11d);
                        break;
                    case "11n": imageView.setImageResource(R.drawable.d11d);
                        break;
                    case "13d": imageView.setImageResource(R.drawable.d13d);
                        break;
                    case "13n": imageView.setImageResource(R.drawable.d13d);
                        break;
                    default:
                        imageView.setImageResource(R.drawable.wheather);
                }
            }
        });
    }
    public void BackDashboard(View view)
    {Intent intent = new Intent(this, Dashboard.class);startActivity(intent);}
    public void Backcountry(View view)
    {Intent intent = new Intent(this, Country.class);startActivity(intent);}

    @Override
    public boolean onNavigationItemSelected(@NonNull final MenuItem item) {
        navigationView.postDelayed(new Runnable() {
            @Override
            public void run() {
                int itemId = item.getItemId();
                if (itemId == R.id.action_home) {
                    City.this.startActivity(new Intent(City.this, Dashboard.class));
                } else if (itemId == R.id.action_profile) {
                    City.this.startActivity(new Intent(City.this, ProfielActivity.class));
                } else if (itemId == R.id.action_favorite) {
                    City.this.startActivity(new Intent(City.this, favourits.class));
                }
                City.this.finish();
            }
        }, 300);
        return true;
    }
}
