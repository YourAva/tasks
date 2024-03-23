#include <stdio.h>
#include "taskHandling.h"

int main(){
    int decision;
    printf("What do you wish to do?:\n1 - Open a task\n2 - Create a task\n0 - Exit\n");
    scanf("%d", &decision);
    switch(decision){
        case 1:
            openTask();
            break;
        case 2:
            makeFile();
            break;
        default:
            printf("Exiting program...");
    }
}
