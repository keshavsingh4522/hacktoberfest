class Solution {
int mySqrt(int x)
{
    if (x == 0) {
            return 0;
        }
         
        if (x < 0) {
            return -1;
        }
         
        long lo = 0;
        long hi = x / 2 + 1;
         
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long sq = mid * mid;
            if (sq == x) {
                return (int) mid;
            }
             
            if (sq < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
         
        return (int) hi;
    
}
}
