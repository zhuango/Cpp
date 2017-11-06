#include <iostream>
using namespace std;

class Test
{
public:
    // error: static member cannot init inside of class.
    // static int a = 100;
    static int a;
    static const int b = 1;
};

int Test::a =  100;

class Bar
{
public:
    // ok: static member can have incomplete type
    static Bar mem1;
    // ok: pointer member can have incomplete type
    Bar * mem2;
    // error: data members must have complete type
    // Bar mem3;
};

int main(void)
{
    Test t;
    cout << t.a << endl;
    cout << t.b << endl;
    cout << Test::a << endl;
    cout << Test::b << endl;
    return 0;
}