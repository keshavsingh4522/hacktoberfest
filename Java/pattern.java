 import java.io.*;
/**
 * class Employee
 *
*
 */
class Employee
{
    // instance variables
    int pan;
    String name;
    double taxIncome, tax;

    // read the data from the keyboard
    public void input()throws IOException
    {
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(in);
        System.out.println("Enter the name, pan and taxable income : ");
        name = br.readLine();
        pan = Integer.parseInt(br.readLine());
        taxIncome = Double.parseDouble(br.readLine());
       
    }

    // Method calculate tax
    public void calc()
    {
        tax = 0.0;
        if( (taxIncome > 100000) && (taxIncome <= 150000) )
          tax = (taxIncome - 100000) * 0.1;
        else if( (taxIncome > 150000) && (taxIncome <= 250000) )
          tax = 5000.0 + (taxIncome - 150000) * 0.2;
        else
          tax = 25000.0 + (taxIncome - 250000) * 0.3;
    }

    // display details of an employee
    public void display()
    {
        System.out.println("Pan Number        Name                 Tax-income         Tax");
        System.out.println(pan+"           " + name + "               " + taxIncome + "      " + tax);
    }
// Main method
    public static void main(String args[])throws IOException
    {
        Employee ob=new Employee();
        ob.input();
        ob.calc();
        ob.display();
    }
}
