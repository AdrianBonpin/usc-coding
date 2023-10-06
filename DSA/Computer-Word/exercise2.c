#include <stdio.h>

#define SET_SIZE 256

typedef struct {
    unsigned char set[SET_SIZE / 8];
} SET;

void initSet(SET *s) {
    for (int i = 0; i < SET_SIZE / 8; i++) {
        s->set[i] = 0;
    }
}

void displaySet(SET s) {
    printf("Set elements: {");
    for (int i = 0; i < SET_SIZE; i++) {
        if (member(s, i)) {
            printf("%d, ", i);
        }
    }
    printf("}\n");
}

void insert(SET *s, int element) {
    if (element >= 0 && element < SET_SIZE) {
        int byteIndex = element / 8;
        int bitIndex = element % 8;
        s->set[byteIndex] |= (1 << bitIndex);
    }
}

int member(SET s, int element) {
    if (element >= 0 && element < SET_SIZE) {
        int byteIndex = element / 8;
        int bitIndex = element % 8;
        return (s.set[byteIndex] & (1 << bitIndex)) != 0;
    }
    return 0; // False
}

void delete(SET *s, int element) {
    if (element >= 0 && element < SET_SIZE) {
        int byteIndex = element / 8;
        int bitIndex = element % 8;
        s->set[byteIndex] &= ~(1 << bitIndex);
    }
}

void unionSets(SET s1, SET s2, SET *result) {
    for (int i = 0; i < SET_SIZE / 8; i++) {
        result->set[i] = s1.set[i] | s2.set[i];
    }
}

void intersectionSets(SET s1, SET s2, SET *result) {
    for (int i = 0; i < SET_SIZE / 8; i++) {
        result->set[i] = s1.set[i] & s2.set[i];
    }
}

void differenceSets(SET s1, SET s2, SET *result) {
    for (int i = 0; i < SET_SIZE / 8; i++) {
        result->set[i] = s1.set[i] & ~s2.set[i];
    }
}

int main() {
    SET A, B, result;
    initSet(&A);
    initSet(&B);
    initSet(&result);

    insert(&A, 3);
    insert(&A, 5);
    insert(&B, 5);
    insert(&B, 7);

    printf("Set A: ");
    displaySet(A);

    printf("Set B: ");
    displaySet(B);

    unionSets(A, B, &result);
    printf("Union of Set 1 and Set 2: ");
    displaySet(result);

    intersectionSets(A, B, &result);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(result);

    differenceSets(A, B, &result);
    printf("Difference of Set 1 and Set 2: ");
    displaySet(result);

    return 0;
}