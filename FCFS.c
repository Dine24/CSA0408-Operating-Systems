#include <stdio.h>
int main() {
int processes[100][3];  
int n, i, j, total_waiting_time = 0, total_turnaround_time = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter Burst Time for each process:\n");
for (i = 0; i < n; i++) {
printf("P%d: ", i + 1);
scanf("%d", &processes[i][1]); 
processes[i][0] = i + 1; 
}
processes[0][2] = 0; // First process has 0 waiting time
for (i = 1; i < n; i++) {
processes[i][2] = processes[i - 1][2] + processes[i - 1][1]; // Waiting Time = Previous Waiting Time + Previous Burst Time
total_waiting_time += processes[i][2];
}
// Calculate turnaround time and display process details
printf("Process   Burst Time   Waiting Time   Turnaround Time\n");
for (i = 0; i < n; i++) {
int turnaround_time = processes[i][1] + processes[i][2]; // Turnaround Time = Burst Time + Waiting Time
total_turnaround_time += turnaround_time;
printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i][0], processes[i][1], processes[i][2], turnaround_time);
}
// Calculate and display average waiting time and average turnaround time
float avg_waiting_time = (float)total_waiting_time / n;
float avg_turnaround_time = (float)total_turnaround_time / n;
printf("\nAverage Waiting Time= %.2f\n", avg_waiting_time);
printf("Average Turnaround Time= %.2f\n", avg_turnaround_time);
return 0;
}

