package agecounter;

import java.util.Scanner;
import java.time.LocalDate;
import java.time.Period;

public class AgeCounter {

    public static void main(String[] args) {
        
        Scanner bday=new Scanner(System.in);
        
        //Get Inputs
        System.out.println("Enter your Birth Year");
        int year=bday.nextInt();
      
        System.out.println("Enter your Birth Month");
        int month=bday.nextInt();
        
        System.out.println("Enter your Birth Date");
        int day=bday.nextInt();
        
        
        
        LocalDate pres = LocalDate.now();
        LocalDate bdate = LocalDate.of(year,month,day);
        
        int age = Period.between(bdate , pres).getYears();
        
        System.out.println(pres);
        System.out.println(bdate);
        System.out.println(age);
    }
    
}
