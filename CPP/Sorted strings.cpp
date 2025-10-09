#include<stdio.h>
#include<string.h>

int main()
{
	char a[10][10],temp[10];
	int i,j,n;
	printf("Enter the number of strings....");
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
	{
		printf("Enter string :");
		gets(a[i]);	
	}
	for(i=i;i<=n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
					
			}	
		}	
	}
	printf("\nSorted strings are...");
	for(i=0;i<n;i++)
	{
		printf("\n%s",a[i]);	
	}	
}





