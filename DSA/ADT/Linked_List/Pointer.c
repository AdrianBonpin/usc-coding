#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data;
    int *next;
} ltype;

typedef struct {
    ltype node[MAX];
    int avail;
}virHeap;

typedef virHeap *LIST;

LIST initList() {
    LIST new = (LIST)malloc(sizeof(virHeap));
    new->avail = 0;
    return new;
}

void main() {
    LIST L = initList();
    printf("%d\n",L->avail);
}