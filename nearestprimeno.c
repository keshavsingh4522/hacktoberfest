#include <stdio.h>
//This was gfg daily problem "Help Ishaan"
int main()
{
    int n,c,N,a;
    printf("Enter the number: ");
    scanf("%d",&n);
    N=n;
    a=n;
    if(n==1){
         printf("the difference is 1\n");
printf("it is lower next prime nothing\n");
printf("2 is the next prime\n");
printf("\n1 was the initial value\n");
    return 0;
    }
    while(1){
    for(int i=2;i<n;i++){
        c=n%i;
        if(c==0){//not prime
        break;
        }
    }
    if(c!=0){
        break;
    }
    n++;
}
while(1){
    for(int i=2;i<a;i++){
        c=a%i;
        if(c==0){
            break;
        }
    }
    if(c!=0){
        break;
    }
    a--;
}
if((N-a)<(n-N)){
    printf("the difference is %d\n",N-a);
}else{
    printf("the difference is %d\n",n-N);
}
printf("lower nearest prime is %d\n",a);
printf("%d is the next nearest prime\n",n);
printf("\n%d was the initial value given by you\n",N);
    return 0;
}
