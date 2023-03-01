#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name1{
    char name[20];
    int x;
    float y;
} n1;

union name2{
    char name[20];
    int x;
    float y;
} n2;

enum year{first = 1,second = 20 ,third,fourth}level;

int main(){
    int size = sizeof(n1);
    int size2 = sizeof(n2);
    printf("Size 1 = %d\nSize 2 = %d",size,size2);
    strcpy(n1.name,"Adrian");
    n1.x = first;
    n1.y = 20;
    printf("\n\nstruct\nname1 = %s\nx1 = %d\ny1 = %d",n1.name,n1.x,n1.y);
    n2.y = 19;
    strcpy(n2.name,"Matt");
    n2.x = second;
    printf("\n\nunion\nname2 = %s\nx2 = %d\ny2 = %d\n\n- - - - - - -\n",n2.name,n2.x,n2.y);

    for(level = first; level <= fourth ; level++){
        printf("%d\n\n",level);
    }
    return 0;
}