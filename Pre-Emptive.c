#include<stdio.h>
int main()
{
int i, NOP, sum=0, count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
float avg_wt, avg_tat;

printf("Total number of processes in the system: ");
scanf("%d", &NOP);
y = NOP;
// Input arrival and burst time for each process
for(i=0; i<NOP; i++)
{
printf("\nEnter the Arrival and Burst time of Process[%d]\n", i+1);
printf("Arrival time: ");
scanf("%d", &at[i]);
printf("Burst time: ");
scanf("%d", &bt[i]);
temp[i] = bt[i];
}
printf("Enter the Time Quantum for the process: ");
scanf("%d", &quant);
// Sorting processes based on arrival time
for(i=0; i<NOP-1; i++) {
int j;
for(j=i+1; j<NOP; j++) {
if(at[i] > at[j]) {
int temp = at[i];
at[i] = at[j];
at[j] = temp;
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
}
}
}
printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");
for(sum=0, i = 0; y!=0; )
{
if(temp[i] <= quant && temp[i] > 0)
{
sum = sum + temp[i];
temp[i] = 0;
count=1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - quant;
sum = sum + quant;
}
if(temp[i]==0 && count==1)
{
y--;
printf("Process No[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
wt = wt + sum - at[i] - bt[i];
tat = tat + sum - at[i];
count = 0;
}
i = (i + 1) % NOP;
}
avg_wt = (float)wt / NOP;
avg_tat = (float)tat / NOP;
printf("\nAverage Turn Around Time: %.2f", avg_tat);
printf("\nAverage Waiting Time: %.2f\n", avg_wt);
return 0;
}  
