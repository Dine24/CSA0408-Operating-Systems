#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trimNewline(char* string) {
size_t length = strlen(string);
if (length > 0 && string[length - 1] == '\n') {
string[length - 1] = '\0';
}
}
int main() {
FILE *fptr1, *fptr2;
char readPath[1000], writePath[1000], readFilename[100], writeFilename[100];
char readFullPath[1100], writeFullPath[1100];
// For reading
printf("Enter the full directory path to open for reading (e.g., C:\\Users\\YourUsername\\Desktop):\n");
fgets(readPath, sizeof(readPath), stdin);
trimNewline(readPath); // Remove the newline character
printf("Enter the filename to open for reading:\n");
fgets(readFilename, sizeof(readFilename), stdin);
trimNewline(readFilename); // Remove the newline character
snprintf(readFullPath, sizeof(readFullPath), "%s\\%s", readPath, readFilename);
fptr1 = fopen(readFullPath, "r");
if (fptr1 == NULL) {
printf("Cannot open file %s\n", readFullPath);
exit(0);
}
// For writing
printf("Enter the full directory path to open for writing (e.g., C:\\Users\\YourUsername\\Desktop):\n");
fgets(writePath, sizeof(writePath), stdin);
trimNewline(writePath); // Remove the newline character
printf("Enter the filename to open for writing:\n");
fgets(writeFilename, sizeof(writeFilename), stdin);
trimNewline(writeFilename); // Remove the newline character
snprintf(writeFullPath, sizeof(writeFullPath), "%s\\%s", writePath, writeFilename);
fptr2 = fopen(writeFullPath, "w");
if (fptr2 == NULL) {
printf("Cannot open file %s\n", writeFullPath);
exit(0);
}
// Copying contents
char c = fgetc(fptr1);
while (c != EOF) {
fputc(c, fptr2);
c = fgetc(fptr1);
}
printf("\nContents copied to %s\n", writeFullPath);
fclose(fptr1);
fclose(fptr2);
return 0;
}

