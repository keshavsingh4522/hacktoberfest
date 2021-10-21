import java.util.*;
import java.lang.*;
class gym1
{
 double height,weight,option;
 String gender,contact,a,month,amount,name,name2,name3,address;
 Scanner s=new Scanner(System.in);
}
class gym2 extends gym1
{
	 public void get()
 {
  System.out.println("\n\t\t\t\tJOKER'S GYM");
  System.out.println("\n\t\t*********************************************");
  System.out.println("\n\t\t\tPress 1 for Gym Info");
  System.out.println("\n\t\t\tPress 2 for Registration");
  System.out.println("\n\t\t\tPress 3 for Attendance Portal");
  System.out.println("\n\t\t\tPress 4 for Fee Portal");
  System.out.println("\n\t\t\tPress 5 for View Gym data");
  System.out.println("\n\t\t\tPress 6 for Exercise Schedule");
  System.out.println("\n\t\t\tPress 7 for Calculate your BMI");
  System.out.println("\n\t\t\tPress 8 for Exit\n\n\n\n\n\n\t\t\t");
 }
 
	public void get1()
	{
	int input1;
   input1=s.nextInt();  	
    switch(input1)
    {
	    case 1:
        System.out.println("\n\tJOKER'S GYM");
       	System.out.println("\n******************************");
		System.out.println("\nGYM RATINGS : 8/10");
		System.out.println("\nGYM INFRASTRUCTURE : 7/10");
		System.out.println("\nGYM STAFF ATTITUDE : 9/10");
        System.out.println("\nPUBLIC RATINGS : 9/10");
		System.out.println("\nGYM ADDRESSS : 703A,Holy Cross Apt,FY rd. ,Andheri-[E],MUM-59");
		System.out.println("\nCONTACT : 9769557266");
		System.out.println("\nEMAIL : joker73@gmail.com");
		System.out.println("\n\n\t\t\t\tPress Any Key to return to Main Screen");
		get();
		get1();
		break;
	    case 2:
	    System.out.println("\n\tREGISTER NEW USER :\n");
		System.out.println("************************************\n");
		System.out.println("\nENTER NAME :");
		name=s.next();
		System.out.println("\nGENDER (M / F) :");
		gender=s.next();
		System.out.println("\nCONTACT :");
		contact=s.next();
		System.out.println("\nADDRESS :");
		address=s.next();
		System.out.println("\n\n\t\t\t\tPress Any Key to return to Main Screen");
		get();
		get1();
	    case 3:
        System.out.println("\n\tATTENDANCE FOR TODAY :");	
        System.out.println("\n**************************************\n");
		System.out.println("NAME OF TRAINEE :");
		name2=s.next();
		System.out.println("\n\n"+name2+" has marked attendance successfully !!");
		System.out.println("\n\t\t\t\tPress Any Key to return to Main Screen");
		get();
		get1();
	    case 4:
	    System.out.println("\n\tFEE PORTAL");
		System.out.println("\n****************************\n");
		System.out.println("PRESS 1 TO SUBMIT FEE :");
		System.out.println("\nPRESS 2 TO VIEW PENDING FEE :\n\n");
		option=s.nextInt();
		if(option==1)
		{
			System.out.println("\nNAME OF TRAINEE :");
			name3=s.next();
			System.out.println("\nFEE OF MONTH :");
			month=s.next();
			System.out.println("\nAMOUNT :");
			amount=s.next();
			System.out.println("\n\n**********PAYMENT SUCCESSFUL !! ***********:");
		}
		else
		{
			System.out.println("\n\tAll Trainees have done their payments !!");
		
		}
		System.out.println("\n\t\t\t\tPress Any Key to return to Main Screen");
		get();
		get1();
	    case 5:
	    System.out.println("\n\tGYM DATA ");
		System.out.println("\n****************************\n");
		System.out.println("NAME OF TRAINEE :" +name);
		System.out.println("\nGENDER :" +gender);
		System.out.println("\nCONTACT :" +contact);
		System.out.println("\nADDRESS :" +address);
		System.out.println("\n\t\t\t\tPress Any Key to return to Main Screen");
		get();
		get1();
	    case 6:
	    System.out.println("\n\tEXERCISE SCHEDULE \n");
		System.out.println("***********************************\n");
		System.out.println("MONDAY : CHEST");
		System.out.println("\nTUESDAY : BICEPS");
		System.out.println("\nWEDNESDAY : TRICEPS");
		System.out.println("\nTHRUSDAY : BACK");
		System.out.println("\nFRIDAY : LEGS");
		System.out.println("\nSATURDAY : SHOULDER");
		System.out.println("\n\n\t\tPress Any Key to return to Main Screen");
		get();
		get1();	
	    case 7:
	    double bmi;
		System.out.println("\n\tBMI CALCULATOR");
		System.out.println("\n************************************\n");
		System.out.println("ENTER YOUR HEIGHT [in CM] =");
		height=s.nextDouble();
		System.out.println("\nENTER YOUR WEIGHT [in KG] =");
		weight=s.nextDouble();
		bmi=weight/((height/100)*(height/100));
		System.out.println("\n\nyour BODY MASS INDEX is = "+bmi);
		if(bmi<=18.5)
		{
			System.out.println("\n******YOU ARE THIN******");
		}
		else if( bmi>=18.6 && bmi<=24.9 )
		{
			System.out.println("\n******YOU ARE HEALTHY******");
		}
		else if(bmi==25 && bmi>=29.9)
		{
			System.out.println("\n******YOU ARE OVER WEIGHT******");
		}
		else
		{
			System.out.println("\n******YOU ARE OBESED******");
		}
		System.out.println("\n\n\n\t\t\t\tPress Any Key to return to Main Screen");
		get();
		get1();
        case 8:
	    System.out.println("\n\n\t\t\t***THANK YOU***");
		System.exit(0);
	    default :
        System.out.println("\n\t\tPlease press key from 1 - 7");	
        }

	}
}

class javaproject
{
  public static void main(String args[])
{
  gym2 g = new gym2();
  g.get();
  g.get1();
}
} 




 