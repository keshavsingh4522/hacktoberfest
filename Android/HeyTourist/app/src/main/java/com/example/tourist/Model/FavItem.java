package com.example.tourist.Model;

public class FavItem {
    private String id;
    private String countryName;
    private String countryImg;
    private  String user;
    private String fStatus;

    public FavItem(String id, String countryName, String countryImg,String user, String fStatus) {
        this.id = id;
        this.countryName = countryName;
        this.countryImg = countryImg;
        this.user = user;
        this.fStatus = fStatus;
    }

    public String getId() {return id;}
    public void setId(String id) {this.id = id;}
    public String getCountryName() {return countryName;}
    public void setCountryName(String countryName) {this.countryName = countryName;}
    public String getCountryImg() {return countryImg;}
    public void setCountryImg(String countryImg) {this.countryImg = countryImg;}
    public String getUser() {return user;}
    public void setUser(String user) { this.user = user;}
    public String getfStatus() {return fStatus;}
    public void setfStatus(String fStatus) {this.fStatus = fStatus;}
}
