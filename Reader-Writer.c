#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
DIR *directory;
struct dirent *entry;

// Open the current directory
directory = opendir(".");

if (directory == NULL) {
perror("Unable to open directory");
return EXIT_FAILURE;
}

// Read directory entries
while ((entry = readdir(directory)) != NULL) {
printf("%s\n", entry->d_name);
}

// Close the directory
closedir(directory);

return EXIT_SUCCESS;
}
