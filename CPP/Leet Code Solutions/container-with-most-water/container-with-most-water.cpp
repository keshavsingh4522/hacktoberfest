class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int area=0;
        while(i<j){
            int minht=min(height[i],height[j]);
            area=max(minht*(j-i),area);
            while(height[i]<=minht&&i<j)i++;
            while(height[j]<=minht&&i<j)j--;
        }
        return area;
    }
};