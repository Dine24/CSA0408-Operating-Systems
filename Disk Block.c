#include <stdio.h>
#include <stdlib.h>

// Node structure for a block in the linked list
struct Block {
    int data;
    struct Block* next;
};

// Function to display the blocks in the file
void displayBlocks(struct Block* head) {
    printf("File Blocks: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Block* head = NULL;
    struct Block* current = NULL;
    int fileSize, blockCount;

    printf("Enter the size of the file: ");
    scanf("%d", &fileSize);

    printf("Enter the number of blocks: ");
    scanf("%d", &blockCount);
	int i;
    // Creating the linked list representing the file
    for (i = 0; i < blockCount; i++) {
        struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
        newBlock->data = i;
        newBlock->next = NULL;

        if (head == NULL) {
            head = newBlock;
            current = newBlock;
        } else {
            current->next = newBlock;
            current = newBlock;
        }
    }

    // Displaying the allocated blocks
    displayBlocks(head);

    return 0;
}
