#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

#define assert_static(e) \
    do{ \
        enum { assert_static__ = 1/(e) }; \
    } while (0)

template<typename T, typename U> int bit_copy(T& a, U& b)
{
    //assert_static(sizeof(b) == sizeof(a));
    //must be a const expression.
    static_assert(sizeof(b) == sizeof(a), "the parameters of bit_copy must have same width.");
    memcpy(&a, &b, sizeof(b));
}

int main()
{
    int a = 0x2468;
    //double a = 0.0;
    double b;
    bit_copy(a, b);
}
