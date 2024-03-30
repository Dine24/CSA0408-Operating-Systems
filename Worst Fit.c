#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 100

struct memory_block {
int size;
int allocated;
};

void worstFit(struct memory_block mem[], int n, int process_size) {
int i, worstFitIdx = -1;
for (i = 0; i < n; i++) {
if (!mem[i].allocated && mem[i].size >= process_size) {
if (worstFitIdx == -1 || mem[i].size > mem[worstFitIdx].size) {
worstFitIdx = i;
}
}
}
if (worstFitIdx != -1) {
mem[worstFitIdx].allocated = 1;
printf("Memory allocated successfully at position %d\n", worstFitIdx);
} else {
printf("No memory block available for allocation\n");
}
}

int main() {
int n, i, process_size;
printf("Enter the number of memory blocks: ");
scanf("%d", &n);

struct memory_block mem[MAX_MEMORY];

printf("Enter the size of each memory block:\n");
for (i = 0; i < n; i++) {
scanf("%d", &mem[i].size);
mem[i].allocated = 0;
}

printf("Enter the size of the process to be allocated: ");
scanf("%d", &process_size);

worstFit(mem, n, process_size);

return 0;
}

