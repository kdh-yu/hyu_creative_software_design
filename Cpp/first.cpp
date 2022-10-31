#include <stdio.h>

int main(){
    char ch1 = 'a';
    char* pch1 = &ch1;

    printf("%d\t%c\n", ch1, ch1);
    printf("%p\n", &ch1);
    printf("%p\n", pch1);
    printf("%p\n", &pch1);

    return 0;
}