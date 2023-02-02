#include <stdio.h>
#include <stdlib.h>

int* populate(){
    int *arr = malloc (sizeof(int) * 5);
    printf("Input 5 numbers:\n");
    for(int x = 0 ; x < 5 ; x++){
        scanf("%d",arr+x);
    }
    return arr;
}

void swap(int arr[],int count){
    int sm = *(arr+count), pos = count;
    for(int x = count ; x < 5 ; x++){
        if(sm > *(arr+x)){
            pos = x;
            sm = *(arr+x);
        }
    }
    if(sm < *(arr+count)){
        *(arr+pos) = *(arr+count);
        *(arr+count) = sm;
    }
}

int main(){
    int *x;
    x = populate();
    for(int count = 0 ; count < 5 ; count++){
        swap(x, count);
    }
    for(int y = 0 ; y < 5 ; y++){
        printf("%d ",*(x+y));
    }
}