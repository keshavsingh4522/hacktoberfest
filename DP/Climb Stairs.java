import java.io.*;
import java.util.*;

public class Main {

    static int[] dp;

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        dp = new int[n+1];
        System.out.println(climbStairs(n));
    }

    public static int climbStairs(int n) {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];

    }

}
