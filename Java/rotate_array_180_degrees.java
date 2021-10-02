package main;

import java.util.Scanner;


public class rotate_array_180_degrees {
    public static void main(String[] args) {
        Scanner scan =  new Scanner(System.in);
        System.out.println("=== Rotate by 180 degrees ===");
        System.out.printf("Please input your total ordo m x n: ");
        int m = scan.nextInt();
        int n = scan.nextInt();
        int[][] arr = new int[m][n];

        System.out.printf("Input array elements %d x %d \n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                arr[i][j] = scan.nextInt();

            }
        }

        for (int i = arr.length-1; i >= 0; i--) {
            for (int j = arr.length-1; j >= 0; j--) {
                System.out.printf("%d ",arr[i][j]);

            }
            System.out.printf("\n");
        }
    }

}
