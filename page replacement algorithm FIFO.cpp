#include <stdio.h>

#define MAX_BLOCKS 10

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_BLOCKS];
    for (int i = 0; i < MAX_BLOCKS; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1) {
                    bestIndex = j;
                } else if (blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[bestIndex] = i;
            blockSize[bestIndex] -= processSize[i];
            printf("Process %d of size %d allocated to block %d\n", i, processSize[i], bestIndex);
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

    bestFit(blockSize, m, processSize, n);

    return 0;
}

