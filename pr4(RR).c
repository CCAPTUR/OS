
#include<stdio.h>
int main()
{
//initialization
int i, limit, total = 0, x, counter = 0, time_quantum;
int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
float average_wait_time, average_turnaround_time;
//take user input
printf("\nEnter Total Number of Processes:\t");
scanf("%d", &limit);
x = limit;
//ask for no of process
for(i = 0; i < limit; i++)
{
printf("\nEnter Details of Process[%d]\n", i + 1);
printf("Arrival Time:\t");
scanf("%d", &arrival_time[i]);
printf("Burst Time:\t");
scanf("%d", &burst_time[i]);
temp[i] = burst_time[i];
}
//ask user tq
printf("\nEnter Time Quantum:\t");
scanf("%d", &time_quantum);
//to display all detail of process
printf("\nProcess ID\t\tBT\t\t TAT\t\t WT\n");
//process executed for remaining BT OR calculate total
for(total = 0, i = 0; x != 0;)
{
if(temp[i] <= time_quantum && temp[i] > 0)
{
total = total + temp[i];
temp[i] = 0;
counter = 1;
}
//increase time by tq
else if(temp[i] > 0)
{
temp[i] = temp[i] - time_quantum;
total = total + time_quantum;
}
//for each process display BT , TAT , WT
if(temp[i] == 0 && counter == 1)
{
x--;
printf("\nProcess[%d]\t\t %d\t\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total -
arrival_time[i] - burst_time[i]);
//Calculation of Turn Around Time // Calculation of Waiting Timeswait_time = wait_time + total - arrival_time[i] - burst_time[i];
turnaround_time = turnaround_time + total - arrival_time[i];
counter = 0;
}
if(i == limit - 1)
{
i = 0;
}
else if(arrival_time[i + 1] <= total)
{
i++;
}
else
{
i = 0;
}
}
average_wait_time = wait_time * 1.0 / limit;
average_turnaround_time = turnaround_time * 1.0 / limit;
printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
return 0;
}
