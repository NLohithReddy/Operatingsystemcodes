#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int burstTime;
    int priority;
} Process;

void priorityScheduling(Process processes[], int n) {
    // Sort processes based on priority in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                // Swap processes[j] and processes[j + 1]
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;

    printf("Process Execution Order:\n");

    for (int i = 0; i < n; i++) {
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
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    priorityScheduling(processes, n);

    return 0;
}

