#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
} Process;

void fcfsScheduling(Process processes[], int n) {
    int currentTime = 0;

    printf("Process Execution Order:\n");

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        printf("Executing Process %d from time %d to %d\n", processes[i].id, currentTime, currentTime + processes[i].burstTime);
        currentTime += processes[i].burstTime;
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    fcfsScheduling(processes, n);

    return 0;
}

