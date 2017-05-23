#include <iostream>
using std::cout;
using std::endl;
#include <utility>
using std::move;

void printRvalue(int &&i)
{
    cout << i << endl;
}

int main(void)
{
    int i = 42;
    // error i * 42 is an rvalue.
    // int &r2 = i * 42;

    // ok: we can bind a regerence to const to an rvalue.
    const int &r3 = i * 42;

    int &&rr2 = i * 42;
    rr2 = 100;
    cout << rr2 << endl;

    int &&rr3 = move(i);
    cout << rr3 << endl;
    cout << i << endl;

    printRvalue(12);
    return 0;
}