#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void  morning_walk()
{
	int a=8,g;

	for(g=5;g<a;g++)
	{
		if(g<8)
		{
			printf("%d:%d%:%d\n",g,g*0,g*0);
		}
	}
}

void breakfast()
{
	int i=10,j;
	
	for(j=8;j<=i;j++)
	{
		if(j<10)
		{
			printf("%d:%d:%d\n",j,j*00,j*00);
		}
	}
}

void lunch()
{
	int k=15,l;
	
	for(l=12;l<k;l++)
	{
		if(l<16)
		{
			printf("%d:%d:%d\n",l,l*0,l*0);
		}
	}
}

void dinner()
{
	int y=23,c;
	for(c=19;c<y;c++)
	{
		if(c<22)
		{
			printf("%d:%d:%d\n",c,c*0,c*0);
		}
	}
}

void sleep()
{
	int q=25,z,v=7,k;
	for(z=22;z<q;z++)
	{
		if(z<25)
		{
			printf("%d:%d:%d\n",z,z*0,z*0);
		}
	}
	for(k=1;k<v;k++)
	{
		if(k<7)
		{
			printf("%d:%d:%d\n",k,k*0,k*0);
		}
	}
}

void yes()
{
	printf("1. Morning Walk\n2. Breakfast\n3. Lunch\n4. Dinner\n5. Sleep\n6. Exit");
}

void no()
{
	printf("No Problem");
}

int main()
{
	int ch,ch1;
	
	printf("1. Morning Walk\n2. Breakfast\n3. Lunch\n4. Dinner\n5. Sleep\n6. Exit");
	
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:morning_walk();
			       break;       
			case 2:breakfast();
			       break;
			case 3:lunch();
			        break;
			case 4:dinner();
					break;
			case 5:sleep();
					break;		
			case 6:exit(0);	
			default:printf("Invalid Choice\n");	        
 	    }
 	    
 	    printf("\nDo you want to print menu (0/1)");
 	    
 	    printf("\nType.... ");
 	    scanf("%d",&ch1);
 	    
 	    switch(ch1)
 	    {
 	    	case 0:yes();
 	    	       break;
 	    	case 1:no();
 	    	       exit(0);
			       break;  
			default:printf("Incorrect Value");	        
		 }
	}
}
