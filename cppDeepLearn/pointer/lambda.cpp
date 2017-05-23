#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

void func1()
{
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
    cout << j << endl;
}

void func2()
{
    size_t v1 = 42;
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

void func3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    // 0
    auto j = f();
    cout << j << endl;
    cout << v1 << endl;
}

void func4()
{
    size_t v1 = 42;
    auto f2 = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

void func5()
{
    size_t v1 = 42;
    size_t *const p = &v1;
    auto f = [p]() { return ++*p; };
    auto j = f();
    cout << v1 << " " << j << endl;
    v1 = 0;
    j = f();
    cout << v1 << " " << j << endl;
}

int main()
{
    func1();
    func2();
    func3();
    func4();

    return 0;
}