#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int isCompleted;
} Process;

void sjnScheduling(Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    printf("Process Execution Order:\n");

    while (completedProcesses < n) {
        int shortestIndex = -1;
        int shortestBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!processes[i].isCompleted && processes[i].arrivalTime <= currentTime && processes[i].burstTime < shortestBurst) {
                shortestBurst = processes[i].burstTime;
                shortestIndex = i;
            }
        }

        if (shortestIndex != -1) {
            printf("Executing Process %d from time %d to %d\n", processes[shortestIndex].id, currentTime, currentTime + processes[shortestIndex].burstTime);
            currentTime += processes[shortestIndex].burstTime;
            processes[shortestIndex].isCompleted = 1;
            completedProcesses++;
        } else {
            currentTime++;
        }
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
        processes[i].isCompleted = 0;
    }

    sjnScheduling(processes, n);

    return 0;
}
 
