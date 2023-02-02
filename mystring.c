#include <stdio.h>
//Input String, return size in int
int mystrlen(char arr[]){
    int counter = 0; //Create a counter to return
    for(counter = 0 ; *(arr+counter)!='\0';counter++){} //Loops and increments counter until it hits "\0"
    return counter-1; //Returns counter - 1 as "\0" is included
}
//Input 2 Strings, return state in int
int mystrcmp(char arr[], char arr2[]){
    int state = 1; //Create state flag that reads 1 for true and 0 for false (true is same)
    int size = mystrlen(arr); //runs length to find the length
    int x; //initalize for the loop
    for(x = 0 ; x < size ; x++){ //Increment and loop until x hits size of string
        if(*(arr+x) != *(arr2+x)){ //ask if string1 posX is same with string2 posX
            state = 0; //If true, immediately trip flag that there is a difference
        }
    }
    return state; //Return flag
}
//Input 2 Strings, return 2nd string with contents of 1st string
void mystrcpy(char arr[],char arr2[]){
    int size = mystrlen(arr); //runs length to find the length xD
    int x; //for the for loop again
    for(x = 0 ; x < size ; x++){ //Increments x and loops until x is equal to size
        *(arr2+x) = *(arr+x); //copies character from str1 posX to str2 posX
    }
}
int main(){
    char word[100],word2[100],word3[100],word4[100];
    printf("Enter line: ");
    fgets(word,100,stdin);
    int len = mystrlen(word); //Input String, returns String Length
    printf("String length is: %d\n\n", len);
    printf("Enter second line: ");
    fgets(word2,100,stdin);
    int state = mystrcmp(word,word2); //Input 2 Strings, return 0 as same and 1 as not same
    if(state!=0){
        printf("The lines are the same!\n\n");
    }else{
        printf("The lines are not the same!\n\n");
    }
    printf("Input line to copy: ");
    fgets(word3,100,stdin);
    mystrcpy(word3, word4); //Input 2 strings, return 2nd string with content from 1st string
    printf("The line copied is: %s\n\n",word4);
    return 0;
}