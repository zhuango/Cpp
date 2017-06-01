#include <iostream>
using namespace std;

template<typename T>
void TempFun(T a)
{
    cout << a << endl;
}

template <typename T = int>
class DefClass{};

template <typename T = int>
void DefTEmpParm()
{}

template <typename T1, typename T2 = int> 
class DefClass1{};

// Error! the default typename must in the end of template parameters list.
// template <typename T1 = int, typename T2>
// class DefClass2{};

template <typename T1, int i = 0>
class DefClass3;

// Error! the default typename must in the end of template parameters list.
// template <int i = 0, typename T>
// class DefClass4;

// no limitation for the order of template parameters of a function template.
template <typename T1 = int, typename T2>
void DefFunc1(T1 a, T2 b);

// no limitation for the order of template parameters of a function template.
template <int i = 0, typename T> 
void DefFunc2(T a);

template <class T, class U = double>
void f(T t = t, U u = 0)
{
    cout << t << " " << t << endl;
}
void g()
{
    f(1, 'c'); // f<int, char>(1, 'c')
    f(1);      // f<int, double>(1, 0)
    // Error! don't know the type.ss
    //f();
    f<int>();  // f<int, double>(0, 0)
    f<int, char>(); // f<int, char> (0, 0)
}

int main(void)
{
    TempFun(1);
    TempFun("1");
}