#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

struct File {
    int indexBlock; // Index block pointer
    int numBlocks;  // Number of data blocks
};

int main() {
    struct File files[MAX_BLOCKS];
    int numFiles;

    printf("Enter the number of files: ");
    scanf("%d", &numFiles);
	int i;
    // Input file details
    for (i = 0; i < numFiles; i++) {
        printf("Enter the index block for file %d: ", i + 1);
        scanf("%d", &files[i].indexBlock);

        printf("Enter the number of data blocks for file %d: ", i + 1);
        scanf("%d", &files[i].numBlocks);
    }

    // Display file details
    printf("\nFile Details:\n");
    for (i = 0; i < numFiles; i++) {
        printf("File %d: Index Block %d, Data Blocks %d\n", i + 1, files[i].indexBlock, files[i].numBlocks);
    }

    // Simulate accessing a specific file
    int fileNumber;
    printf("\nEnter the file number to access: ");
    scanf("%d", &fileNumber);

    if (fileNumber >= 1 && fileNumber <= numFiles) {
        printf("Accessing File %d: Index Block %d, Data Blocks %d\n",
               fileNumber, files[fileNumber - 1].indexBlock, files[fileNumber - 1].numBlocks);
    } else {
        printf("Invalid file number. Please enter a valid file number.\n");
    }

    return 0;
}

