// Linear Search
#include <stdio.h>


int main(void)
{	
	int n;
	printf("Enter the number of value you want to enter in the array\n");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter the %d elements in the array\n",n);
	for(i=0;i<=n-1;i++);
	{
		scanf("%d",&arr[i]);
	}	
	int data;
	printf("Enter the number you want to seach in this array using the linear search\n");
	scanf("%d",&data);
	for(i=0;i<=n-1;i++)
	{
		if(arr[i] == data) 
		{
			printf("The data is in %d index and in %d position\n", i, i+1);
			break;
		}
	}
	if(i == n)
	{
		printf("The data is not present in the array\n"):
	}
	return 0;
}
