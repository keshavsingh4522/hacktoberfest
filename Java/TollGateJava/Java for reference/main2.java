
import java.util.Scanner;

public class main2 {

    public static void main(String[] args) {
 Scanner a= new Scanner(System.in);
        Scanner b= new Scanner(System.in);
        
        boolean bool=true;
do{
System.out.println("1:Vehicle\n2:Buses\n3:Heavy Goods Vehicle"); 

System.out.println("Name                    Enitials");
System.out.println("Mindanao Avenue         MIN\n" +"Valenzuela              VAL\n" +"Meycauyan               MEY\n" +
"Marilao                 MAR\n" +"Bocaue                  BOC\n" +"Balagtas                BAL\n" +"Tabang                  TAB\n" +"Sta.Rita                STR\n" +
"Pulilan                 PUL\n" +"San Simon               SNM\n" +"San Fernando            SNF\n" +"Mexico                  MXC\n" +"Angeles                 ANG\n" +
"Dau                     DAU\n" +"Sta.Ines                INES\n" +"Tipo/Sfex               TIPO\n" +"Dinalupihan             DIN\n" +"Floridablanca           FLOR\n" +
"porac                   PRC\n" +"Clark South             SCLARK\n" +"Mabalacat(Mabiga)       MAB\n" +"Clark North             NCLARK\n" +"Dolores                 DOL\n" +
"Concepcion              CONC\n" +"San Miguel              SMG\n" +"Tarlac                  TAR\n" );
System.out.println("Enter vehicle type: ");
int vehicle= a.nextInt();
System.out.println("Entry Point: ");
String en=b.nextLine().toLowerCase();
System.out.println("Exit Point: ");
String ex=b.nextLine().toLowerCase();

if(vehicle==1){
class1(en,ex);
}
    
if(vehicle==2){
    
        }
}while(bool);
    }
public static void class1(String enter,String exit){
if(enter.equals("mindanao avenue")&& exit.equals("bwk") || 
   enter.equals("valenzuela")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||
   enter.equals("meycuayan")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||
   enter.equals("marilao")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")|| exit.equals("mey")){
   System.out.println("Payment is P136.00");
                }
else if(enter.equals("bocaue")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar")){
    System.out.println("Payment is P166.00");
}
else if(enter.equals("balagtas")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar")){
    System.out.println("Payment is P84.00");
    if(enter.equals("balagtas")&& exit.equals("boc")){
        System.out.println("Payment is P18.00");
}
else if(enter.equals("tabang")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar")){
    System.out.println("Payment is P96.00");
    if(enter.equals("tabang")&& exit.equals("boc"))
{System.out.println("Payment is P30.00");
}}
else if(enter.equals("sta. rita")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P101.00");
    if(enter.equals("sta. rita")&& exit.equals("boc"))
{System.out.println("Payment is P34.00");
}
   
}
else if(enter.equals("pulilan")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P122.00");
    if(enter.equals("pulilan")&& exit.equals("boc"))
{System.out.println("Payment is P55.00");
}
    else if(enter.equals("pulilan")&& exit.equals("str"))
{System.out.println("Payment is P21.00");
}  
}
else if(enter.equals("san simon")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P159.00");
     if(enter.equals("san simon")&& exit.equals("boc"))
{System.out.println("Payment is P92.00");
} 
     else if(enter.equals("san simon")&& exit.equals("str"))
{System.out.println("Payment is P58.00");
} 
     else if(enter.equals("san simon")&& exit.equals("pul"))
{System.out.println("Payment is P37.00");
} 
}
else if(enter.equals("san fernando")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P187.00");
     if(enter.equals("san fernando")&& exit.equals("boc"))
{System.out.println("Payment is P120.00");
} 
     else if(enter.equals("san fernando")&& exit.equals("str"))
{System.out.println("Payment is P86.00");
} 
     else if(enter.equals("san fernando")&& exit.equals("pul"))
{System.out.println("Payment is P65.00");
} 
     else if (enter.equals("san fernando")&&exit.equals("snm")){
     System.out.println("Payment is P28.00");}
}
    
else if(enter.equals("mexico")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P209.00");
       if(enter.equals("mexico")&& exit.equals("boc"))
{System.out.println("Payment is P142.00");
} 
     else if(enter.equals("mexico")&& exit.equals("str"))
{System.out.println("Payment is P108.00");
} 
     else if(enter.equals("mexico")&& exit.equals("pul"))
{System.out.println("Payment is P87.00");
} 
     else if (enter.equals("mexico")&&exit.equals("snm")){
     System.out.println("Payment is P50.00");}
     else if(enter.equals("mexico")&&exit.equals("snf")){
     System.out.println("Payment is P22.00");}
}
    
else if(enter.equals("angeles")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P235.00");
       if(enter.equals("angeles")&& exit.equals("boc"))
{System.out.println("Payment is P169.00");
} 
     else if(enter.equals("angeles")&& exit.equals("str"))
{System.out.println("Payment is P135.00");
} 
     else if(enter.equals("angeles")&& exit.equals("pul"))
{System.out.println("Payment is P113.00");
} 
     else if (enter.equals("angeles")&&exit.equals("snm")){
     System.out.println("Payment is P77.00");}
     else if(enter.equals("angeles")&&exit.equals("snf")){
     System.out.println("Payment is P49.00");}
     else if(enter.equals("angeles")&&exit.equals("mxc")){
     System.out.println("Payment is P27.00");}
}
    
else if(enter.equals("dau")&& exit.equals("bwk")||exit.equals("min")||exit.equals("kar")||exit.equals("val")||exit.equals("mey")||exit.equals("mar"))
{System.out.println("Payment is P242.00");
        if(enter.equals("dau")&& exit.equals("boc"))
{System.out.println("Payment is P175.00");
} 
     else if(enter.equals("dau")&& exit.equals("str"))
{System.out.println("Payment is P141.00");
} 
     else if(enter.equals("dau")&& exit.equals("pul"))
{System.out.println("Payment is P120.00");
} 
     else if (enter.equals("dau")&&exit.equals("snm")){
     System.out.println("Payment is P83.00");}
     else if(enter.equals("dau")&&exit.equals("snf")){
     System.out.println("Payment is P55.00");}
     else if(enter.equals("dau")&&exit.equals("mxc")){
     System.out.println("Payment is P33.00");}
     else if(enter.equals("dau")&&exit.equals("ang")){
     System.out.println("Payment is P6.00");}
}
}

    }

}
