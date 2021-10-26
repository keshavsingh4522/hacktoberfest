#include<stdio.h>
int main()
{
int p[10]={0},at[10]={0},bt[10]={0},n,i,j,k,temp,wt[10]={0},tat[10]={0},ct[10]={0},sum=0;
float totaltat=0,totalwt=0;
printf("Enter the number of process ");
scanf("%d",&n);
printf("Enter the value of arival time and burst time\n\n");
for(i=0;i<n;i++)
{
	    printf("Arrival time[%d]", i+1);
	    scanf("%d",&at[i]);
	    printf("Burst time[%d]", i+1);
	    scanf("%d",&bt[i]);
	    printf("\n");
}
     // using bubble sort algorithm
     for(i=0;i<n;i++)
     {
     	for(j=0;j<n-i-1;j++)
     	{
     		if(bt[j]>bt[j+1])
     		{
     			temp=bt[j];
     			bt[j]=bt[j+1];
     			bt[j+1]=temp;
     			
     			temp=p[j];
     			p[j]=p[j+1];
     			p[j+1]=temp;
			 }
		 }
	 }
	 for(j=0;j<n;j++)
        {
        	sum+=bt[j];
        	ct[j]+=sum;
		}
	 for(j=0;j<n;j++)
		{
			tat[j]=ct[j]-at[j];
			totaltat+=tat[j];
		}
		for(j=0;j<n;j++)
		 {
		 	 wt[j]=tat[j]-bt[j];
		 	 totalwt+=wt[j];
		 }
		 printf("Solution: \n\n");
		 printf("PR\t AT\t BT\t CT\t TAT\t WT\t \n\n");
		 for(i=0;i<n;i++)
		 {
		 	printf("p%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		 }
		 printf("\n\n Average turnaround time=%f\n", totaltat/n);
		 printf("\n\n Average Wating time=%f\n", totalwt/n);
		 return 0;
    }
 /*   output
    __________________________________________________________________________________________________________________________
    Enter the number of process 5
Enter the value of arival time and burst time

Arrival time[1]0
Burst time[1]2

Arrival time[2]1
Burst time[2]6

Arrival time[3]2
Burst time[3]4

Arrival time[4]3
Burst time[4]9

Arrival time[5]4
Burst time[5]12


Solution:

PR       AT      BT      CT      TAT     WT

p1       0       2       2       2       0
p2       1       4       6       5       1
p3       2       6       12      10      4
p4       3       9       21      18      9
p5       4       12      33      29      17


 Average turnaround time=12.800000 


 Average Wating time=6.200000

-------------------------------- */
