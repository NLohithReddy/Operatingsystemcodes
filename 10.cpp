#include <stdio.h>

int main() {
    int choice;
    char filename[100];
    FILE *file;

    while (1) {
        printf("\nFile Management Menu:\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Write to a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                file = fopen(filename, "w");
                if (file == NULL) {
                    printf("File creation failed.\n");
                } else {
                    printf("File created successfully.\n");
                    fclose(file);
                }
                break;

            case 2:
                printf("Enter the filename to read: ");
                scanf("%s", filename);
                file = fopen(filename, "r");
                if (file == NULL) {
                    printf("File not found.\n");
                } else {
                    char ch;
                    printf("File content:\n");
                    while ((ch = fgetc(file)) != EOF) {
                        putchar(ch);
                    }
                    fclose(file);
                }
                break;

            case 3:
                printf("Enter the filename to write: ");
                scanf("%s", filename);
                file = fopen(filename, "a");
                if (file == NULL) {
                    printf("File not found.\n");
                } else {
                    char data[100];
                    printf("Enter data to write: ");
                    scanf(" %[^\n]s", data);
                    fprintf(file, "%s\n", data);
                    printf("Data written to the file.\n");
                    fclose(file);
                }
                break;

            case 4:
                printf("Enter the filename to delete: ");
                scanf("%s", filename);
                if (remove(filename) == 0) {
                    printf("File deleted successfully.\n");
                } else {
                    printf("File deletion failed.\n");
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

