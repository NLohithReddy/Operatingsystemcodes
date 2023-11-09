#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hPipe;
    char buffer[100];
    DWORD bytesRead;

    
    hPipe = CreateNamedPipe(
        "\\\\.\\pipe\\MyPipe",  
        PIPE_ACCESS_DUPLEX,     
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE, 
        1,                       
        0,                       
        0,                       
        0,                       
        NULL                     
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Failed to create named pipe. Error code: %d\n", GetLastError());
        return 1;
    }

    printf("Waiting for client to connect...\n");

    
    if (ConnectNamedPipe(hPipe, NULL)) {
        printf("Client connected.\n");

       
        if (ReadFile(hPipe, buffer, sizeof(buffer), &bytesRead, NULL)) {
            printf("Received message from client: %s\n", buffer);
        } else {
            fprintf(stderr, "Failed to read from pipe. Error code: %d\n", GetLastError());
        }

       
        CloseHandle(hPipe);
    } else {
        fprintf(stderr, "Failed to connect to client. Error code: %d\n", GetLastError());
    }

    return 0;
}

