#include <iostream>
using namespace std;

void f(){}
void f(int a){}
void f(int a, int b){ cout << "int" << a + b << endl;}
void f(double a, double b){cout << "float" << a + b << endl;}

int add(int a, int b)
{
    cout << "int" << endl;
    return a + b;
}

float add(double a, double b)
{
    cout << "float" << endl;
    return a + b;
}

int addE(int a, int b)
{
    cout << "int" << endl;
    return a + b;
}

float addE(float a, float b)
{
    cout << "float" << endl;
    return a + b;
}

// 1. An exact match. An exact match happens when:
// • The argument and parameter types are identical.
// • The argument is converted from an array or function type to the corresponding
// pointer type. (§ 6.7 (p. 247) covers function pointers.)
// • A top-level const is added to or discarded from the argument.
// 2. Match through a const conversion (§ 4.11.2, p. 162).
// 3. Match through a promotion (§ 4.11.1, p. 160).
// 4. Match through an arithmetic (§ 4.11.1, p. 159) or pointer conversion (§ 4.11.2,
// p. 161).
// 5. Match through a class-type conversion. (§ 14.9 (p. 579) covers these
// conversions.)

int main(void)
{
    f(5.6);
    f(3.0, 2.0);
    f(3, 2);
    cout << sizeof(int) << " " << sizeof(float) << endl;

    float a = add(2.0,3.3);
    // float b = addE(2.3, 4.3);
    return 0;
}