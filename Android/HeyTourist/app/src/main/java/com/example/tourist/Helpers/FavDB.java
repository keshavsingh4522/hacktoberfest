package com.example.tourist.Helpers;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class FavDB extends SQLiteOpenHelper {

    private static int DB_VERSION = 1;
    private static String DATABASE_NAME = "Favourite";
    private static String TABLE_NAME = "favoriteTable";
    public static String KEY_ID = "id";
    public static String COUNTRY_NAME = "countryName";
    public static String COUNTRY_IMAGE = "countryImg";
    public static String USER = "user";
    public static String FAVORITE_STATUS = "fStatus";
    // dont forget write this spaces
    private static String CREATE_TABLE = "CREATE TABLE " + TABLE_NAME + "("+ KEY_ID + " TEXT,"
            + COUNTRY_NAME + " TEXT,"+ COUNTRY_IMAGE +" TEXT," + USER+ " TEXT,"+ FAVORITE_STATUS+" TEXT)";

    public FavDB(Context context) { super(context,DATABASE_NAME,null,DB_VERSION);}

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(CREATE_TABLE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }
    // create empty table
    public void insertEmpty() {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues cv = new ContentValues();
        // enter your value
        for (int x = 1; x < 11; x++) {
            cv.put(KEY_ID, x);
            cv.put(FAVORITE_STATUS, "0");
            db.insert(TABLE_NAME,null, cv);
        }
    }
    // insert data into database
    public void insertIntoTheDatabase(String id,String CountryName, String CountryImg,String User,String fav_status) {
        SQLiteDatabase db;
        db = this.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put(KEY_ID,id);
        cv.put(COUNTRY_NAME, CountryName);
        cv.put(COUNTRY_IMAGE,CountryImg);
        cv.put(USER, User);
        cv.put(FAVORITE_STATUS, fav_status);
        db.insert(TABLE_NAME,null, cv);
        Log.d("FavDB Status", CountryName + ", favstatus - "+fav_status+" - . " + cv);
    }

    // read all data
    public Cursor read_all_data(String id) {
        SQLiteDatabase db = this.getReadableDatabase();
        String sql = "select * from " + TABLE_NAME + " where " + KEY_ID+"="+id+"";
        return db.rawQuery(sql,null,null);
    }

    // remove line from database
    public void remove_fav(String id) {
        SQLiteDatabase db = this.getWritableDatabase();
        String sql = "UPDATE " + TABLE_NAME + " SET  "+ FAVORITE_STATUS+" ='0' WHERE "+KEY_ID+"="+id+"";
        db.execSQL(sql);
        Log.d("remove", id.toString());

    }

    // select all favorite list

    public Cursor select_all_favorite_list() {
        SQLiteDatabase db = this.getReadableDatabase();
        String sql = "SELECT * FROM "+TABLE_NAME+" WHERE "+FAVORITE_STATUS+" ='1'";
        return db.rawQuery(sql,null,null);
    }





}
