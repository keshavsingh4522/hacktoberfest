package com.company;

import java.util.Scanner;

public class LocalMin {
    public static void main(String[] args) {
        // local minimum - the number which is smaller than its 2 neighbors. For example: 2 7 3 5, there is 3 is local minimum
        // code will equal the local minimum to 0
        Scanner in = new Scanner(System.in);
        System.out.print("n = ");
        int n = in.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++){
            System.out.print("arr["+i+"] = ");
            arr[i] = in.nextInt();
        }
        System.out.print("Changed array: "+arr[0]+"; ");
        for (int i = 1; i<n-1; i++){
            if (arr[i]<arr[i-1] && arr[i]<arr[i+1]){
//                System.out.println("local min = "+arr[i]);
                arr[i] = 0;
            }
            System.out.print(arr[i]+"; ");
        }
        System.out.print(arr[n-1]+"; ");
    }
}
