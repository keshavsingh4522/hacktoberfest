package com.example.tourist.Adapters;

import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Handler;
import android.os.Looper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;
import com.bumptech.glide.request.RequestOptions;
import com.example.tourist.Helpers.FavDB;
import com.example.tourist.Model.Tourist;
import com.example.tourist.R;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.MutableData;
import com.google.firebase.database.Transaction;

import java.util.ArrayList;
import java.util.Objects;

public class AdapterClass extends RecyclerView.Adapter<AdapterClass.MyViewHolder> {

    private ArrayList<Tourist> list;
    private ArrayList<String> names;
    private Context context;
    private FavDB favDB;
    private RecyclerViewClickListener mListener;
    private String Username;

    public AdapterClass(ArrayList<String> names, Context context, ArrayList<Tourist> list, RecyclerViewClickListener listener, String username) {
        this.names = names;
        this.list = list;
        this.mListener = listener;
        this.context = context;
        Username = username;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        favDB = new FavDB(context);
        //create table on first
        SharedPreferences prefs = context.getSharedPreferences("prefs", Context.MODE_PRIVATE);
        boolean firstStart = prefs.getBoolean("firstStart", true);
        if (firstStart) {
            createTableOnFirstStart();
        }
        Context context = parent.getContext();
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.card_holder, parent, false);
        return new MyViewHolder(view, mListener);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, final int position) {
        final Tourist tourist = list.get(position);
        readCursorData(tourist, holder);
        holder.countryName.setText(names.get(position));
        holder.desc.setText(list.get(position).getCapitalCity());
        Glide.with(context).load(list.get(position).getCountryImg()).apply(new RequestOptions().override(1024, 720)).into(holder.countryImg);
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public class MyViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        public TextView countryName, desc,likeCountTextView;
        public ImageView countryImg;
        private RecyclerViewClickListener mListener;
        Button favBtn;

        public MyViewHolder(@NonNull View itemView, RecyclerViewClickListener listener)  {
            super(itemView);
            mListener = listener;
            itemView.setOnClickListener(this);
            favBtn = itemView.findViewById(R.id.favBtn);
            likeCountTextView = itemView.findViewById(R.id.likeCountTextView);

            countryImg = (ImageView) itemView.findViewById(R.id.countryImg);
            countryName = (TextView) itemView.findViewById(R.id.countryName);
            desc = (TextView) itemView.findViewById(R.id.desciption);
            //add to fav btn
            favBtn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    int position = getAdapterPosition();
                    Tourist tourist = list.get(position);
                    likeClick(tourist, favBtn, likeCountTextView);
                }
            });
        }

        @Override
        public void onClick(View v) {
            mListener.onClick(v, getAdapterPosition());
        }
    }

    public interface RecyclerViewClickListener {
        void onClick(View view, int position);
    }

    private void createTableOnFirstStart() {
        favDB.insertEmpty();
        SharedPreferences prefs = context.getSharedPreferences("prefs", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = prefs.edit();
        editor.putBoolean("firstStart", false);
        editor.apply();
    }

    private void readCursorData(Tourist tourist, MyViewHolder viewHolder) {
        Cursor cursor = favDB.read_all_data(tourist.getId().toString());
        SQLiteDatabase db = favDB.getReadableDatabase();
        try {
            while (cursor.moveToNext()) {
                String item_fav_status = cursor.getString(cursor.getColumnIndex(FavDB.FAVORITE_STATUS));
                tourist.setFavStatus(item_fav_status);
                //check fav status
                if (item_fav_status != null && item_fav_status.equals("1")) {
                    viewHolder.favBtn.setBackgroundResource(R.drawable.ic_favorite_red_24dp);
                } else if (item_fav_status != null && item_fav_status.equals("0")) {
                    viewHolder.favBtn.setBackgroundResource(R.drawable.ic_favorite_shadow_24dp);
                }
            }
        } finally {
            if (cursor != null && cursor.isClosed())
                cursor.close();
            db.close();
        }
    }

    // like click
    private void likeClick(Tourist tourist, Button favBtn, final TextView textLike) {
        DatabaseReference refLike = FirebaseDatabase.getInstance().getReference().child("Favourits");
        final DatabaseReference upvotesRefLike = refLike.child(tourist.getCountryName());

        if (tourist.getFavStatus().equals("0")) {

            tourist.setFavStatus("1");

            favDB.insertIntoTheDatabase(tourist.getId().toString(),tourist.getCountryName(), tourist.getCountryImg(),Username,tourist.getFavStatus());
            favBtn.setBackgroundResource(R.drawable.ic_favorite_red_24dp);
            favBtn.setSelected(true);

            upvotesRefLike.runTransaction(new Transaction.Handler() {
                @NonNull
                @Override
                public Transaction.Result doTransaction(@NonNull final MutableData mutableData) {
                    try {
                        Integer currentValue = mutableData.getValue(Integer.class);
                        if (currentValue == null) {
                            mutableData.setValue(1);
                        } else {
                            mutableData.setValue(1);
                            new Handler(Looper.getMainLooper()).post(new Runnable() {
                                @Override
                                public void run() {
                                    textLike.setText(Objects.requireNonNull(mutableData.getValue()).toString());
                                }
                            });
                        }
                    } catch (Exception e) {
                        throw e;
                    }
                    return Transaction.success(mutableData);
                }
                @Override
                public void onComplete(@Nullable DatabaseError databaseError, boolean b, @Nullable DataSnapshot dataSnapshot) {
                    System.out.println("Transaction completed");
                }
            });

        } else if (tourist.getFavStatus().equals("1")) {
            tourist.setFavStatus("0");
            favDB.remove_fav(tourist.getId().toString());
            favBtn.setBackgroundResource(R.drawable.ic_favorite_shadow_24dp);
            favBtn.setSelected(false);

            upvotesRefLike.runTransaction(new Transaction.Handler() {
                @NonNull
                @Override
                public Transaction.Result doTransaction(@NonNull final MutableData mutableData) {
                    try {
                        Integer currentValue = mutableData.getValue(Integer.class);
                        if (currentValue == null) {
                            mutableData.setValue(1);
                        } else {
                            mutableData.setValue(0);
                            new Handler(Looper.getMainLooper()).post(new Runnable() {
                                @Override
                                public void run() {
                                    textLike.setText(Objects.requireNonNull(mutableData.getValue()).toString());
                                }
                            });
                        }
                    } catch (Exception e) {
                        throw e;
                    }
                    return Transaction.success(mutableData);
                }

                @Override
                public void onComplete(@Nullable DatabaseError databaseError, boolean b, @Nullable DataSnapshot dataSnapshot) {
                    System.out.println("Transaction completed");
                }
            });
        }
    }
}
