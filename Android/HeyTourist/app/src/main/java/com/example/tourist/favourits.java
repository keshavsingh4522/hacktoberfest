package com.example.tourist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.MenuItem;

import com.example.tourist.Adapters.FavAdapter;
import com.example.tourist.Helpers.FavDB;
import com.example.tourist.Model.FavItem;
import com.google.android.material.bottomnavigation.BottomNavigationView;

import java.util.ArrayList;
import java.util.List;

public class favourits extends AppCompatActivity implements BottomNavigationView.OnNavigationItemSelectedListener{
    protected BottomNavigationView navigationView;
    private RecyclerView recyclerView;
    private FavDB favDB;
    private List<FavItem> favItemList = new ArrayList<>();
    private FavAdapter favAdapter;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_favourits);
        navigationView = (BottomNavigationView) findViewById(R.id.navigation);
        navigationView.setOnNavigationItemSelectedListener(this);
        favDB = new FavDB(getApplication());
        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(new LinearLayoutManager(getApplication()));

        // add item touch helper
        ItemTouchHelper itemTouchHelper = new ItemTouchHelper(simpleCallback);
        itemTouchHelper.attachToRecyclerView(recyclerView); // set swipe to recyclerview
        loadData();

    }

    @Override
    public boolean onNavigationItemSelected(@NonNull final MenuItem item) {
        navigationView.postDelayed(new Runnable() {
            @Override
            public void run() {
                int itemId = item.getItemId();
                if (itemId == R.id.action_home) {
                    favourits.this.startActivity(new Intent(favourits.this, Dashboard.class));
                } else if (itemId == R.id.action_profile) {
                    favourits.this.startActivity(new Intent(favourits.this, ProfielActivity.class));
                } else if (itemId == R.id.action_favorite) {
                    favourits.this.startActivity(new Intent(favourits.this, favourits.class));
                }
                favourits.this.finish();
            }
        }, 300);
        return true;
    }

    private void loadData() {
        if (favItemList != null) {
            favItemList.clear();
        }
        SQLiteDatabase db = favDB.getReadableDatabase();
        Cursor cursor = favDB.select_all_favorite_list();
        try {
            while (cursor.moveToNext()) {

                String id = cursor.getString(cursor.getColumnIndex(FavDB.KEY_ID));
                String country = cursor.getString(cursor.getColumnIndex(FavDB.COUNTRY_NAME));
                String countyImg = cursor.getString(cursor.getColumnIndex(FavDB.COUNTRY_IMAGE));
                String user = cursor.getString(cursor.getColumnIndex(FavDB.USER));
                String status = cursor.getString(cursor.getColumnIndex(FavDB.FAVORITE_STATUS));
                FavItem favItem = new FavItem(id,country,countyImg, user, status);
                favItemList.add(favItem);
            }
        } finally {
            if (cursor != null && cursor.isClosed())
                cursor.close();
            db.close();
        }
        favAdapter = new FavAdapter(getApplication(), favItemList);
        recyclerView.setAdapter(favAdapter);

    }

    // remove item after swipe
    private ItemTouchHelper.SimpleCallback simpleCallback = new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT) {
        @Override
        public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
            return false;
        }

        @Override
        public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
            final int position = viewHolder.getAdapterPosition(); // get position which is swipe
            final FavItem favItem = favItemList.get(position);
            if (direction == ItemTouchHelper.LEFT) { //if swipe left
                favAdapter.notifyItemRemoved(position); // item removed from recyclerview
                favItemList.remove(position); //then remove item
                favDB.remove_fav(favItem.getId()); // remove item from database
            }
        }
    };
}
