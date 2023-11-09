#include <stdio.h>

#define SIZE 3 // Number of frames

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("X ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int pages[] = {0, 1, 2, 3, 0, 4, 1, 0, 2, 3, 4}; // Reference string
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[SIZE];
    int used[SIZE];
    for (int i = 0; i < SIZE; i++) {
        frames[i] = -1;
        used[i] = 0;
    }
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < SIZE; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int replaced = 0;
            for (int j = 0; j < SIZE; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    used[j] = i;
                    replaced = 1;
                    break;
                }
            }
            if (!replaced) {
                int idx = 0;
                for (int j = 1; j < SIZE; j++) {
                    if (used[j] < used[idx]) {
                        idx = j;
                    }
                }
                frames[idx] = pages[i];
                used[idx] = i;
            }
            pageFaults++;
        }
        printf("Page %d: ", pages[i]);
        printFrames(frames, SIZE);
    }
    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}

