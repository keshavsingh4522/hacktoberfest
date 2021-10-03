#include<stdio.h>
#include<math.h>
int main(){
	int num,count=0,arm=0,val,rem;
	scanf("%d",&num);
	val=num;
	while(num>0){
		num/=10;
		count++;
	}
	num=val;
	while(num>0){
		rem=num%10;
		num/=10;
		arm=arm+pow(rem,count);
	}
	if(val==arm)
		printf("Armstrong Number");
	else
		printf("Not an Armstrong Number");
	return 0;
}
