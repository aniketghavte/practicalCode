#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void cLook(int requests[], int n, int initialPosition) {
    int totalHeadMovement = 0;

    // Sorting the requests in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                // Swap
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Finding the index where the initial position should be inserted
    int insertIndex = 0;
    while (insertIndex < n && requests[insertIndex] < initialPosition) {
        insertIndex++;
    }

    // Perform C-LOOK algorithm
    for (int i = insertIndex; i < n; i++) {
        totalHeadMovement += abs(requests[i] - initialPosition);
        initialPosition = requests[i];
    }

    // Move the head to the beginning and continue C-LOOK
    for (int i = 0; i < insertIndex; i++) {
        totalHeadMovement += abs(requests[i] - initialPosition);
        initialPosition = requests[i];
    }

    printf("Total Head Movement (C-LOOK): %d\n", totalHeadMovement);
}

int main() {
    int n, initialPosition;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_REQUESTS) {
        printf("Invalid number of disk requests.\n");
        return 1;
    }

    int requests[MAX_REQUESTS];

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &initialPosition);

    cLook(requests, n, initialPosition);

    return 0;
}
