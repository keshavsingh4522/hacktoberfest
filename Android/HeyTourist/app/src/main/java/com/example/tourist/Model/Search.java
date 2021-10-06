package com.example.tourist.Model;

public class Search {
    private String CountryName;

    public String getCountryName() {
        return CountryName;
    }

    public void setCountryName(String countryName) {
        CountryName = countryName;
    }

    public Search(String countryName) {
        CountryName = countryName;
    }
}
