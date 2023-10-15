package com.binarySearchQuestion;
//https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/
public class smallestLetter {
    public static void main(String[] args) {
        char letters [] ={'a','b','c','d'};
        char target = 'b';
        System.out.println(ans(letters,target));
    }
   static char ans(char [] letters, int target ){
        int s =0;
        int e = letters.length - 1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(target<letters[mid]){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return letters[s%letters.length];
    }


}
