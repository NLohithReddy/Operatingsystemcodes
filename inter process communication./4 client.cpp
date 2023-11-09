#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hPipe;
    char message[] = "Hello, Pipe Server!";
    DWORD bytesWritten;

   
    hPipe = CreateFile(
        "\\\\.\\pipe\\MyPipe",  
        GENERIC_WRITE,           
        0,                       
        NULL,                    
        OPEN_EXISTING,           
        0,                       
        NULL                     
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Failed to connect to the named pipe. Error code: %d\n", GetLastError());
        return 1;
    }

    
    if (WriteFile(hPipe, message, sizeof(message), &bytesWritten, NULL)) {
        printf("Message sent to server: %s\n", message);
    } else {
        fprintf(stderr, "Failed to write to pipe. Error code: %d\n", GetLastError());
    }

    
    CloseHandle(hPipe);

    return 0;
}

