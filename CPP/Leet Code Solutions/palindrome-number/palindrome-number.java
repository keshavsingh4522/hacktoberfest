class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverse = 0;
        int original = x;
        while(x!=0){
            int remainder = x%10;
            reverse = reverse*10 + remainder;
            x = x/10;
        }
        return reverse==original;
    }
}