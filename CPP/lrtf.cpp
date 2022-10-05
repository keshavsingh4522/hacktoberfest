#include <stdio.h>
#include <bits/stdc++.h>

struct process {
    int processno;
    int AT;
    int BT;
    int BTbackup;
    int WT;
    int TAT;
    int CT;
};
struct process p[6];
int totaltime = 0;
int prefinaltotal = 0;
bool compare(process p1, process p2)
{
    return p1.AT < p2.AT;
}
int findlargest(int at)
{
    int max = 0, i;
    for (i = 0; i < 6; i++) {
        if (p[i].AT <= at) {
            if (p[i].BT > p[max].BT)
                max = i;
        }
    }
    return max;
}
int findCT()
{
  
    int index;
    int flag = 0;
    int i = p[0].AT;
    while (1) {
        if (i <= 6) {
            index = findlargest(i);
        }
  
        else
            index = findlargest(6);
        p[index].BT -= 1;
        totaltime += 1;
        i++;
  
        if (p[index].BT == 0) {
            p[index].CT = totaltime;
        }
        
        if (totaltime == prefinaltotal)
            break;
    }
    return 0;
}
  
int main()
{
  
    int i;
    for (i = 0; i < 6; i++) {
        p[i].processno = i + 1;
    }
  
     printf("Enter arrival time of 6 processes : ");
    for (i = 0; i < 6; i++)
    {
        scanf("%d",&p[i].AT);
    }
  
     printf(" Enter Burst time of 6 processes : ");
    for (i = 0; i < 6; i++) {
        scanf("%d",&p[i].BT);
        p[i].BTbackup = p[i].BT;
        prefinaltotal += p[i].BT;
    }
    sort(p, p + 6, compare);
    totaltime += p[0].AT;
    prefinaltotal += p[0].AT;
    findCT();
    int totalWT = 0;
    int totalTAT = 0;
    for (i = 0; i < 6; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BTbackup;
  
        totalWT += p[i].WT;
  
        totalTAT += p[i].TAT;
    }
  
    
    printf("PNo\tAT\tBT\tCT\tTAT\tWT\n");
  
    for (i = 0; i < 6; i++) {
        printf("%d\t",p[i].processno);
         printf("%d\t",p[i].AT);
        printf("%d\t",p[i].BTbackup);
         printf("%d\t",p[i].CT);
         printf("%d\t",p[i].TAT);
         printf("%d\t",p[i].WT);
        printf("\n");
    }
  	int atat =totalTAT/6;
  	int awt = totalWT/6;
    printf("\n");
    printf("Total TAT = %d\n",totalTAT);
    printf("Average TAT = %d\n" , atat);
    printf("Total WT = %d\n",totalWT);
    printf("Average WT = %d", awt);
    return 0;
}
