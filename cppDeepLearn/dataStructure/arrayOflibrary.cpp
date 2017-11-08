#include <array>
#include <iostream>
using namespace std;
int main(void)
{
    // The size is part of the array’s type
    array<int, 42> arrayWith42elems;

    array<int, 42> arrayWith42elems2 = arrayWith42elems;
    return 0;
}