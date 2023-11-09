//offline
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Path to the file you want to retrieve information about
    char *file_path = "9312B.xlsx";

    // Declare a stat structure
    struct stat file_stat;

    // Use the stat system call to get information about the file
    if (stat(file_path, &file_stat) == 0) {
        printf("File Size: %lld bytes\n", (long long)file_stat.st_size);
        printf("Number of Links: %d\n", (int)file_stat.st_nlink);
        printf("File inode: %llu\n", (unsigned long long)file_stat.st_ino);
        // Add more fields from the stat structure as needed
    } else {
        perror("Error");
    }

    return 0;
}

