#include <iostream>
using namespace std;

void test(int a)
{
    a = a + 1;
    cout << a << endl;
}

// top-level const is ignored.
// same as "void test(int a)" except "a" cannot be modified in this function.
// Thus this function cannot be a overloaded function of "void test(int a)"
// void test(const int a)
// {
//     // a = a + 1; // error
//     cout << a << endl;
// }

int Add(int a, int b)
{
    cout << "add two int number" << endl;
    return a + b;
}

float Add(float a, float b)
{
    cout << "add two float number" << endl;
    return a + b;
}
int main(void)
{
    float result = Add(1.6, 2.0);
    // 3 it is.
    cout << result << endl;

    float re = Add (1.6, 2.4);
    return 0;
}