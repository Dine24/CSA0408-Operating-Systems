#include<stdio.h>
struct Process {
char process_name;
int burst_time;
int waiting_time;
int turn_around_time;
int priority;
};
int main() {
int number_of_processes;
int total_waiting_time = 0;
struct Process temp_process;
int ASCII_number = 65;
int position;
float average_waiting_time;
float average_turnaround_time;
printf("Enter the total number of Processes: ");
scanf("%d", &number_of_processes);
struct Process processes[number_of_processes];
printf("\nPlease Enter the Burst Time and Priority of each process:\n");
int i;
for (i = 0; i < number_of_processes; i++) {
processes[i].process_name = (char) ASCII_number;
printf("\nEnter the details of the process %c\n", processes[i].process_name);
printf("Enter the burst time: ");
scanf("%d", &processes[i].burst_time);
printf("Enter the priority: ");
scanf("%d", &processes[i].priority);
ASCII_number++;
}
// Sort processes based on priority (Highest priority first)
for (i = 0; i < number_of_processes - 1; i++) {
position = i;
int j;
for (j = i + 1; j < number_of_processes; j++) {
if (processes[j].priority > processes[position].priority)
position = j;
}
temp_process = processes[i];
processes[i] = processes[position];
processes[position] = temp_process;
}
processes[0].waiting_time = 0;
// Calculate waiting time for each process
for (i = 1; i < number_of_processes; i++) {
processes[i].waiting_time = 0;
int j;
for (j = 0; j < i; j++) {
processes[i].waiting_time += processes[j].burst_time;
}
total_waiting_time += processes[i].waiting_time;
}
average_waiting_time = (float) total_waiting_time / (float) number_of_processes;
// Calculate turnaround time for each process and display process details
printf("\n\nProcess_name\tBurst Time\tWaiting Time\tTurnaround Time\n");
printf("-----------------------------------------------------------\n");
int total_turnaround_time = 0;
for (i = 0; i < number_of_processes; i++) {
processes[i].turn_around_time = processes[i].burst_time + processes[i].waiting_time;
total_turnaround_time += processes[i].turn_around_time;
printf("\t%c\t\t%d\t\t%d\t\t%d\n", processes[i].process_name, processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time);
printf("-----------------------------------------------------------\n");
}
average_turnaround_time = (float) total_turnaround_time / (float) number_of_processes;
printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
return 0;
}
