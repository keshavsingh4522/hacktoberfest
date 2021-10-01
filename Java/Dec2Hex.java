package BJP;

import java.util.Scanner;

public class Dec2Hex {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the Decimal value: ");
        int decimal = scan.nextInt();
        int rem;
        String hex="";
        char hexchars[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        while(decimal>0)
        {
            rem=decimal%16;
            hex=hexchars[rem]+hex;
            decimal=decimal/16;
        }
        System.out.print("Hexadecimal value: "+hex);
    }
}
