#include <stdio.h>

int main(){
    int a[3] = {1 , 2 , 3};
    a[1000] = 1;
    printf("%d \n", a[1000]);
}