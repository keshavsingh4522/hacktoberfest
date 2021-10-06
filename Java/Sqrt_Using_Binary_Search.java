public class Sqrt_Using_Binary_Search {
    public static void main(String[] args) {
        int x = 7;
        System.out.println(sqrt(x));
        System.out.println(preciseSqrt(x));
    }

    private static int sqrt(int x) {
        if(x < 1) return 0;
        int start = 0, end = x;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(mid == x/mid)
                return mid;
            else if(mid < x/mid)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
}
