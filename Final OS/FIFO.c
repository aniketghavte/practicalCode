#include <stdio.h>

#define MAX_FRAMES 10

void displayPageFrames(int frames[], int n) {
    printf("Page Frames: ");
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf("| ");
        else
            printf("| %d ", frames[i]);
    }
    printf("|\n");
}

int isPageInFrames(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}

int getPageIndex(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int currentIndex = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        printf("\nReference to Page %d:\n", pages[i]);
        if (!isPageInFrames(frames, capacity, pages[i])) {
            frames[currentIndex] = pages[i];
            currentIndex = (currentIndex + 1) % capacity;
            pageFaults++;
        }
        displayPageFrames(frames, capacity);
    }

    printf("\nNumber of Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the sequence of pages:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of page frames: ");
    scanf("%d", &capacity);

    fifoPageReplacement(pages, n, capacity);

    return 0;
}
