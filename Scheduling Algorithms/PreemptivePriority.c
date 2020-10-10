#include<stdio.h>
 
struct process
{
    char process_name;
    int arrivalTime , burstTime, ct, waitingTime, turnaround_time, priority;
    int status;
}process_queue[10];
 
int n;
 
void ArrivalTime_Sorting()
{
    struct process temp;
    int i, j;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(process_queue[i].arrivalTime  > process_queue[j].arrivalTime )
            {
                temp = process_queue[i];
                process_queue[i] = process_queue[j];
                process_queue[j] = temp;
            }
        }
    }
}
 
void main()
{
    printf("\nGOR SMIT HASMUKHBHAI(19BCT0103)");

    int i, time = 0, burstTime = 0, l;
    char c;
    float wait_time = 0, turnaround_time = 0, average_waitingTime, average_turnaround_time;
    printf("\nEnter Total Number of Processes : ");
    scanf("%d", &n);
    for(i = 0, c = 'A'; i < n; i++, c++)
    {
        process_queue[i].process_name = c;
        printf("\nEnter Details For Process[%C] : \n", process_queue[i].process_name);
        printf("Enter Arrival Time : ");
        scanf("%d", &process_queue[i].arrivalTime  );
        printf("Enter Burst Time : ");
        scanf("%d", &process_queue[i].burstTime);
        printf("Enter Priority : ");
        scanf("%d", &process_queue[i].priority);
        process_queue[i].status = 0;
        burstTime = burstTime + process_queue[i].burstTime;
    }
    ArrivalTime_Sorting();
    process_queue[9].priority = -9999;
    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
    for(time = process_queue[0].arrivalTime ; time < burstTime;)
    {
        l = 9;
        for(i = 0; i < n; i++)
        {
            if(process_queue[i].arrivalTime  <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[l].priority)
            {
                l = i;
            }
        }
        time = time + process_queue[l].burstTime;
        process_queue[l].ct = time;
        process_queue[l].waitingTime = process_queue[l].ct - process_queue[l].arrivalTime  - process_queue[l].burstTime;
        process_queue[l].turnaround_time = process_queue[l].ct - process_queue[l].arrivalTime ;
        process_queue[l].status = 1;
        wait_time = wait_time + process_queue[l].waitingTime;
        turnaround_time = turnaround_time + process_queue[l].turnaround_time;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[l].process_name, process_queue[l].arrivalTime , process_queue[l].burstTime, process_queue[l].priority, process_queue[l].waitingTime);
    }
    average_waitingTime = wait_time / n;
    average_turnaround_time = turnaround_time / n;
    printf("\n\nAverage waiting time:\t%f\n", average_waitingTime);
    printf("Average Turnaround Time:\t%f\n", average_turnaround_time);

    
    printf("\n\nSubmited By SMIT GOR\n Reg. No. : 19BCT0103");
}

