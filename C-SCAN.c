#include <stdio.h>
#include <stdlib.h>

void C_SCAN(int requests[], int numRequests, int initialHead, int maxRange) {
    int totalSeekCount = 0;
    int currentTrack = initialHead;
	int i;
	int j;
    // Sort requests in ascending order
    for (i = 0; i < numRequests - 1; i++) {
        for (j = i + 1; j < numRequests; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Move in the right direction
    for (i = 0; i < numRequests; i++) {
        int requestedTrack = requests[i];
        int seekDistance = abs(requestedTrack - currentTrack);
        totalSeekCount += seekDistance;
        currentTrack = requestedTrack;
    }

    // Move back to the beginning (circular fashion)
    totalSeekCount += maxRange - currentTrack;

    printf("Total number of seek operations = %d\n", totalSeekCount);
}

int main() {
    int requests[] = {60, 79, 92, 114, 176, 199, 0, 11, 34, 41};
    int numRequests = sizeof(requests) / sizeof(requests[0]);
    int initialHead = 50;
    int maxRange = 199;

    C_SCAN(requests, numRequests, initialHead, maxRange);
    return 0;
}

