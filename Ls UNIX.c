#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main() {
DIR *directory;
struct dirent *entry;
directory = opendir("C:\\Users\\tamil\\OneDrive\\Documents");
if (directory == NULL) {
perror("Unable to open directory");
return EXIT_FAILURE;
}

while ((entry = readdir(directory)) != NULL) {
printf("%s\n", entry->d_name);
}
closedir(directory);

return EXIT_SUCCESS;
}

