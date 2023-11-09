//online
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from the child process!\n");
        exit(0);
    } else {
        // Parent process
        printf("Hello from the parent process!\n");
        wait(&status); // Wait for the child process to finish
        printf("Child process finished.\n");
    }

    return 0;
}

