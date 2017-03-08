#include <stdio.h>
#include <memory.h>
#include <malloc.h>
typedef struct test
{
    char a[1];
}Test;

void main(void)
{
    Test *t = (Test*)malloc(sizeof(Test) + 10);
    strcpy(t->a, "abcdefg");
    printf("%ld\n", sizeof(*t));
    printf("%c\n", t->a[3]);
}
