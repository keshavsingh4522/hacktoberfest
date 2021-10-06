package com.example.tourist;

import android.content.Context;
import android.content.SharedPreferences;

import com.example.tourist.Model.Users;

public class SessionManagement {
    SharedPreferences sharedPreferences;
    SharedPreferences.Editor editor;
    String SHARED_PREF_NAME = "session";
    String SESSION_KEY = "session_user";

    public SessionManagement(Context context){
        sharedPreferences = context.getSharedPreferences(SHARED_PREF_NAME,Context.MODE_PRIVATE);
        editor = sharedPreferences.edit();
    }

    public void saveSession(Users user){
        //save session of user whenever user is logged in
        String id = user.getPhone();
        editor.putString(SESSION_KEY,id).commit();
    }

    public String getSession(){
        //return user id whose session is saved
        return sharedPreferences.getString(SESSION_KEY,null);
    }

    public void removeSession(){
        editor.putString(SESSION_KEY,null).commit();
    }
}
