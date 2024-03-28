#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// File structure
struct File {
int id;
char name[MAX_FILENAME_LENGTH];
};

// Directory structure
struct Directory {
struct File *files;
int fileCount;
int maxSize;
};

// Function prototypes
void initializeDirectory(struct Directory *dir, int maxSize);
void addFile(struct Directory *dir, int fileId, const char *fileName);
void deleteFile(struct Directory *dir, int fileId);
void listFiles(const struct Directory *dir);
void clearInputBuffer();

int main() {
struct Directory dir;
int choice, fileId;
char fileName[MAX_FILENAME_LENGTH];

// Initialize directory with a maximum capacity of 100 files
initializeDirectory(&dir, 100);

// Menu
while (1) {
printf("\nSingle-Level Directory Operations\n");
printf("1. Add File\n");
printf("2. Delete File\n");
printf("3. List Files\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
clearInputBuffer(); // Clear input buffer

switch (choice) {
case 1:
printf("Enter file ID and name: ");
scanf("%d %s", &fileId, fileName);
clearInputBuffer(); // Clear input buffer
addFile(&dir, fileId, fileName);
break;
case 2:
printf("Enter file ID to delete: ");
scanf("%d", &fileId);
clearInputBuffer(); // Clear input buffer
deleteFile(&dir, fileId);
break;
case 3:
listFiles(&dir);
break;
case 4:
// Free dynamically allocated memory before exiting
free(dir.files);
exit(EXIT_SUCCESS);
default:
printf("Invalid choice\n");
clearInputBuffer(); // Clear input buffer
}
}

return 0;
}

// Initialize directory
void initializeDirectory(struct Directory *dir, int maxSize) {
dir->fileCount = 0;
dir->maxSize = maxSize;
dir->files = (struct File *)malloc(maxSize * sizeof(struct File));
if (dir->files == NULL) {
printf("Memory allocation failed\n");
exit(EXIT_FAILURE);
}
}

// Add file to directory
void addFile(struct Directory *dir, int fileId, const char *fileName) {
if (dir->fileCount < dir->maxSize) {
struct File *file = &(dir->files[dir->fileCount]);
file->id = fileId;
strncpy(file->name, fileName, MAX_FILENAME_LENGTH - 1);
file->name[MAX_FILENAME_LENGTH - 1] = '\0'; // Ensure null-terminated string
printf("File '%s' added with ID %d\n", fileName, fileId);
dir->fileCount++;
} else {
printf("Cannot add file. Directory is full.\n");
}
}

// Delete file from directory
void deleteFile(struct Directory *dir, int fileId) {
int i, found = 0;
for (i = 0; i < dir->fileCount; i++) {
if (dir->files[i].id == fileId) {
printf("File '%s' with ID %d deleted\n", dir->files[i].name, fileId);
found = 1;
break;
}
}

if (found) {
int j;
for (j = i; j < dir->fileCount - 1; j++) {
dir->files[j] = dir->files[j + 1];
}
dir->fileCount--;
} else {
printf("File with ID %d not found\n", fileId);
}
}

// List all files in directory
void listFiles(const struct Directory *dir) {
if (dir->fileCount == 0) {
printf("No files in directory\n");
} else {
printf("Files in Directory:\n");
int i;
for (i = 0; i < dir->fileCount; i++) {
printf("File ID: %d, Name: %s\n", dir->files[i].id, dir->files[i].name);
}
}
}

// Function to clear input buffer
void clearInputBuffer() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}
