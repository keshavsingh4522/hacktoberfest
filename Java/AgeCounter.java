package agecounter;

import java.util.Scanner;
import java.time.LocalDate;
import java.time.Period;

public class AgeCounter {

    public static void main(String[] args) {
        
        Scanner bday=new Scanner(System.in);
        
        //Get Inputs
        System.out.println("Enter Your Birth Year");
        int year=bday.nextInt();
      
        System.out.println("Enter Your Birth Month");
        int month=bday.nextInt();
        
        System.out.println("Enter Your Birth Date");
        int day=bday.nextInt();
        
        
        //analyses todays Date and your birthDate
        LocalDate pres = LocalDate.now();
        LocalDate bdate = LocalDate.of(year,month,day);
        
        //function to get the present age
        int age = Period.between(bdate , pres).getYears();
        
        //Prints present, birthDate, Present Age
        System.out.println(pres);
        System.out.println(bdate);
        System.out.println(age);
    }
    
}
