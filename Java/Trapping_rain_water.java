 public int trap(int[] arr) {
         int n=arr.length;
        if(n==0 || n==1)
            return 0;
         int trapped=0;
        int larray[]=new int[n];
        int rarray[]=new int[n];
        larray[0]=arr[0];
        int lmax=arr[0];
        rarray[n-1]=arr[n-1];
        int rmax=arr[n-1];
        for(int i=1;i<n;i++){
            if(arr[i]>lmax){
                lmax=arr[i];
            }
                larray[i]=lmax;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>rmax){
                rmax=arr[i];
            }
                rarray[i]=rmax;
        }
        for(int i=0;i<n;i++){
            trapped += Math.min(larray[i],rarray[i]) - arr[i];
        }
        return trapped;
    }
