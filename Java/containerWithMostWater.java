import java.util.*;
import java.util.Scanner;

public class ContainerWithMostWater {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        // Get inputs
        System.out.println("Enter the number of lines:");
        int n = sc.nextInt();
        
        int[] height = new int[n];
        System.out.println("Enter the heights of the lines:");
        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
        }
        
        int maxArea = findMaxArea(height);
        
        System.out.println("The maximum water that can be contained is: " + maxArea);
    }
    
    
    public static int findMaxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;
        
        while (left < right) {
            int width = right - left;
            int minHeight = Math.min(height[left], height[right]);
            int area = width * minHeight;
            
            maxArea = Math.max(maxArea, area);
            
            // Move the pointer pointing to the smaller line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
}

