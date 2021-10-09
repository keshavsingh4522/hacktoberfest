
import java.util.HashMap;
public class class1{
     public boolean GET(String entry , String exit) {
         String EnEx= entry+"-"+exit;
         String ExEn00= exit+"-"+entry;
         
        
HashMap hash = new HashMap();
hash.put("MIN-BWK",54);
//VAL
hash.put("VAL-BWK",54);
hash.put("VAL-MIN",54);
hash.put("VAL-KAR",54);

//MEYCA
hash.put("MEY-BWK",54);
hash.put("MEY-MIN",54);
hash.put("MEY-KAR",54);
hash.put("MEY-VAL",54);
//MAR
hash.put("MAR-BWK",54);
hash.put("MAR-MIN",54);
hash.put("MAR-KAR",54);
hash.put("MAR-VAL",54);
hash.put("MAR-MEY",54);
//BOC
hash.put("BOC-BWK",66);
hash.put("BOC-MIN",66);
hash.put("BOC-KAR",66);
hash.put("BOC-VAL",66);
hash.put("BOC-MEY",66);
hash.put("BOC-MAR",66);
//BAL
hash.put("BAL-BWK",83);
hash.put("BAL-MIN",83);
hash.put("BAL-KAR",83);
hash.put("BAL-VAL",83);
hash.put("BAL-MEY",83);
hash.put("BAL-MAR",83);
hash.put("BAL-BOC",18);

//TABANG
hash.put("TAB-BWK",95);
hash.put("TAB-MIN",95);
hash.put("TAB-KAR",95);
hash.put("TAB-VAL",95);
hash.put("TAB-MEY",95);
hash.put("TAB-MAR",95);
hash.put("TAB-BOC",30);

//STA-RITA
hash.put("RITA-BWK",100);
hash.put("RITA-MIN",100);
hash.put("RITA-KAR",100);
hash.put("RITA-VAL",100);
hash.put("RITA-MEY",100);
hash.put("RITA-MAR",100);
hash.put("RITA-BOC",34);

//PULILAN
hash.put("PUL-BWK",121);
hash.put("PUL-MIN",121);
hash.put("PUL-KAR",121);
hash.put("PUL-VAL",121);
hash.put("PUL-MEY",121);
hash.put("PUL-MAR",121);
hash.put("PUL-BOC",55);
hash.put("PUL-STR",21);

//SANSIMON
hash.put("SNM-BWK",158);
hash.put("SNM-MIN",158);
hash.put("SNM-KAR",158);
hash.put("SNM-VAL",158);
hash.put("SNM-MEY",158);
hash.put("SNM-MAR",158);
hash.put("SNM-BOC",92);
hash.put("SNM-STR",58);
hash.put("SNM-PUL",37);

//SANFERNANDO
hash.put("SNF-BWK",186);
hash.put("SNF-MIN",186);
hash.put("SNF-KAR",186);
hash.put("SNF-VAL",186);
hash.put("SNF-MEY",186);
hash.put("SNF-MAR",186);
hash.put("SNF-BOC",120);
hash.put("SNF-STR",86);
hash.put("SNF-PUL",65);
hash.put("SNF-SNM",28);

//MEXICO
hash.put("MXC-BWK",208);
hash.put("MXC-MIN",208);
hash.put("MXC-KAR",208);
hash.put("MXC-VAL",208);
hash.put("MXC-MEY",208);
hash.put("MXC-MAR",208);
hash.put("MXC-BOC",142);
hash.put("MXC-STR",108);
hash.put("MXC-PUL",87);
hash.put("MXC-SNM",50);
hash.put("MXC-SNF",22);

//ANGELES
hash.put("ANG-BWK",234);
hash.put("ANG-MIN",234);
hash.put("ANG-KAR",234);
hash.put("ANG-VAL",234);
hash.put("ANG-MEY",234);
hash.put("ANG-MAR",234);
hash.put("ANG-BOC",169);
hash.put("ANG-STR",135);
hash.put("ANG-PUL",113);
hash.put("ANG-SNM",77);
hash.put("ANG-SNF",49);
hash.put("ANG-MXC",27);

//DAU
hash.put("DAU-BWK",241);
hash.put("DAU-MIN",241);
hash.put("DAU-KAR",241);
hash.put("DAU-VAL",241);
hash.put("DAU-MEY",241);
hash.put("DAU-MAR",241);
hash.put("DAU-BOC",175);
hash.put("DAU-STR",141);
hash.put("DAU-PUL",120);
hash.put("DAU-SNM",83);
hash.put("DAU-SNF",55);
hash.put("DAU-MXC",33);
hash.put("DAU-ANG",6);

//STA.INES
hash.put("INES-BWK",257);
hash.put("INES-MIN",257);
hash.put("INES-KAR",257);
hash.put("INES-VAL",257);
hash.put("INES-MEY",257);
hash.put("INES-MAR",257);
hash.put("INES-BOC",192);
hash.put("INES-STR",158);
hash.put("INES-PUL",136);
hash.put("INES-SNM",100);
hash.put("INES-SNF",72);
hash.put("INES-MXC",50);
hash.put("INES-ANG",23);
hash.put("INES-DAU",17);

//TIPO.SFEX
hash.put("TIPO-BWK",484);
hash.put("TIPO-MIN",484);
hash.put("TIPO-KAR",484);
hash.put("TIPO-VAL",484);
hash.put("TIPO-MEY",484);
hash.put("TIPO-MAR",484);
hash.put("TIPO-BOC",419);
hash.put("TIPO-STR",385);
hash.put("TIPO-PUL",363);
hash.put("TIPO-SNM",327);
hash.put("TIPO-SNF",299);
hash.put("TIPO-MXC",277);
hash.put("TIPO-ANG",250);
hash.put("TIPO-DAU",244);
hash.put("TIPO-INES",27);



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
