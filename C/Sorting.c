#include <stdio.h>
#include <stdlib.h>
void display(int arr[],int size){
    int x;
    for (x = 0 ; x < size ; x++){
        printf("%d ",*(arr+x));
    }
    printf("\n");
}
void bubble(int arr[],int size){
    int temp, flag, x;
    do{
        flag=0;
        display(arr,size);
        printf("\n");
        for(x = 0 ; x < (size-1) ; x++){
            if(*(arr+x) > *(arr+(x+1))){
                flag = 1;
                temp = *(arr+x);
                *(arr+x) = *(arr+(x+1));
                *(arr+(x+1)) = temp;
            }
        }
    }while(flag == 1);
}
void insertion(int arr[], int size){
    int x, y, temp;
    for( x = 1 ; x < size ; x++){
        temp = *(arr+x);
        for( y = x - 1 ; y >= 0 && *(arr+y) > temp ; y--){
            *(arr+(y+1)) = *(arr+y);
        }
        *(arr+(y+1)) = temp;
    }
}
void selection(int arr[], int size){
    int x, y, min, temp;
    for( y = 0 ; y < size - 1 ; y++){
        min = y;
        for( x = y + 1 ; x < size ; x++){
            if( *(arr+x) < *(arr+min) ){
                min = x;
            }
        }
        temp = *(arr+y);
        *(arr+y) = *(arr+min);
        *(arr+min) = temp;
        display(arr,size);
    }
}
int main(){
    int c, size, x;
    printf("Select which algo to use to sort! \n1\tBubble\n2\tQuick\n3\tMerge\n4\tHeap\n5\tInsertion\n6\tSelection\nInput: ");
    scanf("%d",&c);
    printf("Enter array size: ");
    scanf("%d",&size);
    int *arr=malloc(size*sizeof(int));
    printf("Enter %d elements in array: ",size);
    for(x = 0 ; x < size ; x++){
        scanf("%d",arr+x);
        }
    switch(c){
        case 1 : bubble(arr,size);
        break;
        case 2 : 
        break;
        case 3 :
        break;
        case 4 :
        break;
        case 5 : insertion(arr,size);
        break;
        case 6 : selection(arr,size);
        break;
    }
    display(arr,size);
    free(arr);
    return 0;
}