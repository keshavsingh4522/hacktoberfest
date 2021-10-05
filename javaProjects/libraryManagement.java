// Library Management System
// Ankit Raj Biswal (ankitrudra2001@gmail.com)
//Admin: ankitrudra (you can change it on line number 127)
//Password: ankitrudra (you can change it on line number 127)

import javax.swing.*;
import java.time.LocalDate;
import java.time.temporal.*;

public class librarymanagementprojectjava
{
public static void main(String args[])
 {
	JOptionPane.showMessageDialog(null, "WELCOME TO LIBRARY");
	lib l=new lib();
	l.menu();
  }
}		
 class lib
 {
	public void info()
	{
	JOptionPane.showMessageDialog(null, "Enter info");
	String name=JOptionPane.showInputDialog("Enter Name");
	System.out.println("Name:"+name);
	long reg=Integer.parseInt(JOptionPane.showInputDialog("Enter your registration no"));
		System.out.println("Registration no:"+reg);
    }
    public void ViewBooks()
	{
	    JOptionPane.showMessageDialog(null, "List of all the books\n\n 1.java\n 2.Data Structures\n 3.STLD\n 4.Maths\n 5.COA\n 6.Value Ethics\n Choose only 1 book !");
		int ibook=Integer.parseInt(JOptionPane.showInputDialog("Book chosen"));
		switch(ibook)
		{ 
		   case 1:
			System.out.println("Issued book is Java");
			break;
		   case 2:
			System.out.println("Issued book is Data structures");
			break;
		   case 3:
			System.out.println("Issued book is STLD");
			break;
		   case 4:
			System.out.println("Issued book is Maths");
            break;
		   case 5:
			System.out.println("Issued book is COA");
			break;
		   case 6:
			System.out.println("Issued book is Value ethics");
			break;
		default:
			System.out.println("book not available");
			JOptionPane.showMessageDialog(null, "Book Not Available !");
			ViewBooks();
			break;
		 }
		
		details();
		next();
   }
	public void details()
	{
		LocalDate IssueDate = LocalDate.now();
		JOptionPane.showMessageDialog(null, "issue date is: "+IssueDate);
		System.out.println("Issue date is :"+IssueDate);
		LocalDate ReturnDate=IssueDate.plusDays(15);
		JOptionPane.showMessageDialog(null, "Return date is: "+ReturnDate);
		System.out.println("Return date is :"+ReturnDate);
		
		JTextField rd = new JTextField();
		JTextField rm = new JTextField();
		JTextField ry = new JTextField();
		Object[] message =
			{
		    "Date:", rd,
		    "Month:",rm,
		    "Year:",ry
		    };
		int option = JOptionPane.showConfirmDialog(null, message, "Returning Day:", JOptionPane.OK_CANCEL_OPTION);
		if (option == JOptionPane.OK_OPTION)
		{
		    String value1 = rd.getText();
		    String value2 = rm.getText();
		    String value3 = ry.getText();
		    int d = Integer.parseInt(value1);
			 int m = Integer.parseInt(value2);
			 int y = Integer.parseInt(value3);
			 LocalDate ReturningDate = LocalDate.of(y, m, d);
			 System.out.println("Returning day is : "+value3+"-"+value2+"-"+value1);
		    JOptionPane.showMessageDialog(null, "Returning date is: "+ReturningDate);
		    long days=ChronoUnit.DAYS.between(ReturnDate, ReturningDate);
		    long fine= days*2;
		    JOptionPane.showMessageDialog(null, "Days due: "+days);
		    System.out.println("Days due:"+days);
		    JOptionPane.showMessageDialog(null, "Total fine: "+fine);
		    System.out.println("Total fine:"+fine);
		  }
	}
	public void next()
	{
		int n=Integer.parseInt(JOptionPane.showInputDialog("1.Choose book\n 2.Exit"));
		switch(n)
		{
		case 1:
			ViewBooks();
			break;
		case 2:
			JOptionPane.showMessageDialog(null, "Exiting..\n THANKYOU!");
			break;
		}
	}
	public void menu()
{
		JTextField username = new JTextField();
		JTextField password = new JPasswordField();
		Object[] message =
			{
		    "Username:", username,
		    "Password:", password
		    };

		int option = JOptionPane.showConfirmDialog(null, message, "Login", JOptionPane.OK_CANCEL_OPTION);
		if (option == JOptionPane.OK_OPTION) 
		{
		    if (username.getText().equals("ankitrudra") && password.getText().equals("ankitrudra"))
		    {
		    	JOptionPane.showMessageDialog(null, "LOGIN SUCCESSFUL");
		    	 info();
		 	    ViewBooks();
		    }
		    else 
		    {
		    	JOptionPane.showMessageDialog(null, "LOGIN FAILED \n TRY AGAIN");
		    	menu();
		    }
		} 
}
}
