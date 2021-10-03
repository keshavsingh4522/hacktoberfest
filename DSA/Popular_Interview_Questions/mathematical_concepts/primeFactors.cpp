void printPrimeFactors(int n){
    if(n<=1){
        return;
    }

    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            cout<<i<<" ";
            n=n/i;
        }
    }
}