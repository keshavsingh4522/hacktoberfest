public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int start =1;
        int end = n;
        while(start<end){
            int mid=start+(end-start)/2;
            boolean answer = isBadVersion(mid);
            if(answer == false){
               
                start = mid+1;
            }
            else {
                 end = mid;
            }
        }
        return start;
    }
}
