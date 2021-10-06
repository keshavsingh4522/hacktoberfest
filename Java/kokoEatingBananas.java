//875: leetcode - https://leetcode.com/problems/koko-eating-bananas/

public class kokoEatingBananas {
    public static void main(String[] args) {
        int[] piles = {30, 11, 23, 4, 20};
        int hours = 6;
        int minSpeed = minEatingSpeed(piles, hours);
        System.out.println(minSpeed);
    }

    private static int minEatingSpeed(int[] piles, int hours) {
        int low = 1, high = getHigh(piles);
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(canKokoEatAllBananas(piles, mid, hours)) 
                high = mid - 1;
            else
                low =  mid + 1;
        }
        return low;
    }

    private static boolean canKokoEatAllBananas(int[] piles, int speed, int hours) {
        int count = 0;
        for(int i : piles){
            count += i/speed;
            if(i%speed != 0)
                count++;
        }
        return count <= hours;
    }

    private static int getHigh(int[] piles) {
        int max = 0;
        for(int i : piles)
            max = (max > i) ? max : i;
        return max;
    }
}
