#include <stdio.h>

int main(){
    int a[3] = {1 , 2 , 3};
    a[10] = 1;
    printf("%d \n", a[10]);
}