#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int calculateHeadMovement(int queue[], int head, int size) {
int totalMovement = 0;
int i;
for (i = 0; i < size; i++) {
totalMovement += abs(queue[i] - head);
head = queue[i];
}
return totalMovement;
}
int main() {
int n; 
printf("Enter the number of disk requests: ");
scanf("%d", &n);
int requestQueue[n];
printf("Enter the disk request queue:\n");
int i;
for (i = 0; i < n; i++) {
scanf("%d", &requestQueue[i]);
}
int initialHead;
printf("Enter the initial position of the head: ");
scanf("%d", &initialHead);
int totalHeadMovement = calculateHeadMovement(requestQueue, initialHead, n);
printf("Total head movement: %d\n", totalHeadMovement);
return 0;
}

