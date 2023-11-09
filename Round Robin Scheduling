#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int burstTime;
    int remainingTime;
} Process;

void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    int currentTime = 0;
    int completedProcesses = 0;

    printf("Process Execution Order:\n");

    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                int executionTime = (processes[i].remainingTime > timeQuantum) ? timeQuantum : processes[i].remainingTime;
                printf("Executing Process %d from time %d to %d\n", processes[i].id, currentTime, currentTime + executionTime);
                currentTime += executionTime;
                processes[i].remainingTime -= executionTime;

                if (processes[i].remainingTime == 0) {
                    completedProcesses++;
                }
            }
        }
    }
}

int main() {
    int n, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}

