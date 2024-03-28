#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MEMORY_SIZE 100

// Memory block structure
struct MemoryBlock {
int id;         // Process ID
int size;       // Size of the memory block
int allocated;  // Flag to indicate whether the block is allocated or free
};

// Function prototypes
void initializeMemory(struct MemoryBlock memory[], int size);
void printMemory(struct MemoryBlock memory[], int size);
void allocateFirstFit(struct MemoryBlock memory[], int size, int pid, int requestSize);
void allocateBestFit(struct MemoryBlock memory[], int size, int pid, int requestSize);
void allocateWorstFit(struct MemoryBlock memory[], int size, int pid, int requestSize);

int main() {
struct MemoryBlock memory[MEMORY_SIZE];
int choice, pid, requestSize;

// Initialize memory
initializeMemory(memory, MEMORY_SIZE);

// Menu
while (1) {
printf("\nMemory Allocation Strategies\n");
printf("1. First Fit\n");
printf("2. Best Fit\n");
printf("3. Worst Fit\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter process ID and size: ");
scanf("%d %d", &pid, &requestSize);
allocateFirstFit(memory, MEMORY_SIZE, pid, requestSize);
break;
case 2:
printf("Enter process ID and size: ");
scanf("%d %d", &pid, &requestSize);
allocateBestFit(memory, MEMORY_SIZE, pid, requestSize);
break;
case 3:
printf("Enter process ID and size: ");
scanf("%d %d", &pid, &requestSize);
allocateWorstFit(memory, MEMORY_SIZE, pid, requestSize);
break;
case 4:
exit(EXIT_SUCCESS);
default:
printf("Invalid choice\n");
}

// Print memory after allocation
printMemory(memory, MEMORY_SIZE);
}

return 0;
}

// Initialize memory blocks as free
void initializeMemory(struct MemoryBlock memory[], int size) {
int i;
for (i = 0; i < size; i++) {
memory[i].id = -1;
memory[i].size = 0;
memory[i].allocated = 0;
}
}

// Print memory blocks
void printMemory(struct MemoryBlock memory[], int size) {
printf("\nMemory Blocks:\n");
printf("%-8s %-8s %-8s %-12s\n", "Block", "ID", "Size", "Allocated");
int i;
for (i = 0; i < size; i++) {
printf("%-8d %-8d %-8d %-12s\n", i, memory[i].id, memory[i].size,
memory[i].allocated ? "Allocated" : "Free");
}
}

// Allocate memory using First Fit strategy
void allocateFirstFit(struct MemoryBlock memory[], int size, int pid, int requestSize) {
int allocated = 0;
int i;
for (i = 0; i < size; i++) {
if (!memory[i].allocated && memory[i].size >= requestSize) {
memory[i].id = pid;
memory[i].allocated = 1;
allocated = 1;
break;
}
}
if (!allocated)
printf("Memory allocation failed for process %d with size %d\n", pid, requestSize);
}

// Allocate memory using Best Fit strategy
void allocateBestFit(struct MemoryBlock memory[], int size, int pid, int requestSize) {
int bestFitIndex = -1;
int minFragmentation = INT_MAX;
int i;
for (i = 0; i < size; i++) {
if (!memory[i].allocated && memory[i].size >= requestSize) {
int fragmentation = memory[i].size - requestSize;
if (fragmentation < minFragmentation) {
minFragmentation = fragmentation;
bestFitIndex = i;
}
}
}

if (bestFitIndex != -1) {
memory[bestFitIndex].id = pid;
memory[bestFitIndex].allocated = 1;
} else {
printf("Memory allocation failed for process %d with size %d\n", pid, requestSize);
}
}

// Allocate memory using Worst Fit strategy
void allocateWorstFit(struct MemoryBlock memory[], int size, int pid, int requestSize) {
int worstFitIndex = -1;
int maxFragmentation = INT_MIN;
int i;
for (i = 0; i < size; i++) {
if (!memory[i].allocated && memory[i].size >= requestSize) {
int fragmentation = memory[i].size - requestSize;
if (fragmentation > maxFragmentation) {
maxFragmentation = fragmentation;
worstFitIndex = i;
}
}
}

if (worstFitIndex != -1) {
memory[worstFitIndex].id = pid;
memory[worstFitIndex].allocated = 1;
} else {
printf("Memory allocation failed for process %d with size %d\n", pid, requestSize);
}
}
