#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linkedList {
    int number;
    struct linkedList *Next;
} list;

list *addNumber(int j, list *start) {
    list *new, *point;
    if((new = (list*)malloc(sizeof(list))) == NULL) {
        perror("Memorys reservation was unsuccessful\n");
        exit(0);
    }

    new->number = j;
    new->Next = NULL;

    if (start == NULL) {
        start = new;
    }

    else {
        point = start;
        while (point->Next != NULL){
            point = point->Next;
        }
        point->Next = new;
    }

    return start;
} 

void printList(list *start) {
    list *point;
    if (start == NULL) {
        printf("The list is empty.");
    }
    else {
        for(point = start; point != NULL; point = point->Next) {
            printf("%d ", point->number);
        }
        printf("\n");
    }
}

list *freeMemory(list *start) {
    list *point = start;
    while (point != NULL) {
        start = point->Next;
        free(point);
        point = start;
    }
    return start;
}

void deleteElement(list *start){ //delete element with key 6
    list *point, *prev = NULL;
    point = start;
    while (point->number != 6 || point == NULL){
        prev = point;
        point = point->Next; 
    }
    prev->Next = point->Next;
    free(point);
}

void deleteSecondLast(list *start) {
    list *point = start, *prev = NULL, *prev2 = NULL;

    while(point->Next != NULL) {
        prev2 = prev;
        prev = point;
        point = point->Next;
    }

    prev2->Next = point;
    free(prev);
}

int main(void) {
    list *start = NULL;
    int i = 1, j;
    printf("Give numbers, 0 ends:\n");
    while(j != 0) {
        scanf("%d", &j);
        if(j != 0) {
            start = addNumber(j, start);
        }
    }

    while (i != 0) {
        printf("1) Delete the element with key 6\n2) Delete second last element\n3) Print list\n0) End the program\nNumber: ");
        scanf("%d", &i);
    
        if (i == 1) {
            deleteElement(start);
        }
        else if (i == 2) {
            deleteSecondLast(start);
        }
        else if (i == 3) {
            printList(start);
        }
    }
    freeMemory(start);
}