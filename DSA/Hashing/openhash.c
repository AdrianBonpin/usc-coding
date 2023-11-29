#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int value;
    int key;
    struct node *mem;
    struct node *next;
} ltype, *LIST;

LIST node() {
    return (LIST)malloc(sizeof(ltype));
}

void initList( LIST *L ) {
    *L = NULL;
}

int calcHsh( int value ) {
    return value % MAX;
}

// Inserts in order, if part of bucket, data is appended to the bucket
void insert(LIST *L, int data) {
    LIST cur = *L;
    LIST prev = NULL;
    LIST new = node();
    int hshval = calcHsh(data);

    new->key = hshval;
    new->value = data;
    new->mem = NULL;
    new->next = NULL;

    if (cur == NULL) {
        *L = new;
        printf("\nInserted %d as Initial Value", data);
    } else {
        while (cur != NULL && hshval > cur->key) {
            prev = cur;
            cur = cur->next;
        }
        if (cur != NULL && hshval == cur->key) {
            while (cur != NULL && data != cur->value) {
                prev = cur;
                cur = cur->mem;
            }
            if (cur != NULL && data == cur->value) {
                printf("\nDeleted %d", data);
            } else {
                if (prev != NULL) {
                    prev->mem = new;
                } else {
                    new->mem = cur->mem;
                    cur->mem = new;
                }
                printf("\nInserted %d as Bucket", data);
            }
        } else {
            new->next = cur;
            if (prev != NULL) {
                prev->next = new;
            } else {
                *L = new;
            }
            printf("\nInserted %d as Main", data);
        }
    }
}

// prints whole list and prints an error if empty
void print(LIST *L) {
    LIST cur = *L;
    if (cur != NULL) {
        printf("\n\n~ Open Hashing ~\n");
        while (cur != NULL) {
            LIST curmem = cur->mem;
            printf("\n+ # + -");
            printf("\n| %d | %d", calcHsh(cur->value), cur->value);
            while (curmem != NULL) {
                printf(" %d", curmem->value);
                curmem = curmem->mem;
            }
            printf(" |");
            cur = cur->next;
        }
        printf("\n+ - + -");
    } else {
        printf("List is empty!!");
    }
}

// checks from what member a value is, prints an error if not found
// if value is found, print the parent and the hash
void isMem(LIST *L, int value) {
    LIST cur = *L;
    if (cur != NULL) {
        int hashval = calcHsh(value);
        while (cur != NULL && hashval != cur->key) {
            cur = cur->next;
        }

        if (cur == NULL) {
            printf("\nCould not find");
        } else {
            while (cur != NULL && cur->value != value) {
                cur = cur->mem;
            }
            if (cur != NULL) {
                printf("\nValue is in group %d", cur->key);
            } else {
                printf("\nCould not find in group %d", hashval);
            }
        }
    } else {
        printf("\nList is empty!!");
    }
}


int main() {
    LIST L;
    initList(&L);


    insert(&L, 0);
    insert(&L, 14);
    insert(&L, 4);
    insert(&L, 24);
    insert(&L, 5);
    insert(&L, 15);
    insert(&L, 1);

    isMem(&L, 8);
    isMem(&L, 14);
    isMem(&L, 34);

    print(&L);

    return 0;
}