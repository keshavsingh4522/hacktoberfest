#include<stdio.h>

int rpm( int no1, int no2){  
    // rpm = russian peasant method of multiplicatiion

    int res;
    res=0;

    while ( no1>0 ){
        
        if(no1%2==1){
            res+=no2;
        }
        no2*=2;
        no1/=2;
    }

    return res;
}

int main(void){
    int n1, n2;
    printf("Enter 2 numbers : ");
    scanf("%d%d",&n1,&n2);
    printf("%d x %d = %d\n",n1,n2,rpm(n1,n2));
}