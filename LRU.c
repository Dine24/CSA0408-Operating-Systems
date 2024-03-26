#include <stdio.h>
#include <stdlib.h>

#define PAGE_FRAMES 3

int main() {
int page_frames[PAGE_FRAMES];
int page_faults = 0;
int pages[] = {1, 3, 0, 3, 5, 6, 3}; // Reference string
int page_count = sizeof(pages) / sizeof(pages[0]);

// Initialize page frames to -1 (indicating empty)
int i;
for (i = 0; i < PAGE_FRAMES; i++) {
page_frames[i] = -1;
}

// Simulate LRU paging
for (i = 0; i < page_count; i++) {
int page = pages[i];
int found = 0;

// Check if page is already in page frame
int j;
for (j = 0; j < PAGE_FRAMES; j++) {
if (page_frames[j] == page) {
found = 1;
// Update the page's position in page_frames (move to front)
int k;
for (k = j; k > 0; k--) {
page_frames[k] = page_frames[k - 1];
}
page_frames[0] = page;

break;
}
}

// Page fault: Replace the least recently used page
if (!found) {
// Move all pages one step forward to make space for the new page
for (j = PAGE_FRAMES - 1; j > 0; j--) {
page_frames[j] = page_frames[j - 1];
}
page_frames[0] = page;
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

