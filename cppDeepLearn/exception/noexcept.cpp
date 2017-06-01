#include <iostream>
using namespace std;

void except_func() noexcept
{
    throw;
}

const bool thro = false;

void except_func1() noexcept(thro)
{
    throw;
}

void Throw() { throw 1; }
void NoBlockThrow() { Throw(); }
void BlockThrow() noexcept { Throw(); }
void no_except_test()
{
    try
    {
        Throw();
    }
    catch(...)
    {
        cout << "Found throw." << endl;
    }

    try
    {
        // By marked noexcept, this function terminates and 
        // its exception won't be catched by this try.
        NoBlockThrow();
    }
    catch(...)
    {
        cout << "Throw is not blocked." << endl;
    }

    try
    {
        BlockThrow();
    }
    catch(...)
    {
        cout << "Found throw 1." << endl;
    }
}

int main()
{
    //except_func();
    //except_func();
    no_except_test();
}