#include <stdio.h>

int main(){
	int n=5;
	int at[n], bt[n], wt[n], rt[n], tat[n],ct[n], p[n];
	printf("Enter Arrival Time\n");
	for(int i=0;i<=n;i++){
		printf("P[%d] :",i+1);
		scanf("%d",&at[i]);
	}
	printf("Enter Burst Time\n");
	for(int i=0;i<=n;i++){
		printf("P[%d] :",i+1);
		scanf("%d",&bt[i]);
	}
	printf("Enter Priority\n");
	for(int i=0;i<=n;i++){
		printf("P[%d] :",i+1);
		scanf("%d",&p[i]);
	}
	int temp=0,pos=0;
	for(int i=0;i<=n;i++)
    {
        pos=i;
        for(int j=i+1;j<=n;j++)
        {
            if(p[j]<p[pos])
                pos=j;
        }
  	
  		temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
  	
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
    }
	for(int i=0;i<=n;i++){
		ct[0]=bt[0];
		for(int j=1;j<=i;j++){
			ct[j]=ct[j-1] + bt[j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			tat[j]=ct[j] - at[j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			wt[j]=tat[j] - bt[j];
		}
	}
	printf("Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Responce Time\n");
	for(int i=0;i<=n;i++){
		
		printf("      %d            %d               %d            %d                 %d             %d      \n",at[i],bt[i],ct[i],tat[i],wt[i],wt[i]);
	}
	int awt=0,att=0;
	for(int i=0;i<=n;i++){
		awt+=wt[i]/n;
		att+=tat[i]/n;
	}
	printf("Average Turnaround Time: %d\n",att);
	printf("Average Waitng Time: %d\n",awt);
	printf("Average Running Time: %d\n",awt);
	
}
