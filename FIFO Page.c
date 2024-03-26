#include <stdio.h>
#include <stdlib.h>
#define PAGE_FRAMES 3
int main() {
int page_frames[PAGE_FRAMES];
int page_faults = 0;
int page_count;
int oldest_index = 0; // Index of the oldest page in the page frames
printf("Enter the number of pages: ");
scanf("%d", &page_count);
int pages[page_count];
printf("Enter the page reference string: ");
int i;
for (i = 0; i < page_count; i++) {
scanf("%d", &pages[i]);
}
// Initialize page frames to -1 (indicating empty)
for (i = 0; i < PAGE_FRAMES; i++) {
page_frames[i] = -1;
}
// Simulate FIFO paging
for (i = 0; i < page_count; i++) {
int page = pages[i];
int found = 0;
// Check if page is already in page frame
int j;
for (j = 0; j < PAGE_FRAMES; j++) {
if (page_frames[j] == page) {
found = 1;
break;
}
}
// Page fault: Replace the oldest page
if (!found) {
page_frames[oldest_index] = page;
oldest_index = (oldest_index + 1) % PAGE_FRAMES; // Update oldest page index
page_faults++;
}
// Print current state of page frames
printf("Page frames after reference %d: ", page);
for (j = 0; j < PAGE_FRAMES; j++) {
printf("%d ", page_frames[j]);
}
printf("\n");
}

printf("Total page faults: %d\n", page_faults);

return 0;
}

