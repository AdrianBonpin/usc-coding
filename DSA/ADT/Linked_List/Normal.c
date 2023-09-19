#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
}*LIST, ltype;

void initList(LIST *L) {
    *L = NULL;
}

LIST node() {
    return (LIST)malloc(sizeof(ltype));
}

void insFirst(LIST *L, int data) {
    LIST new = node();
    new->data = data;
    new->next = *L;
    *L = new;
}

void insLast(LIST *L, int data) {
    LIST new = node();
    new->data = data;
    new->next = NULL;
    if (*L == NULL) {
        *L = new;
    } else {
        LIST current = *L;
        while ( current->next != NULL ) {
            current = current->next;
        }
        current->next = new;
    }
}

void insSorted(LIST *L, int data) {
    LIST new = node();
    new->data = data;
    new->next = NULL;
    if (*L == NULL || data <= (*L)->data) {
        new->next = *L;
        *L = new;
    } else {
        LIST current = *L;
        while (current->next != NULL && data > current->next->data) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

void print(LIST *L) {
    LIST current = *L;
    printf("\nList: ");
    while (current != NULL) {
        if (current->next != NULL) {
            printf("%d, ",current->data);
        }else {
            printf("%d",current->data);
        }
        current = current->next;
    }
    printf("\n\n");
}

LIST retrieve(LIST *L, int pos) {
    LIST current = *L;
    LIST last = NULL;
    int count = 0;
    while (current != NULL && count++ < pos) {
        last = current;
        current = current->next;
    }
    if (current == NULL) {
        return last;
    } else {
        return current;
    }
}

LIST delNode(LIST *L, int data) {
    LIST current = *L;
    LIST prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return NULL;
    } else if (prev == NULL) {
        *L = current->next;
    } else {
        prev->next = current->next;
    }
    return current;
}

void main() {
    LIST L;

    initList(&L);
    insFirst(&L, 4);
    insLast(&L, 6);
    insFirst(&L, 2);
    insLast(&L, 8);

    insSorted(&L, 5);
    insSorted(&L, 7);
    
    print(&L);

    printf("Data Retrieved: %d\n\n",retrieve(&L, 2)->data);

    printf("Data deleted: %d\n",delNode(&L, 7)->data);

    print(&L);

    printf("Data Retrieved: %d\n\n",retrieve(&L, 8)->data);

    printf("Data deleted: %d\n\n",delNode(&L, 2)->data);

    printf("Data deleted: %d\n",delNode(&L, 9) != NULL ? delNode(&L, 9)->data : delNode(&L, 9));

    print(&L);
}