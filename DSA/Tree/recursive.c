#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool isMember(struct Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    return isMember(root->left, value) || isMember(root->right, value);
}

void Traversal(struct Node* root) {
    if (root != NULL) {
        Traversal(root->left);
        printf("%d ", root->data);
        Traversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Traversal: ");
    Traversal(root);
    printf("\n");;

    int searchValue = 40;
    if (isMember(root, searchValue)) {
        printf("%d is present in the tree.\n", searchValue);
    } else {
        printf("%d is not present in the tree.\n", searchValue);
    }

    return 0;
}