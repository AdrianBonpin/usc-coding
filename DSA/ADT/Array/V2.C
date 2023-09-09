#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct List {
    int data[MAX];
    int count;
} *LIST;

// LIST points to a "LIST"

LIST initList () {
    LIST newList = (LIST)malloc(sizeof(struct List));
    newList->count = 0;
    return newList;
}

void insert ( int data, LIST L ) {
    if ( L->count < MAX ) {
        L->data[L->count++] = data;
    }
}

void print ( LIST L ) {
    printf("\n~ ~ ~ ~ ~\n");
    int i;
    for ( i = 0 ; i < L->count ; i++ ) {
        printf("[%d] - %d\n", i, L->data[i]);
    }
    printf("~ ~ ~ ~ ~\n");
}

void insPos ( int data, int pos, LIST L ) {
    if ( L->count < MAX ) {
        int i;
        for ( i = 0 ; i < pos && i < L->count ; i++) {}
        memcpy(L->data+i+1,L->data+i,sizeof(int) * (L->count++ - i + 1));
        L->data[i] = data;
    }
}

void delPos ( int pos, LIST L ) {
    if ( pos <= L->count && pos >= 0 ) {
        memcpy(L->data+pos,L->data+pos+1,sizeof(int) * (L->count-- - pos + 1));
    }
}

int main () {
    LIST L = initList();

    insert(1, L);
    insert(2, L);
    insert(4, L);
    insert(5, L);

    print(L);

    insPos(3, 2, L);

    insPos(6, 9, L);

    print(L);

    delPos(5,L);

    print(L);

    return 0;
}