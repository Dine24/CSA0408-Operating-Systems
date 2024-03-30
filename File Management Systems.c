#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a new file and write data to it
    FILE *file = fopen("my_file.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Hello, this is some text written to the file.\n");
    fclose(file);
    printf("File created and data written successfully.\n");

    // Open the file for reading
    file = fopen("my_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Read data from the file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read from file: %s", buffer);
    }
    fclose(file);

    // Append more data to the file
    file = fopen("my_file.txt", "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Appending additional text to the file.\n");
    fclose(file);
    printf("Data appended successfully.\n");

    // Delete the file
    if (remove("my_file.txt") == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }

    return 0;
}

