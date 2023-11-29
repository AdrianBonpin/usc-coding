#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* table[TABLE_SIZE];
} HashTable;

void initializeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

int generateKey(int value) {
    return value % TABLE_SIZE;
}

void insert(HashTable* ht, int value) {
    int key = generateKey(value);
    int index = hash(key);

    while (ht->table[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }

    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;

    ht->table[index] = newEntry;
}

int search(HashTable* ht, int key) {
    int index = hash(key);

    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1; // Key not found
}

void delete(HashTable* ht, int key) {
    int index = hash(key);

    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            free(ht->table[index]);
            ht->table[index] = NULL;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
}

void printHashTable(HashTable* ht) {
    printf("Key\tValue\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("%d\t%d\n", ht->table[i]->key, ht->table[i]->value);
        } else {
            printf("-\t-\n");
        }
    }
    printf("-------------\n");
}

int main() {
    HashTable ht;
    initializeHashTable(&ht);

    insert(&ht, 3);
    insert(&ht, 5);
    insert(&ht, 13);
    insert(&ht, 4);
    printHashTable(&ht);

    return 0;
}