#include<stdio.h>

int id[20],completed[20],arrivalTime[20],burstTime[20],ct[20],tat[20],wt[20];
int n,t=0,noOfCompletedProcess=0,i,temp=0,temp1,j;

void print_table()
{
    float avgWT=0,avgTAT=0;
    printf("\n\n\n\n\n");
    printf("\n|---------------------------------------------------------------------------|");
    printf("\n|  id  |  Arrival Time  |  Burst Time  |  Turtaround Time  |  Waiting Time  |");
    printf("\n|---------------------------------------------------------------------------|");
    for(int i=0;i<n;i++)
    {
        printf("\n|   %d  |       %d        |      %d       |         %d         |        %d       |",id[i],arrivalTime[i],burstTime[i],tat[i],wt[i]);
        printf("\n|---------------------------------------------------------------------------|");
    }
    for(int i=0;i<n;i++)
    {
        avgTAT+=tat[i];
        avgWT+=wt[i];
    }
    avgTAT/=n;
    avgWT/=n;
    printf("\n\n");
    printf("\nAverage waiting time : %.3f\n",avgWT);
    printf("\nAverage Turnaround time : %.3f\n\n\n",avgTAT);
    

}

void print_gnatt()
{
    printf("\n\n\n");
    printf("___________Gnatt Chart____________\n\n\n");
    printf("|-----------------|--------------|\n");
    printf("|  Time Interval  |  Process ID  |\n");
    printf("|-----------------|--------------|");
}

void sort()
{
    for(i=0;i<n;i++)
    {
        temp=burstTime[i];
        for(j=i;j<n;j++)
        {
            if(burstTime[j]<temp)
            {
                temp=burstTime[j];
                temp1=burstTime[i];
                burstTime[i]=burstTime[j];
                burstTime[j]=temp1;
                
                temp1=arrivalTime[i];
                arrivalTime[i]=arrivalTime[j];
                arrivalTime[j]=temp1;

                temp1=id[i];
                id[i]=id[j];
                id[j]=temp1;
            }
        }
    }
}

int notDone(int x)
{
    for(j=0;j<noOfCompletedProcess;j++)
    {
        if(x==completed[j])
        {
            return 0;
        }
    }
    return 1;
}

int nextProcess()
{
    for(i=0;i<n;i++)
    {
        if(notDone(id[i]))
        {
            if(t>=arrivalTime[i])
            {
                
                completed[noOfCompletedProcess]=id[i];
                noOfCompletedProcess++;
                if(t/10>0)
                {
                    printf("\n|     %d -",t);
                }
                else
                {
                    printf("\n|      %d -",t);
                }
                t+=burstTime[i];
                if(t/10>0)
                {
                printf(" %d     |      %d       |\n",t,id[i]);
                }
                else
                {   
                    printf(" %d      |      %d       |\n",t,id[i]);
 
                }
                printf("|-----------------|--------------|");
                ct[i]=t;
                tat[i]=ct[i]-arrivalTime[i];
                wt[i]=tat[i]-burstTime[i];
                return i;
            }
        }
    }
    t++;
    printf("\n|      %d - %d      |     IDLE     |\n",t-1,t);
    printf("|-----------------|--------------|");
    return nextProcess();
}

int main()
{
    printf("GOR SMIT HASMUKHBHAI(19BCT0103)");
    int nextid;
    printf("\nEnter the total number of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process id : ");
        scanf("%d",&id[i]);
        printf("Enter the Arrival time : ");
        scanf("%d",&arrivalTime[i]);
        printf("Enter the Burst time : ");
        scanf("%d",&burstTime[i]);
        printf("\n");
    }
    sort();
    print_gnatt();
    do
    {
        nextid=nextProcess();
    } while (noOfCompletedProcess!=n);

    print_table();

    printf("\n\nSubmited By SMIT GOR\n Reg. No. : 19BCT0103");

}