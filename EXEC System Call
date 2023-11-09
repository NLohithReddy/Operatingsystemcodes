//online
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Using the system call exec to execute the date command
    if (execl("/bin/date", "date", NULL) == -1) {
        perror("execl failed");
        return 1;
    }

    return 0;
}

