#include <stdio.h>

//Bubble Sort
void sort(int *arr, int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, arr[10];

    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, 10);

    printf("Sorted numbers: \n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}