#include<stdio.h>
 
int main()
{
    printf("\nGOR SMIT HASMUKHBHAI(19BCT0103)\n");

    int i, n, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, arrivalTime[10],id[10], burstTime[10], temp[10];
    float average_wait_time, average_turnaround_time;
    printf("\nEnter Total Number of Processes : ");
    scanf("%d", &n);
    x = n;
    for(i = 0; i < n; i++)
    {
        printf("Enter the process id : ");
        scanf("%d",&id[i]);
        printf("Enter the Arrival time : ");
        scanf("%d",&arrivalTime[i]);
        printf("Enter the Burst time : ");
        scanf("%d",&burstTime[i]);
        printf("\n"); 
        temp[i] = burstTime[i];
    }

    printf("\nEnter Time Quantum : ");
    scanf("%d", &time_quantum);
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
                total = total + temp[i];
                temp[i] = 0;
                counter = 1;
        }
        else if(temp[i] > 0)
        {
                temp[i] = temp[i] - time_quantum;
                total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
                x--;
                printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burstTime[i], total - arrivalTime[i], total - arrivalTime[i] - burstTime[i]);
                wait_time = wait_time + total - arrivalTime[i] - burstTime[i];
                turnaround_time = turnaround_time + total - arrivalTime[i];
                counter = 0;
        }
        if(i == n - 1)
        {
                i = 0;
        }
        else if(arrivalTime[i + 1] <= total)
        {
                i++;
        }
        else
        {
                i = 0;
        }
    }

    average_wait_time = wait_time * 1.0 / n;
    average_turnaround_time = turnaround_time * 1.0 / n;
    printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
    printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
    
    printf("\n\nSubmited By SMIT GOR\n Reg. No. : 19BCT0103");
    return 0;
}


