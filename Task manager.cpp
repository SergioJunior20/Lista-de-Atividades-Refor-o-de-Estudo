#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DESCRIPTION_SIZE 100

typedef struct Task {
    int id;
    char description[MAX_DESCRIPTION_SIZE];
    struct Task* prox;
} TASK;

TASK* pendingQueueHead = NULL;
TASK* pendingQueueTail = NULL;
TASK* completedListHead = NULL;
TASK* draftStackTop = NULL;


TASK* createTask(int id, char* description);
TASK* createTaskByScanf();


void addToCompletedList(TASK* newTask);
TASK* removeFromCompletedListByItsId(int id);
void seeAllCompletedList();


void putToPendingQueue(TASK* newTask);
TASK* getFromPendingQueue();
void seeAllPendingQueue();


void pushToDraftStack(TASK* newTask);
TASK* popFromDraftStack();
void seeAllDraftStack();


void displayMenu();

int main() {
    int choice;
    printf("################# TASK MANAGER SYSTEM #################");

    do {
        displayMenu();
        printf("Choose an option:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                           
                TASK* newTask = createTaskByScanf();                
                putToPendingQueue(newTask);
            }
            break;
            
            case 2:
                
                seeAllPendingQueue();
                break;

            case 3:
                
                {
                    TASK* firstTask = getFromPendingQueue();
                    if (firstTask != NULL) {
                        addToCompletedList(firstTask);
                    }
                }
                break;

            case 4:
                
                seeAllCompletedList();
                break;

            case 5:
            {
                int id;
                printf("Enter Task ID (number):");
                scanf("%d", &id);

                TASK* task = removeFromCompletedListByItsId(id);
                if(task != NULL) {
                    pushToDraftStack(task);
                }
            }
            break;
            
            case 6:
                seeAllDraftStack();
                break;

            case 7:
            {
                TASK* lastTask = popFromDraftStack();
                if(lastTask != NULL) {
                    putToPendingQueue(lastTask);
                }
            }
            break;
            
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);

    printf("################# SYSTEM SHUT DOWN #################");
}

TASK* createTask(int id, char* description) {
    TASK* newTask = (TASK*) malloc(sizeof(TASK));

    newTask->id = id;
    strcpy(newTask->description, description);
    newTask->prox = NULL;

    return newTask;
}

TASK* createTaskByScanf() {
    int id;
    char description[MAX_DESCRIPTION_SIZE];

    printf("Enter Task ID (number): ");
    scanf("%d", &id);

    getchar();
    printf("Enter Task Description (string): ");

    fgets(description, MAX_DESCRIPTION_SIZE, stdin);
    description[strcspn(description, "\n")] = '\0';

    return createTask(id, description);
}


void addToCompletedList(TASK* newTask) {
    printf("Adding Task to Completed List\n");
    newTask -> prox = completedListHead;
    completedListHead = newTask;
}

TASK* removeFromCompletedListByItsId(int id) {
    printf("Removing Task from Completed List\n");
        TASK* current = completedListHead;;
        TASK* prev = NULL;
        while (current != NULL && current->id != id) {
            prev = current;
            current = current->prox;
        }
        if (current == NULL) {
            return NULL; 
        }
        if (prev == NULL) {
            completedListHead = current->prox;
        } else {
            prev->prox = current->prox;
        }
        return current;
    }

void seeAllCompletedList() {
    printf("Printing All Completed List\n");
        TASK* current = completedListHead;
        while (current != NULL) {
         printf("ID: %d, Description: %s\n", current->id, current->description);
            current = current->prox;
        }
    }


void putToPendingQueue(TASK* newTask) {
    printf("Putting Task to Pending Queue\n");
    
    if (pendingQueueHead == NULL) {
        pendingQueueHead = newTask;
        pendingQueueTail = newTask;
    } else {
        pendingQueueTail->prox = newTask;
        pendingQueueTail = newTask;
    }
}

TASK* getFromPendingQueue() {
    printf("Getting Task from Pending Queue\n");

    if (pendingQueueHead == NULL) {
        return NULL;
    }

    TASK* firstTask = pendingQueueHead;
    pendingQueueHead = pendingQueueHead -> prox;

    if (pendingQueueHead == NULL) {
        pendingQueueTail = NULL;
    }

    return firstTask;
}

void seeAllPendingQueue() {
    printf("Printing All Pending Queue\n");
    TASK* current = pendingQueueHead;
    while (current != NULL) {
        printf("ID: %d, Description: %s\n", current->id, current->description);
        current = current->prox;
    }
}


void pushToDraftStack(TASK* newTask) {
    printf("Pushing Task to Draft Stack\n");
    newTask -> prox = draftStackTop;
    draftStackTop = newTask;
}

TASK* popFromDraftStack() {
    printf("Popping Task to Draft Stack\n");

    if (draftStackTop == NULL) {
        return NULL;
    }
    TASK* topTask = draftStackTop;
    draftStackTop = draftStackTop -> prox;
    
    return topTask;
}

void seeAllDraftStack() {
    printf("Printing All Draft Stack\n");
    TASK* current = draftStackTop;
    while (current != NULL) {
        printf("ID: %d, Description: %s\n", current->id, current->description);
        current = current->prox;
    }
}


void displayMenu() {
    printf("\nMenu:\n");
    printf("1 - Create New Pending Task\n");
    printf("2 - See All Pending Tasks\n");
    printf("3 - Complete First Pending Task\n");
    printf("4 - See All Completed Tasks\n");
    printf("5 - Set Completed Task as Draft by its ID\n");
    printf("6 - See All Draft Tasks\n");
    printf("7 - Set Last Draft Task as Pending Task\n");
    printf("0 - Exit\n");
}
