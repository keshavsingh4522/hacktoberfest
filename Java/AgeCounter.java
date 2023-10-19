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
        while(year>2023 || year<0){
                    System.out.println("Enter Your Birth Year");
            year=bday.nextInt();
        }
      
        System.out.println("Enter Your Birth Month");
        int month=bday.nextInt();
        while(month>12 || month<0){
            System.out.println("Enter Your Birth Month");
            month=bday.nextInt();
        }
        
        System.out.println("Enter Your Birth Date");
        int day=bday.nextInt();
        while(day>31 || day<0){
            System.out.println("Enter Your Birth Date");
            day=bday.nextInt();
        }
        
        
        
        
        LocalDate pres = LocalDate.now();
        LocalDate bdate = LocalDate.of(year,month,day);
        
        int age = Period.between(bdate , pres).getYears();
        
        System.out.println(pres);
        System.out.println(bdate);
        System.out.println(age);
    }
    
}
