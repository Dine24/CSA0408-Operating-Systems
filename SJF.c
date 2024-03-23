#include<stdio.h>
int main() {
int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
float avg_wt, avg_tat;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter Burst Time:\n");
for (i = 0; i < n; i++) {
printf("P%d: ", i + 1);
scanf("%d", &bt[i]);
p[i] = i + 1;
}
// Sort processes based on burst time (Selection Sort)
for (i = 0; i < n - 1; i++) {
pos = i;
for (j = i + 1; j < n; j++) {
if (bt[j] < bt[pos])
pos = j;
}
// Swap burst time and process IDs
temp = bt[i];
bt[i] = bt[pos];
bt[pos] = temp;
temp = p[i];
p[i] = p[pos];
p[pos] = temp;
}
wt[0] = 0; 
total = 0;
for (i = 1; i < n; i++) {
wt[i] = 0;
for (j = 0; j < i; j++)
wt[i] += bt[j];
total += wt[i];
}
avg_wt = (float)total / n; 
total = 0;
printf("\nProcess   Burst Time   Waiting Time   Turnaround Time\n");
for (i = 0; i < n; i++) {
tat[i] = bt[i] + wt[i]; 
total += tat[i];
printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
}
avg_tat = (float)total / n; 
printf("\nAverage Waiting Time= %.2f\n", avg_wt);
printf("Average Turnaround Time= %.2f\n", avg_tat);
return 0;
}
