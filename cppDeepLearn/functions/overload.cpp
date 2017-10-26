#include <iostream>
using namespace std;

void test(int a)
{
    a = a + 1;
    cout << a << endl;
}

// same as "void test(int a)" except "a" cannot be modified in this function.
// Thus this function cannot be a overloaded function of "void test(int a)"
void test(const int a)
{
    // a = a + 1; // error
    cout << a << endl;
}

int main(void)
{
    return 0;
}