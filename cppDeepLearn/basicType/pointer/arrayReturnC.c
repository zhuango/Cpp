#include <stddef.h>


typedef int (*arrayPointer)[5];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

int *elemPtr(int i)
{
    return (i % 2) ? odd : even;
}

arrayPointer arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}

int main(void)
{
    int* p = elemPtr(6);
    int (*arrP)[5] = arrPtr(6);
    printf("%d\n", *p);
    printf("%d\n", p);
    printf("%d\n", *arrP);    
}