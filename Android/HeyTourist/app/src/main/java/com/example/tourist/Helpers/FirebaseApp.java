package com.example.tourist.Helpers;

import android.app.Application;

import com.google.firebase.database.FirebaseDatabase;

public class FirebaseApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();

        //enable offline data on firebase database
        FirebaseDatabase.getInstance().setPersistenceEnabled(true);
    }
}
