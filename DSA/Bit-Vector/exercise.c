#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} *SET, ltype;

void initSet(SET *L) {
    *L = NULL;
}

SET node() {
    return (SET)malloc(sizeof(ltype));
}

void insFirst(SET *L, int data) {
    SET new = node();
    new->data = data;
    new->next = *L;
    *L = new;
}

void insLast(SET *L, int data) {
    SET new = node();
    new->data = data;
    new->next = NULL;
    if (*L == NULL) {
        *L = new;
    } else {
        SET current = *L;
        while ( current->next != NULL ) {
            current = current->next;
        }
        current->next = new;
    }
}

void replace(SET *L, int pos, int data) {
    if ( pos < MAX ) {
        int i;
        SET curr = *L;
        for ( i = 0 ; i < pos ; i++ ) {
            curr = curr->next;
        }
        curr->data = data;
    }
}

void print(SET *L) {
    SET current = *L;
    printf("Set: ");
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

void fill(SET *L, int val, int size) {
    int i;
    if ( L != NULL && size < MAX ) {
        for ( i = 1 ; i <= MAX ; i++ ) {}
        if ( (i + size) <= MAX ) {
            int x;
            for ( x = 0 ; x < size ; x++ ) {
                insLast(L, val);
            }
        } else {
            printf("\n\nError doing fill!!\n\n");
        }
    } else if ( size <= MAX ) {
        for ( i = 0 ; i < size ; i++ ) {
            insLast(L, val);
        }
    } else {
        printf("\n\nError doing fill!!\n\n");
    }
}

SET bitVect(SET *L) {
    SET bitvect, cur = *L;
    initSet(&bitvect);

    fill(&bitvect, 0, MAX);

    while ( cur->next != NULL ) {
        replace( &bitvect, cur->data, 1);
        cur = cur->next;
    }
    replace( &bitvect, cur->data, 1);

    return bitvect;
}

// Gets the set union of A and B
SET setUnion(SET *A, SET *B) {
    SET C, Avect, Bvect;
    initSet(&C);
    initSet(&Avect);
    initSet(&Bvect);

    Avect = bitVect(A);
    Bvect = bitVect(B);

    int i;
    for ( i = 0 ; i < MAX ; i++ ) {
        if ( Avect->data != 0 || Bvect->data != 0 ) {
            insLast(&C, i);
        }
        Avect = Avect->next;
        Bvect = Bvect->next;
    }

    return C;
    
}

// Gets the Intersection of A and B
SET setInter(SET *A, SET *B) {
    SET C, Avect, Bvect;
    initSet(&C);
    initSet(&Avect);
    initSet(&Bvect);

    Avect = bitVect(A);
    Bvect = bitVect(B);

    int i;
    for ( i = 0 ; i < MAX ; i++ ) {
        if ( Avect->data != 0 ) {
            if ( Bvect->data != 0 ) {
                insLast(&C, i);
            }
        }
        Avect = Avect->next;
        Bvect = Bvect->next;
    }

    return C;
}

// Get the Difference of A and B
SET setDiff(SET *A, SET *B) {
    SET C, Avect, Bvect;
    initSet(&C);
    initSet(&Avect);
    initSet(&Bvect);

    Avect = bitVect(A);
    Bvect = bitVect(B);

    int i;
    for ( i = 0 ; i < MAX ; i++ ) {
        if ( Avect->data != 0 ) {
            if ( Bvect->data == 0 ) {
                insLast(&C, i);
            }
        }
        Avect = Avect->next;
        Bvect = Bvect->next;
    }

    return C;
}

void main() {
    SET A, B;

    // Initialize Sets
    initSet(&A);
    initSet(&B);

    // Insert set A variables ( 1, 2, 3, 7 )
    insLast(&A, 1);
    insLast(&A, 2);
    insLast(&A, 3);
    insLast(&A, 7);
    print(&A);

    // Insert set B variables ( 2, 3, 6 )
    insLast(&B, 2);
    insLast(&B, 3);
    insLast(&B, 6);
    print(&B);

    // Get the Union
    SET Union;
    initSet(&Union);
    Union = setUnion(&A, &B);
    printf("Union\n");
    print(&Union);

    // Get the Interesction
    SET Intersection;
    initSet(&Intersection);
    Intersection = setInter(&A, &B);
    printf("Intersection\n");
    print(&Intersection);

    // Get the Difference
    SET Diff1, Diff2;
    initSet(&Diff1);
    initSet(&Diff2);
    Diff1 = setDiff(&A, &B);
    Diff2 = setDiff(&B, &A);
    printf("Difference\n");
    printf("A to B = ");
    print(&Diff1);
    printf("B to A = ");
    print(&Diff2);

}