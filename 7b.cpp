#include <stdio.h>

#define MAX_BLOCKS 10

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_BLOCKS];
    for (int i = 0; i < MAX_BLOCKS; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[j] = i;
                blockSize[j] -= processSize[i];
                printf("Process %d of size %d allocated to block %d\n", i, processSize[i], j);
                break;
            }
        }
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);

    return 0;
}

