#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of processes and resources
#define MAX_P 10
#define MAX_R 10

// Function to calculate the need matrix
void calculateNeed(int need[MAX_P][MAX_R], int max[MAX_P][MAX_R], int alloc[MAX_P][MAX_R], int P, int R) {
int i,j;
for (i = 0; i < P; i++)
for (j = 0; j < R; j++)
need[i][j] = max[i][j] - alloc[i][j];
}

// Function to check if the requested resources are available
bool isSafe(int processes[], int avail[], int max[][MAX_R], int alloc[][MAX_R], int P, int R) {
int need[MAX_P][MAX_R];
calculateNeed(need, max, alloc, P, R);

bool finish[MAX_P] = {0};
int safeSeq[MAX_P];
int work[MAX_R];
int i;
for (i = 0; i < R; i++)
work[i] = avail[i];

int count = 0;
while (count < P) {
bool found = false;
int p;
for (p = 0; p < P; p++) {
if (!finish[p]) {
int j;
for (j = 0; j < R; j++)
if (need[p][j] > work[j])
break;
if (j == R) {
int k;
for (k = 0; k < R; k++)
work[k] += alloc[p][k];
safeSeq[count++] = p;
finish[p] = true;
found = true;
}
}
}
if (!found) {
printf("System is not in safe state");
return false;
}
}

printf("System is in safe state.\nSafe sequence is: ");
for (i = 0; i < P; i++)
printf("%d ", safeSeq[i]);
printf("\n");
return true;
}

// Main function
int main() {
int P, R;
printf("Enter number of processes: ");
scanf("%d", &P);
printf("Enter number of resources: ");
scanf("%d", &R);

int processes[MAX_P];
printf("Enter process IDs: ");
int i;
for (i = 0; i < P; i++)
scanf("%d", &processes[i]);

// Available instances of resources
int available[MAX_R];
printf("Enter available instances of resources: ");

for (i = 0; i < R; i++)
scanf("%d", &available[i]);

// Maximum R that can be allocated to processes
int max[MAX_P][MAX_R];
printf("Enter maximum resources that can be allocated to each process:\n");
for (i = 0; i < P; i++) {
printf("For process %d: ", processes[i]);
int j;
for (j = 0; j < R; j++)
scanf("%d", &max[i][j]);
}

// Resources allocated to processes
int allocation[MAX_P][MAX_R];
printf("Enter resources allocated to each process:\n");
for (i = 0; i < P; i++) {
printf("For process %d: ", processes[i]);
int j;
for (j = 0; j < R; j++)
scanf("%d", &allocation[i][j]);
}

// Check if the system is in safe state or not
isSafe(processes, available, max, allocation, P, R);

return 0;
}

