class NumArray {
public:
    vector<int>tree;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.assign(2*n,0);
        for(int i=n;i<2*n;i++)
            tree[i]=nums[i-n];
        for(int i=n-1;i>0;i--)
            tree[i]=tree[i*2]+tree[i*2+1];
    }
    
    void update(int index, int val) {
        index+=n;
        tree[index]=val;
        while(index){
            int l=index,r=index;
            if(index%2==0)
                r=index+1;
            else
                l=index-1;
        tree[index/2]=tree[l]+tree[r];
        index/=2;
        }
        
    }
    
    int sumRange(int l, int r) {
        l+=n,r+=n;
        int sum=0;
        while (l <= r) {
        if ((l % 2) == 1) {
           sum += tree[l];
           l++;
        }
        if ((r % 2) == 0) {
           sum += tree[r];
           r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
    }
};