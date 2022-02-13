/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;

import java.util.HashMap;

/**
 *
 * @author MY-PC
 */
public class DbPlaces {
    
    
    public String getNames (String place){
        HashMap hash = new HashMap();
        
        hash.put("Angeles","ANG");
        hash.put("Balagtas","BAL");
        hash.put("Balintawak","BWK");
        hash.put("Bocaue","BOC");
        hash.put("Clark North ","NCLARK");
        hash.put("Clark South","SCLARK");
        hash.put("Concepcion","CONC");
        hash.put("Dau","DAU");
        hash.put("Dinalupihan","DIN");
        hash.put("Dolores","DOL");
        hash.put("Floridablanca","FLOR");
        hash.put("Karuhatan Link","KAR");
        hash.put("Mabalacat (Mabiga)","MAB");
        hash.put("Marilao","MAR");
        hash.put("Mexico","MXC");
        hash.put("Meycauayan","MEY");
        hash.put("Mindanao Avenue","MIN");
        hash.put("Porac","PRC");
        hash.put("Pulilan","PUL");
        hash.put("San Fernando","SNF");
        hash.put("San Miguel","SMG");
        hash.put("San Simon","SNM");
        hash.put("Sta. Ines","INES");
        hash.put("Sta. Rita ","STR");
        hash.put("Tabang","TAB");
        hash.put("Tarlac","TAR");
        hash.put("TIPO/SFEX","TIPO");
        hash.put("Valenzuela","VAL");


        
        
        return hash.get(place).toString();
    }
}
