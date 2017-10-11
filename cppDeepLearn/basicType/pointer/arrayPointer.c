#include <stdio.h>

int main(void)
{
    int a[3][4];
    printf("a:\t%x\n", a);
    printf("a+1:\t%x\n", a + 1);
    printf("a[0]:\t%x\n", a[0]);
    printf("a[0]+1:\t%x\n", a[0] + 1);

    int *b = a;
    printf("%x\n", b + 1);
    printf("%x\n", b[0]);
    printf("%x\n", b[0] + 1);
    return 0;
}