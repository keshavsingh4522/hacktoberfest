//441 - Leetcode - https://leetcode.com/problems/arranging-coins/

public class Arranging_Coins {
    public static void main(String[] args) {
        int n = 8;
        System.out.println(arrangeCoins(n));
        System.out.println(arrangeCoins2(n));
    }

    private static int arrangeCoins(int n) {
        long low = 0, high = n;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long current = mid * (mid + 1) / 2;
            if (current == n)
                return (int) mid;
            else if (current < n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return (int) high;
    }

    // Method 2 -
    private static int arrangeCoins2(int n) {
        for (int i = 1;; i++) {
            n -= i;
            if (n < 0)
                return i - 1;
        }
    }
}
