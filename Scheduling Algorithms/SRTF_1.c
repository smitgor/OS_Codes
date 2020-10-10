#include <stdio.h>
 
int main() 
{
    printf("\nGOR SMIT HASMUKHBHAI(19BCT0103)");

      int arrivalTime[10], burstTime[10], temp[10];
      int i, smallest, count = 0, time, n;
      double waitingTime = 0, turnaroundTime = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes : ");
      scanf("%d", &n); 
      printf("\nEnter Details of %d Processes\n", n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time : ");
            scanf("%d", &arrivalTime[i]);
            printf("Enter Burst Time : ");
            scanf("%d", &burstTime[i]); 
            temp[i] = burstTime[i];
      }
      burstTime[9] = 9999;  
      for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(arrivalTime[i] <= time && burstTime[i] < burstTime[smallest] && burstTime[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burstTime[smallest]--;
            if(burstTime[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  waitingTime = waitingTime + end - arrivalTime[smallest] - temp[smallest];
                  turnaroundTime = turnaroundTime + end - arrivalTime[smallest];
            }
      }
      average_waiting_time = waitingTime / n; 
      average_turnaround_time = turnaroundTime / n;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);

    printf("\n\nSubmited By SMIT GOR\n Reg. No. : 19BCT0103");
    return 0;
}
