#include <stdio.h>
#include <stdlib.h>
void bubble(int arr[],int size){
    int temp, flag, x;
    do{
        flag=0;
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
void quick(int arr[], int size){ //Unfinished
    int *arr2 = malloc(size*sizeof(int)) , x,b,s;
    //Sort less than pivot
    for( x = 0 , s = 0; x < size-1 ; x++){
        if(*(arr+(size-1)) > *(arr+x)){
            *(arr2+s) = *(arr+x);
            s++;
        }
    }
    *(arr2+s) = *(arr+x);
    display(arr2,size);
    printf("\n");
    //Sort greater than pivot
    for( x = 0 , b = s + 1; x < size-1 ; x++){
        if(*(arr+(size-1)) <= *(arr+x)){
            *(arr2+b) = *(arr+x);
            b++;
        }
    }
    display(arr2,size);
    printf("\n");
}
void selection(int arr[], int size){
    int x, y, min, temp;
    for( y = 0 ; y < size - 1 ; y++){
        min = y;
        for( x = y ; x < size ; x++){
            if( min > *(arr+x) ){
                min = x;
            }
        }
        temp = *(arr+min);
        *(arr+y) = *(arr+min);
        *(arr+min) = temp;
    }
}
void display(int arr[],int size){
    int x;
    for (x = 0 ; x < size ; x++){
        printf("%d ",*(arr+x));
    }
}
void main(){
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
        case 2 : quick(arr,size);
        break;
        case 3 :
        break;
        case 4 :
        break;
        case 5 :
        break;
        case 6 : selection(arr,size);
        break;
    }
    display(arr,size);
}