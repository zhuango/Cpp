#include <cstddef>
using std::size_t;
#include <iostream>
using std::cout;
using std::endl;


int arr[10];
int *p1[10];
int (*p2)[10] = &arr;

using arrT = int[10];

// three ways to declare function returning pointer to array of ten ints
arrT *func(int i);
auto func(int i) -> int(*)[10];
int (*func(int i))[10];

auto func2(int i) -> int(&)[10];

//two arrays
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

int *elemPtr(int i)
{
    return (i % 2) ? odd : even;
}

decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}
// returns a reference to an array of five int elements.
int (&arrRef(int i))[5]
{
    return (i % 2) ? odd : even;
}


int main(void)
{
    int arr[10];
    cout << arr << endl;
    cout << &arr << endl;

    int *p = elemPtr(6);
    int (*arrP)[5] = arrPtr(6);
    int (&arrR)[5] = arrRef(4);
    cout << p << " " << *arrP << " " << arrR << endl;
    cout << "++++++++++++++++++++++++++" << endl;
    for (size_t i = 0; i < 5; ++i)
    {
        cout << p[i] << " ";
    }
    cout << "++++++++++++++++++++++++++" << endl;

    for (size_t i = 0; i < 5; ++i)
    {
        cout << (*arrP)[i] << " ";
    }
    cout << "++++++++++++++++++++++++++" << endl;
    
    for (size_t i = 0; i < 5; ++i)
    {
        cout << arrR[i] << ' ';
    }
    cout << "++++++++++++++++++++++++++" << endl;

    return 0;
}