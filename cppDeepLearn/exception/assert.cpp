//#define NDEBUG

#include <cassert>
using namespace std;


char *ArrayAlloc(int n)
{
    assert(n > 0);
    return new char [n];
}

int main(void)
{
    char *a = ArrayAlloc(0);
}