 package android.example.mirwok;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Context;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;


 public class NumbersActivity extends AppCompatActivity{
     private ConstraintLayout rootView;

     private MediaPlayer mediaPlayer;

     private AudioManager mAudioManager;

     AudioManager.OnAudioFocusChangeListener mOnAudioFocusChangeListener = new AudioManager.OnAudioFocusChangeListener() {
         @Override
         public void onAudioFocusChange(int focusChange) {
             if (focusChange == AudioManager.AUDIOFOCUS_LOSS_TRANSIENT || focusChange == AudioManager.AUDIOFOCUS_LOSS_TRANSIENT_CAN_DUCK){
                 mediaPlayer.stop();
                 mediaPlayer.seekTo(0);
             } else if (focusChange == AudioManager.AUDIOFOCUS_GAIN || focusChange == AudioManager.AUDIOFOCUS_GAIN_TRANSIENT){
                 mediaPlayer.start();
             }else if (focusChange == AudioManager.AUDIOFOCUS_LOSS){
                 releaseMediaPlayer();
             }
         }
     };

     /**
      * This listener gets triggered when the {@link MediaPlayer} has completed
      * playing the audio file.
      */
     private final MediaPlayer.OnCompletionListener mCompletionListener = new MediaPlayer.OnCompletionListener() {
         @Override
         public void onCompletion(MediaPlayer mediaPlayer) {
             // Now that the sound file has finished playing, release the media player resources.
             releaseMediaPlayer();
         }
     };


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_numbers);

        mAudioManager = (AudioManager)getSystemService(Context.AUDIO_SERVICE);

        ArrayList<word> numbers = new ArrayList<word>();

        numbers.add(new word("One","lutti",R.drawable.number_one,R.raw.number_one));
        numbers.add(new word("Two","otiiko",R.drawable.number_two,R.raw.number_two));
        numbers.add(new word("Three","tolookosu",R.drawable.number_three,R.raw.number_three));
        numbers.add(new word("Four", "oyyisa",R.drawable.number_four,R.raw.number_four));
        numbers.add(new word("Five","massokka",R.drawable.number_five,R.raw.number_five));
        numbers.add(new word("Six","temmokka",R.drawable.number_six,R.raw.number_six));
        numbers.add(new word("Seven","kenekaku",R.drawable.number_seven,R.raw.number_seven));
        numbers.add(new word("Eight","kawinta",R.drawable.number_eight,R.raw.number_eight));
        numbers.add(new word("Nine","wo’e",R.drawable.number_nine,R.raw.number_nine));
        numbers.add(new word("Ten","na’aacha",R.drawable.number_ten,R.raw.number_ten));

        wordAdapter WordAdapter = new wordAdapter(this,R.layout.list_view,numbers,R.color.category_numbers);
        ListView listView = findViewById(R.id.list);
        listView.setAdapter(WordAdapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                word Words = numbers.get(position);
                releaseMediaPlayer();

                int result = mAudioManager.requestAudioFocus(mOnAudioFocusChangeListener, AudioManager.STREAM_MUSIC, AudioManager.AUDIOFOCUS_GAIN_TRANSIENT);

                if (result == AudioManager.AUDIOFOCUS_REQUEST_GRANTED){

                    mediaPlayer = MediaPlayer.create(NumbersActivity.this,Words.getmAudioResourceID());
                    mediaPlayer.start();
                    mediaPlayer.setOnCompletionListener(mCompletionListener);
                }
            }
        });
    }

     @Override
     protected void onStop() {
         super.onStop();
         releaseMediaPlayer();
     }

     /**
      * Clean up the media player by releasing its resources.
      */
     private void releaseMediaPlayer(){
         // If the media player is not null, then it may be currently playing a sound.
         if (mediaPlayer != null) {
             // Regardless of the current state of the media player, release its resources
             // because we no longer need it.
             mediaPlayer.release();

             // Set the media player back to null. For our code, we've decided that
             // setting the media player to null is an easy way to tell that the media player
             // is not configured to play an audio file at the moment.
             mediaPlayer = null;

             mAudioManager.abandonAudioFocus(mOnAudioFocusChangeListener);
         }
     }

}