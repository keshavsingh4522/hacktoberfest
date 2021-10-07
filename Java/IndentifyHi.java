//coded by shreeyachatzz
//Shreeya Chatterji
//Given a string, compute recursively (no loops) the number of times lowercase "hi" appears in the string.
import java.util.*;
class Q14
{  
    static int count(String str1,String str2) 
    { 
        int n1 = str1.length(); //Stores the length of the string from which the number of hi is to be found
        int n2 = str2.length(); //Stores the length of the string(hi) to be found;
        str1= str1.toLowerCase();
        str2= str2.toLowerCase();
        // Base Case 
        if (n1 == 0 || n1 < n2) //when the length of the string entered is less than the length of hi or is zero(in case of null)
        {
            return 0;
        }  
        //Recursive block which checks if the substring is equal to hi 
        if (str1.substring(0, n2).equals(str2)) 
        {
            return count(str1.substring(n2 - 1),str2) + 1; 
        }
        // Otherwise, return the count  
        // from the remaining index 
        return (count(str1.substring(n2 - 1),str2)); //the part of the entered string that goes to the next recursion has one letter from the front removed
    } 
    
    public static void main(String args[]) 
    { 
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the String in which the number of occurances of hi are to be calculated");
        String stra= sc.next();//Accepting the String form the user
        String strb = "hi"; //the string to be searched
        System.out.println("The number of times 'hi' appears in the entered String (not case sensitive) is/are :");
        System.out.println(count(stra,strb)); 
    } 
} 
/*
OUTPUT(1):
Enter the String in which the number of occurances of hi are to be calculated
xxhixx
The number of times 'hi' appears in the entered String (not case sensitive) is/are :
1

OUTPUT(2):
Enter the String in which the number of occurances of hi are to be calculated
HIxxhifgHiuuhI
The number of times 'hi' appears in the entered String (not case sensitive) is/are :
4

OUTPUT(3):
Enter the String in which the number of occurances of hi are to be calculated
xxhixxHIxxIhxxihxxHi!
The number of times 'hi' appears in the entered String (not case sensitive) is/are :
3
 */
