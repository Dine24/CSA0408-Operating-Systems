#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char data[50];
};

int main() {
    struct Record records[MAX_RECORDS];
    int numRecords;

    printf("Enter the number of records: ");
    scanf("%d", &numRecords);
	int i;
    // Input records
    for (i = 0; i < numRecords; i++) {
        records[i].id = i + 1;
        printf("Enter data for record %d: ", i + 1);
        scanf("%s", records[i].data);
    }

    // Display records
    printf("\nRead Records:\n");
    for (i = 0; i < numRecords; i++) {
        printf("Read Record %d: %s\n", records[i].id, records[i].data);
    }

    // Simulate accessing a specific record
    int recordNumber;
    printf("\nEnter the record number to access: ");
    scanf("%d", &recordNumber);

    if (recordNumber >= 1 && recordNumber <= numRecords) {
        printf("Accessing record %d: %s\n", records[recordNumber - 1].id, records[recordNumber - 1].data);
    } else {
        printf("Invalid record number. Please enter a valid record number.\n");
    }

    return 0;
}

