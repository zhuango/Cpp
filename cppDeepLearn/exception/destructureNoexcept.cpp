#include <iostream>
using namespace std;

struct A
{
    ~A(){ throw 1; }
};

struct B
{
    ~B() noexcept(false) {throw 2;}
};

struct C
{
    B b;
};

int funcA() { A a; }
int funcB() { B b; }
int funcC() { C c; }

int main(void)
{
    try
    {
        funcB();
    }
    catch(...)
    {
        cout << "cought funcB." << endl;
    }

    try
    {
        funcC();
    }
    catch(...)
    {
        cout << "cought funcC." << endl;
    }

    try
    {
        funcA();
    }
    catch(...)
    {
        cout << "cought funcA" << endl;
    }
    return 0;
}