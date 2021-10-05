//Find the Longest Palindrome Substring from a string
//Example- avcedecvxyz output - vcedecv

import java.util.*;
public class LongestPalindromicSubstring{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        //Applying expand from centre approach
        int start = 0, end = 0;
        for(int i=0;i<s.length();i++){                           //This loop takes O(n) time complexity
            int len1 = expandFromCentre(s,i,i+1);              //When the string will be like baab
            int len2 = expandFromCentre(s,i,i);                  //When the string will be like bab
            int len = Math.max(len1, len2);
            if(end-start < len){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        System.out.println(s.substring(start, end+1));
    }
    public static int expandFromCentre(String s, int i, int j){        //This loop takes O(n) time complexity
        while(i>=0 && j<s.length() && s.charAt(i)==s.charAt(j)){
            i--;j++;
        }
        return j-i-1;
    }
}

//Time Complexity - O(n^2)
//Space Complexity - O(1)