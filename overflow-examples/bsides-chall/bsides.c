#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char* name;
    void (*callbackFn)();
} Callback, *PCallback;

int initialize(PCallback pCallback, char* functionName, void* functionAddr)
{
    pCallback->callbackFn = functionAddr;
    pCallback->name = (char*)malloc(sizeof(char) * 255);
    strcpy(pCallback->name, functionName);
}

int callFunction(PCallback pCallback, size_t callbackSize, char* inputBuffer)
{
    for(size_t i = 0; i < callbackSize; i++) {
        if(!strcmp(inputBuffer, pCallback[i].name)) {
            pCallback[i].callbackFn();
            return 0;
        }
    }

    return 1;
}

void read_banner(char* filename)
{
    FILE* hFile = fopen(filename, "r");
    
    if (!hFile) {
        perror("Error opening file");
        return;
    }

    size_t bufferSize = 1024;
    char *buffer = (char*)malloc(bufferSize);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(hFile);
        return;
    }

    size_t length = 0;
    int c;

    while ((c = fgetc(hFile)) != EOF) {
        buffer[length++] = c;

        if (length >= bufferSize - 1) {
            bufferSize *= 2;
            buffer = (char*)realloc(buffer, bufferSize);
            if (!buffer) {
                perror("Error reallocating memory");
                fclose(hFile);
                return;
            }
        }
    }
    buffer[length] = '\0';

    printf("%s\n", buffer);

    free(buffer);
    fclose(hFile);
}

void remote()
{
    printf("Calling remote...");
    system("/bin/bash");
}

void sendmail()
{
    // Not implemented yet
    printf("Sendmail...\n");
}

void readmail()
{
    // Not implemented yet
    printf("Reading mail...\n");
}

int main()
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    size_t inputBufferSize = 50;
    char* inputBuffer = (char*)malloc(inputBufferSize * sizeof(char));

    char *filename = (char*)malloc(255 * sizeof(char));
    strcpy(filename, "./banner.txt");

    size_t callbackSize = 2;
    PCallback pCallback = (PCallback)malloc(sizeof(Callback) * callbackSize);

    initialize(&pCallback[0], "sendmail", &sendmail);
    initialize(&pCallback[1], "readmail", &readmail);

    while(1) {
        read_banner(filename);

        printf("Functions available:\nsendmail\nreadmail\n\n> ");

        if(fgets(inputBuffer, MAX_BUFFER_SIZE, stdin) == NULL) {
            printf("Error\n");
            continue;
        }

        inputBuffer[strlen(inputBuffer) - 1] = '\0';

        if(callFunction(pCallback, callbackSize, inputBuffer)) {
            printf("Invalid function\n");
            continue;
        }
    }
}
