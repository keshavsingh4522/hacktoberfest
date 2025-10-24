package twosum;

import java.util.Scanner;

public class twoSum {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        // Get inputs
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        
        int[] arr = new int[n];
        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        System.out.println("Enter the target sum:");
        int target = sc.nextInt();
        
        boolean found = false;
        
        // Find two numbers that add up to target
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target) {
                    System.out.println("Two numbers found at indices " + i + " and " + j);
                    System.out.println("Numbers are: " + arr[i] + " + " + arr[j] + " = " + target);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (!found) {
            System.out.println("No two numbers found with the given target sum.");
        }
    }
}

