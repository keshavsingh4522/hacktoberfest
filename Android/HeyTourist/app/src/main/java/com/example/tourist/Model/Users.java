package com.example.tourist.Model;

public class Users {
    private String Name;
    private String Password;
    private  String Email;
    private String Phone;

    public Users() {}
    public Users(String name, String password, String email,String phone) {
        Name = name;
        Password = password;
        Email = email;
        Phone=phone;
    }

    public String getName() {return Name;}
    public void setName(String name) {Name = name;}
    public String getPassword() {return Password; }
    public void setPassword(String password) {Password = password;}
    public String getEmail() {return Email;}
    public void setEmail(String email) {Email = email;}
    public String getPhone() {return Phone;}
    public void setPhone(String phone) {Phone = phone;}



}
