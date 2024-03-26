#include<stdio.h>
#include<stdlib.h>
#define MAX_PROCESSES 10
struct Process {
int id;
int priority;
};
// Function to select the process with the highest priority
struct Process selectHighestPriority(struct Process processes[], int n) {
int i;
struct Process highestPriorityProcess = processes[0];
for (i = 1; i < n; i++) {
if (processes[i].priority > highestPriorityProcess.priority) {
highestPriorityProcess = processes[i];
}
}
return highestPriorityProcess;
}
int main() {
struct Process processes[MAX_PROCESSES];
int n;
// Input the number of processes
printf("Enter the number of processes: ");
scanf("%d", &n);
// Input details of each process
printf("Enter details of each process:\n");
int i;
for (i = 0; i < n; i++) {
printf("Process %d:\n", i + 1);
processes[i].id = i + 1;
printf("Priority: ");
scanf("%d", &processes[i].priority);
}

// Select the process with the highest priority
struct Process nextProcess = selectHighestPriority(processes, n);

// Display the selected process
printf("Process with the highest priority:\n");
printf("ID: %d\n", nextProcess.id);
printf("Priority: %d\n", nextProcess.priority);

return 0;
}
