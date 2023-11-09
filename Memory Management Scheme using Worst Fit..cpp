#include <stdio.h>

#define MAX_BLOCKS 10

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_BLOCKS];
    for (int i = 0; i < MAX_BLOCKS; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int worstIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1) {
                    worstIndex = j;
                } else if (blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {
            allocation[worstIndex] = i;
            blockSize[worstIndex] -= processSize[i];
            printf("Process %d of size %d allocated to block %d\n", i, processSize[i], worstIndex);
        } else {
            printf("Process %d of size %d cannot be allocated\n", i, processSize[i]);
        }
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, m, processSize, n);

    return 0;
}

