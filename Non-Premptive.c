#include <stdio.h>
// Process structure
typedef struct {
int process_id;
int arrival_time;
int burst_time;
} Process;

// Function to perform non-preemptive SJF scheduling
void sjf(Process processes[], int n) {
int waiting_time[n], turnaround_time[n];

// Initialize waiting time and turnaround time arrays
int i;
for (i = 0; i < n; i++) {
waiting_time[i] = 0;
turnaround_time[i] = 0;
}

// Sort processes based on arrival time
for (i = 0; i < n - 1; i++) {
	int j;
for (j = 0; j < n - i - 1; j++) {
if (processes[j].arrival_time > processes[j + 1].arrival_time) {
Process temp = processes[j];
processes[j] = processes[j + 1];
processes[j + 1] = temp;
}
}
}

int total_waiting_time = 0;
int total_turnaround_time = 0;
int current_time = 0;

// Calculate waiting time and turnaround time
for (i = 0; i < n; i++) {
// Calculate waiting time for current process
waiting_time[i] = current_time - processes[i].arrival_time;
if (waiting_time[i] < 0)
waiting_time[i] = 0;

// Calculate turnaround time for current process
turnaround_time[i] = waiting_time[i] + processes[i].burst_time;

// Update current time
current_time += processes[i].burst_time;

// Update total waiting time and total turnaround time
total_waiting_time += waiting_time[i];
total_turnaround_time += turnaround_time[i];
}

// Calculate average waiting time and average turnaround time
float avg_waiting_time = (float)total_waiting_time / n;
float avg_turnaround_time = (float)total_turnaround_time / n;

// Print results
printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (i = 0; i < n; i++) {
printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
}
printf("Average Waiting Time: %.2f\n", avg_waiting_time);
printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);

// Array to store processes
Process processes[n];

// Input process details
int i;
for (i = 0; i < n; i++) {
printf("Enter arrival time and burst time for process %d: ", i + 1);
scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
processes[i].process_id = i + 1;
}

sjf(processes, n);

return 0;
}
