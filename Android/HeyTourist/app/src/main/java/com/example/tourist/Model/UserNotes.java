package com.example.tourist.Model;

public class UserNotes {
    private String UserNote;

    public UserNotes(){
        //
    }

    public UserNotes(String userNote){

        UserNote = userNote;

    }

    public String getUserNote() {
        return UserNote;
    }

    public void setUserNote(String userNote) {
        UserNote = userNote;
    }
}
