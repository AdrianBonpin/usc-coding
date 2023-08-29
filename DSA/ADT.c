#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int* data;
    int length;
}LIST, *LISTv2;

// For Version 1

void initalizeList(LIST *L) {
    L->data = (int*)malloc(MAX * sizeof(int));
    L->length = 0;
}

void print ( LIST *L ) {
    int i;
    for ( i = 0 ; i < L->length ; i++ ) {
        printf("%d\n", L->data[i]);
    }
    printf("\n\n");
}

void insert ( int data, LIST *L ) {
    if ( L->length < MAX ) {
        L->data[L->length++] = data;
    }
}

void insertPos (int data, int pos, LIST *L) {
    if ( pos <= L->length && L->length < MAX ) {
        memmove(&(L->data[pos]), &(L->data[pos-1]), (L->length++ - pos + 1) * sizeof(int));
        L->data[pos-1] = data;
    } else {
        insert(data, L);
    }
}

void delPos (int pos, LIST *L) {
    if ( pos <= L->length ) {
        memmove(&(L->data[pos-1]), &(L->data[pos]), (L->length-- - pos + 1) * sizeof(int));
    }
}

void main () {
    LIST L;
    initalizeList(&L);

    insert(1, &L);
    insert(2, &L);
    insert(3, &L);

    print(&L);

    insertPos(4, 7, &L);

    insert(5, &L);

    print(&L);

    delPos(2, &L);

    print(&L);

    LISTv2 Lv2;
}