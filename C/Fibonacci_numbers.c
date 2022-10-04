// Fibonacci numbers : here the next number is the sum of previous 2 numbers

# include<stdio.h>

int main()
{
	int first = 0, second = 1, sum = 0, num, i;
	
	printf("Enter the number of elements : ");
	scanf("%d", &num);
	
	// printing the first and second number in the series
	printf("Fibonacci Number :  %d %d",n1,n2); 
	
	// loop starts from 2 as the first and second number in series is already printed
	for(i = 2; i < number; i++)
	{    
		sum = first + second;    
		printf(" %d", sum);    
		first = second;    
		second = sum;    
	}  
	
	return 0;  
}
