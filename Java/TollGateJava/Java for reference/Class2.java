
import java.util.HashMap;
public class Class2 {
     public boolean GET(String entry , String exit) {
         String EnEx= entry+"-"+exit;
         String ExEn00= exit+"-"+entry;
         
        
HashMap hash = new HashMap();
hash.put("MIN-BWK",136);
//VAL
hash.put("VAL-BWK",136);
hash.put("VAL-MIN",136);
hash.put("VAL-KAR",136);

//MEYCA
hash.put("MEY-BWK",136);
hash.put("MEY-MIN",136);
hash.put("MEY-KAR",136);
hash.put("MEY-VAL",136);
//MAR
hash.put("MAR-BWK",136);
hash.put("MAR-MIN",136);
hash.put("MAR-KAR",136);
hash.put("MAR-VAL",136);
hash.put("MAR-MEY",136);
//BOC
hash.put("BOC-BWK",166);
hash.put("BOC-MIN",166);
hash.put("BOC-KAR",166);
hash.put("BOC-VAL",166);
hash.put("BOC-MEY",166);
hash.put("BOC-MAR",166);
//BAL
hash.put("BAL-BWK",210);
hash.put("BAL-MIN",210);
hash.put("BAL-KAR",210);
hash.put("BAL-VAL",210);
hash.put("BAL-MEY",210);
hash.put("BAL-MAR",210);
hash.put("BAL-BOC",44);

//TABANG
hash.put("TAB-BWK",240);
hash.put("TAB-MIN",240);
hash.put("TAB-KAR",240);
hash.put("TAB-VAL",240);
hash.put("TAB-MEY",240);
hash.put("TAB-MAR",240);
hash.put("TAB-BOC",74);

//STA-RITA
hash.put("RITA-BWK",251);
hash.put("RITA-MIN",251);
hash.put("RITA-KAR",251);
hash.put("RITA-VAL",251);
hash.put("RITA-MEY",251);
hash.put("RITA-MAR",251);
hash.put("RITA-BOC",85);

//PULILAN
hash.put("PUL-BWK",304);
hash.put("PUL-MIN",304);
hash.put("PUL-KAR",304);
hash.put("PUL-VAL",304);
hash.put("PUL-MEY",304);
hash.put("PUL-MAR",304);
hash.put("PUL-BOC",138);
hash.put("PUL-STR",54);



if (hash.containsKey(EnEx)){
    System.out.println(hash.get(EnEx));
    return true;
}
else if (hash.containsKey(ExEn00)){
    System.out.println(hash.get(ExEn00));
   return false;
}
else{
    System.out.println("NOT BELONG TO THE REQUIREMENT");
    return true;
}


         
    }



}
