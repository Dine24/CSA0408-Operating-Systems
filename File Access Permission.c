#include <stdio.h>
#include <sys/stat.h>

int main() {
    // Change permissions of a file (example.txt) to read and write for the owner
    chmod("example.txt", S_IRUSR | S_IWUSR);

    printf("File permissions changed successfully!\n");
    return 0;
}

