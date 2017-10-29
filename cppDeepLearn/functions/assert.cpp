#define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
    cerr << __func__ << ": array size is " << size << endl;
    #endif
}
int main(void)
{
    assert(1==4);
    cout << "ssss" << endl;

    int a[10] = {12};
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    print(a, 100);
    return 0;
}