import java.util.Scanner;

public class JavaProgram
{
    public static void main(String args[])
    {
        int decnum, rem;
        String hexdecnum="";
        
        char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        
        Scanner scan = new Scanner(System.in);
      
        System.out.print("Enter Decimal Number : ");
        decnum = scan.nextInt();
      
        while(decnum>0)
        {
            rem = decnum%16;
            hexdecnum = hex[rem] + hexdecnum;
            decnum = decnum/16;
        }
      
        System.out.print("Equivalent Hexadecimal Value of " + decnum + " is :\n");
        System.out.print(hexdecnum);
    }
}
