#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3 // Number of frames in memory

// Function to find the optimal page to replace
int optimalPage(int pages[], int numOfPages, int frames[], int numOfFrames, int index) {
int res = -1, farthest = index;
int i;
for (i = 0; i < numOfFrames; i++) {
int j;
for (j = index; j < numOfPages; j++) {
if (frames[i] == pages[j]) {
if (j > farthest) {
farthest = j;
res = i;
}
break;
}
}
if (j == numOfPages)
return i;
}
return (res == -1) ? 0 : res;
}

// Function to simulate optimal paging
void optimalPaging(int pages[], int numOfPages, int numOfFrames) {
int frames[numOfFrames], pageFaults = 0;
bool isPageFault;
int i;
for (i = 0; i < numOfFrames; i++)
frames[i] = -1;

for (i = 0; i < numOfPages; i++) {
isPageFault = true;
int j;
for (j = 0; j < numOfFrames; j++) {
if (frames[j] == pages[i]) {
isPageFault = false;
break;
}
}

if (isPageFault) {
int index = optimalPage(pages, numOfPages, frames, numOfFrames, i + 1);
frames[index] = pages[i];
pageFaults++;
}
}

printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
int numOfPages, numOfFrames;

printf("Enter the number of pages: ");
scanf("%d", &numOfPages);

printf("Enter the number of frames: ");
scanf("%d", &numOfFrames);

int pages[numOfPages];

printf("Enter the sequence of page references:\n");
int i;
for (i = 0; i < numOfPages; i++)
scanf("%d", &pages[i]);

optimalPaging(pages, numOfPages, numOfFrames);

return 0;
}

