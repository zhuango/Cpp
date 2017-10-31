#include <iostream>
using namespace std;

bool test(int a, int b)
{
    cout << a << endl;
    cout << b << endl;
    cout << "==============" << endl;
    return a == b;
}
// When we pass a function as an argument, we can do so directly. It will be
// automatically converted to a pointer:
bool functionPointerPara(int a, int b, bool(t)(int, int))
{
    return t(a, b);
}

bool functionPointerPara1(int a, int b, bool(*t)(int, int))
{
    return t(a, b);
}

typedef bool Func(int, int);
typedef bool (*FuncP)(int, int);
typedef decltype(test) Func2;
using Func3 = bool(int, int);
using Func3P = bool(*)(int, int);

bool functionPointerPara2(int a, int b, Func t)
{
    t(a, b);
}
bool functionPointerPara3(int a, int b, Func *t)
{
    t(a, b);
}
bool functionPointerPara4(int a, int b, FuncP t)
{
    t(a, b);
}

bool functionPointerPara5(int a, int b, Func2 t)
{
    t(a, b);
}
bool functionPointerPara6(int a, int b, Func3 t)
{
    t(a, b);
}
bool functionPointerPara7(int a, int b, Func3P t)
{
    t(a, b);
}

// function type cannot be function return type.
// Func3 returnAFunction()
// {
//     return test;
// }

Func3P returnAFunction()
{
    return test;
}

bool (*returnAFunction2())(int, int)
{
    return test;
}

auto returnAFunction3() -> bool(*)(int, int)
{
    return test;
}
int main(void)
{
    bool (*p) (int, int);
    p = test;
    cout << p(10, 2) << endl;

    p = &test;// equal to "p = test"
    cout << p(1, 1) << endl;
    // There is no conversion between pointers to one function type and pointers to
    // another function type.
    bool result = p(1, 1);
    result = (*p)(1, 1);

    cout << "parameter" << endl;
    functionPointerPara(1, 2, p);
    functionPointerPara1(1, 2, p);
    functionPointerPara2(1, 2, p);
    functionPointerPara3(1, 2, p);
    functionPointerPara4(1, 2, p);
    functionPointerPara5(1, 1, p);
    functionPointerPara6(1, 1, p);
    functionPointerPara7(1, 1, p);
    returnAFunction()(1,1);
    returnAFunction2()(1,1);
    returnAFunction3()(1,1);
    return 0;
}