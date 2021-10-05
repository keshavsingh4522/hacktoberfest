package android.example.mirwok;

public class word {
    private String mMiwokTranslation;
    private String mDefaultTranslation;
    private int mResourceID;
    private int mAudioResourceID;
    public word(String defaultTranslation, String miwokTranslation, int AudioResourceID){
        mDefaultTranslation = defaultTranslation;
        mMiwokTranslation = miwokTranslation;
        mAudioResourceID = AudioResourceID;
    }
    public word(String defaultTranslation, String miwokTranslation, int resourceID,int AudioResourceID){
        mDefaultTranslation = defaultTranslation;
        mMiwokTranslation = miwokTranslation;
        mResourceID = resourceID;
        mAudioResourceID = AudioResourceID;
    }
    public int getmResourceID(){
        return mResourceID;
    }
    public int getmAudioResourceID(){
        return mAudioResourceID;
    }
    public String getmDefaultTranslation() {
        return mDefaultTranslation;
    }
    public String getmMiwokTranslation(){
        return mMiwokTranslation;
    }
}
