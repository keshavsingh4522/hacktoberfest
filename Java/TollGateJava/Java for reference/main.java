import java.util.Scanner;
public class main {
    
    
    public static void main(String[] args) {
        Class2 class2= new Class2();
       
       
        Scanner a= new Scanner(System.in);
        Scanner b= new Scanner(System.in);
        
boolean move = true;       
while(move){
System.out.println("Enter vehicle type: ");

int vehicle= a.nextInt();
PrintVehicles();
System.out.println("Entry Point: ");
String en=b.nextLine().toUpperCase();



System.out.println("Exit Point: ");
String ex=b.nextLine().toUpperCase();
move= class2.GET(en, ex);





}
    
    
    }
static void PrintVehicles(){
System.out.println("Name                    Enitials");
System.out.println("Mindanao Avenue         MIN\n" +"Valenzuela              VAL\n" +"Meycauyan               MEY\n" +
"Marilao                 MAR\n" +"Bocaue                  BOC\n" +"Balagtas                BAL\n" +"Tabang                  TAB\n" +"Sta.Rita                STR\n" +
"Pulilan                 PUL\n" +"San Simon               SNM\n" +"San Fernando            SNF\n" +"Mexico                  MXC\n" +"Angeles                 ANG\n" +
"Dau                     DAU\n" +"Sta.Ines                INES\n" +"Tipo/Sfex               TIPO\n" +"Dinalupihan             DIN\n" +"Floridablanca           FLOR\n" +
"porac                   PRC\n" +"Clark South             SCLARK\n" +"Mabalacat(Mabiga)       MAB\n" +"Clark North             NCLARK\n" +"Dolores                 DOL\n" +
"Concepcion              CONC\n" +"San Miguel              SMG\n" +"Tarlac                  TAR\n" );

}
}