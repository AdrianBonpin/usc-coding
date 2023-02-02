#include <stdio.h>
int main(){
    for(int x = 0 ; x <= 255 ; x++){
        printf("%d = %c %x\n", x, x, x);
    }
}