#include<stdio.h>

int main()
{
    printf("\nGOR SMIT HASMUKHBHAI(19BCT0103)");

    int burstTime[20], process[20], waitingTime[20], turnaroundTime[20], priority[20];
    int i, j, n, sum = 0, position, temp;
    float average_wait_time, average_turnaroundTime;
    printf("\n\nEnter Total Number of Processes : ");
    scanf("%d", &n);
    printf("\nEnter Burst Time and Priority For %d Processes\n", n);
    for(i = 0; i < n; i++)
    {
        printf("\nProcess[%d]\n", i + 1);
        printf("Process Burst Time : ");
        scanf("%d", &burstTime[i]);
        printf("Process Priority : ");
        scanf("%d", &priority[i]);
        process[i] = i + 1;
    }
    for(i = 0; i < n; i++)
    {
        position = i;
        for(j = i + 1; j < n; j++)
        {
            if(priority[j] < priority[position])
            {
                position = j;
            }
        }
        temp = priority[i];
        priority[i] = priority[position];
        priority[position] = temp; 
        temp = burstTime[i];
        burstTime[i] = burstTime[position];
        burstTime[position] = temp;
        temp = process[i];
        process[i] = process[position];
        process[position] = temp;
    }
    waitingTime[0] = 0;
    for(i = 1; i < n; i++)
    {
        waitingTime[i] = 0;
        for(j = 0; j < i; j++)
        {
            waitingTime[i] = waitingTime[i] + burstTime[j];
        }
        sum = sum + waitingTime[i];
    }
    average_wait_time = sum / n;
    sum = 0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i = 0; i < n; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        sum = sum + turnaroundTime[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    average_turnaroundTime = sum / n;
    printf("\nAverage Waiting Time : %f", average_wait_time);
    printf("\nAverage Turnaround Time : %f\n", average_turnaroundTime);
    printf("\n\nSubmited By SMIT GOR\n Reg. No. : 19BCT0103");
    return 0;
}