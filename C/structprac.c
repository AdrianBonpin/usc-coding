#include <stdio.h>
#include <string.h>

struct grocer{
    char item[20];
    int price, quantity;
};

int main(){
    struct grocer shopping;
    struct grocer palit[10];
    scanf("%d",&shopping.item);
    strcpy(shopping.item,"Milk");
    shopping.price=100;
    shopping.quantity=2;
    printf("%s\t",shopping.item);
    printf("%d\t",shopping.price);
    printf("%d\t",shopping.quantity);
    return 0;
}