#include <stdio.h>
#include <string.h>
#include "taskHandling.h"

int checkIfExists(char *title){
    FILE *file;
    if ((file = fopen(title, "r")))
    {
        fclose(file);
        return 1;
    }
     return 0;
}

int makeFile(){
    char title[200];
    char description[300];

    printf("Enter the title of the task: ");
    scanf("%s", title);
    printf("\nEnter the description of this task: ");
    scanf(" %[^\n]s", description);
    printf("\n");

    if(checkIfExists(title) == 0){
        FILE *task;
        char fileName[sizeof(title) + 4];
        strcpy(fileName, title);
        strcat(fileName, ".txt");

        task = fopen(fileName, "w");
        fprintf(task, "%s\n\n%s", title, description);
        fclose(task);
    }
    else {
        printf("A task with this title already exists.");
    }
    return 0;
}

int openTask(){
    char title[200], c;
    printf("Enter the title of the task: ");
    scanf("%s", title);
    char fileName[sizeof(title) + 4];

    if(checkIfExists(fileName) == 1){
        printf("File does not exist.");
        return -1;
    } else {
        FILE *file;
        strcpy(fileName, title);
        strcat(fileName, ".txt");
        file = fopen(fileName, "r");
        c = fgetc(file);
        while (c != EOF){
            printf("%c", c);
            c = fgetc(file);
        }
        fclose(file);
    }
}
