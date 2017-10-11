#include <iostream>
using namespace std;

int main(void)
{
    int a[3][4];
    cout << a << endl;
    cout << a + 1 << endl;

    int *b = a;
    cout << b + 1 << endl;
    return 0;
}