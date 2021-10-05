package android.example.mirwok;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;
import androidx.viewpager2.adapter.FragmentStateAdapter;
import androidx.viewpager2.widget.ViewPager2;

public class ViewPagerAdapter extends FragmentPagerAdapter {
    private static final int NUM_PAGES = 4;

    public ViewPagerAdapter(@NonNull FragmentManager fm) {
        super(fm);
    }


    @NonNull
    @Override
    public Fragment getItem(int position) {
        if (position == 0){
            return new number_fragment();
        }
        if (position == 1){
            return new color_fragment();
        }
        if (position == 2){
            return new family_fragment();
        }
        else{
            return new phrases_fragment();
        }
    }


    @Override
    public int getCount() {
        return NUM_PAGES;
    }
}
