#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 20

struct User {
    char username[20];
    char files[MAX_FILES][20];
    int numFiles;
};

struct MasterDirectory {
    struct User users[MAX_USERS];
    int numUsers;
};

void addUser(struct MasterDirectory *mfd, const char *username) {
    if (mfd->numUsers >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }

    strcpy(mfd->users[mfd->numUsers].username, username);
    mfd->users[mfd->numUsers].numFiles = 0;
    mfd->numUsers++;
}

void addFile(struct MasterDirectory *mfd, const char *username, const char *filename) {
    for (int i = 0; i < mfd->numUsers; ++i) {
        if (strcmp(mfd->users[i].username, username) == 0) {
            if (mfd->users[i].numFiles >= MAX_FILES) {
                printf("User %s has reached the maximum file limit.\n", username);
                return;
            }
            strcpy(mfd->users[i].files[mfd->users[i].numFiles], filename);
            mfd->users[i].numFiles++;
            return;
        }
    }
    printf("User %s not found.\n", username);
}

void displayDirectory(const struct MasterDirectory *mfd) {
    printf("\nMaster File Directory:\n");
    for (int i = 0; i < mfd->numUsers; ++i) {
        printf("User: %s\n", mfd->users[i].username);
        printf("Files: ");
        for (int j = 0; j < mfd->users[i].numFiles; ++j) {
            printf("%s ", mfd->users[i].files[j]);
        }
        printf("\n");
    }
}

int main() {
    struct MasterDirectory mfd;
    mfd.numUsers = 0;

    addUser(&mfd, "alice");
    addUser(&mfd, "bob");

    addFile(&mfd, "alice", "file1.txt");
    addFile(&mfd, "alice", "file2.txt");
    addFile(&mfd, "bob", "notes.doc");

    displayDirectory(&mfd);

    return 0;
}
