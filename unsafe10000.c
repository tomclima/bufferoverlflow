#include <stdio.h>
int main(){
    int a[3] = {1 , 2 , 3};
    a[10000] = 1; // 1000 -> 10000
    printf("%d\n", a[10000]);
}
