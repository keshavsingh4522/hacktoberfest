class Solution 
{
    public:
    bool solve(int a[],int n,int mid,int m)
    {
        int x=0,y=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid)
            return 0;
            x+=a[i];
            if(x>mid)
            {
                y++;
                x=a[i];
            }
        }
        if(y>m)
        return 0;
        else return 1;
    }
    int binarySearch(int a[],int n,int low,int high,int m)
    {
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(solve(a,n,mid,m))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=a[i];
        }
        return binarySearch(a,n,0,s,m);
    }
};
