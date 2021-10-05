package android.example.mirwok;

import android.app.Activity;
import android.content.Context;
import android.media.Image;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;

import java.util.ArrayList;
import java.util.List;

public class wordAdapter extends ArrayAdapter<word> {
    int mResourceColor;
    public wordAdapter(@NonNull Context context, int resource, @NonNull List<word> objects, int color) {
        super(context, resource, objects);
        mResourceColor = color;

    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        View listItemView = convertView;
        if(listItemView == null) {
            listItemView = LayoutInflater.from(getContext()).inflate(R.layout.list_view, parent, false);
        }

        View textContainer = listItemView.findViewById(R.id.text_container);
        int color = ContextCompat.getColor(getContext(),mResourceColor);
        textContainer.setBackgroundColor(color);

        // Get the {@link AndroidFlavor} object located at this position in the list
        word currentWord = getItem(position);

        // Find the TextView in the list_item.xml layout with the ID version_name
        TextView miwokTextView = (TextView) listItemView.findViewById(R.id.miwok_text_view);
        // set this text on the name TextView
        miwokTextView.setText(currentWord.getmMiwokTranslation());

        // Find the TextView in the list_item.xml layout with the ID version_number
        TextView EnglishTextView = (TextView) listItemView.findViewById(R.id.English_text_view);
        // Get the version number from the current AndroidFlavor object and
        // set this text on the number TextView
        EnglishTextView.setText(currentWord.getmDefaultTranslation());

        ImageView image = (ImageView) listItemView.findViewById(R.id.image);

        image.setImageResource(currentWord.getmResourceID());

        if (currentWord.getmResourceID() != 0){
            image.setVisibility(View.VISIBLE);
        }
        else{
            image.setVisibility(View.GONE);
        }


        // Return the whole list item layout (containing 2 TextViews)
        // so that it can be shown in the ListView
        return listItemView;
    }
}
