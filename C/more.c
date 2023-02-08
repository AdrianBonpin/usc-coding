#include <stdio.h>
int mystrlen(char arr[]){
    int counter = 0;
    for(counter = 0 ; *(arr+counter)!='\0';counter++){}
    return counter-1;
}
int mystrcmp(char arr[], char arr2[]){
    int state = 1 , x , size = mystrlen(arr);
    for(x = 0 ; x < size ; x++){
        if(*(arr+x) != *(arr2+x)){
            state = 0;
        }
    }
    return state;
}
void mystrcpy(char arr[],char arr2[]){
    int size = mystrlen(arr), x;
    for(x = 0 ; x < size ; x++){
        *(arr2+x) = *(arr+x);
    }
}
void mystrrev(char arr[]){
    int x , y , length = mystrlen(arr);
    char wordt[100];
    for(x = 0 ; x < length ; x++){
        wordt[x] = *(arr+x);
    }
    for(x = --length , y = 0; x >= 0 ; x-- , y++){
        *(arr+y) = wordt[x];
    }
}
void mystrcat(char arr[], char arr2[]){
    int x , y , len = mystrlen(arr), len2 = mystrlen(arr2);
    for( x = len , y = 0 ; x < (len + len2) ; x++ , y++){
        *(arr+x) = *(arr2+y);
    }
}
int myisalpha(char a){
    int x , state = 0 ;
    for( x = 65 ; x <= 122 ; x++ ){
        if(x <= 96 && x >= 91 ){}else{
            if( (int) a == x ){
                state = 1 ;
            }
        }
    }
    return state;
}
int myisspace(char a){
    int state = 0 ;
    if ( (int) a == 32 ){
        state = 1;
    }
    return state;
}
int myisdigit(char a){
    int x , state = 0 ;
    for( x = 48 ; x <= 57 ; x++ ){
        if( (int) a == x ){
            state = 1 ;
        }
    }
    return state;
}
int myispunct(char a){
    int x , state = 0 ;
    for( x = 33 ; x <= 126 ; x++ ){
        if(x <= 57 && x >= 48 ){}else if(x <= 90 && x >= 65 ){}else if(x <= 122 && x >= 97 ){}else{
            if( (int) a == x ){
                state = 1 ;
            }
        }
    }
    return state;
}
char mytolower(char a){
    int x;
    for( x = 65 ; x <= 90 ; x++){
        if( (int) a == x){
            a+=32;
        }
    }
    return a;
}
char mytoupper(char a){
    int x;
    for( x = 97 ; x <= 122; x++){
        if( (int) a == x){
            a-=32;
        }
    }
    return a;
}
void main(){
    char word[100],word2[100], letter;
    printf("Enter line: ");
    fgets(word2,100,stdin);
    printf("Enter line to reverse: ");
    fgets(word,100,stdin);
    mystrrev(word);
    mystrcat(word2, word);
    printf("Reversed line: %s\n",word);
    printf("Concatenated (joined) line: %s\n", word2);
    int x;
    for( x = 0 ; x < mystrlen(word2) ; x++ ){
        if(myisspace(word2[x])==1){
            printf("\nSpace in pos %d!\n",x);
        }
    }
    printf("Enter 1 character: ");
    scanf("%c",&letter);
    printf("\nIt is alpha = %d",myisalpha(letter));
    printf("\nIt is digit = %d",myisdigit(letter));
    printf("\nIt is punct = %d",myispunct(letter));
    if(myisalpha(letter)==1){
        printf("\ntolower = %c",mytolower(letter));
        printf("\ntoupper = %c",mytoupper(letter));
    }
}