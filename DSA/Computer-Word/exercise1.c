#include <stdio.h>

void bitPatt(int num) {
    int size = sizeof(num) * 8;
    for (int i = size - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Bit pattern: ");
    bitPatt(num);
}