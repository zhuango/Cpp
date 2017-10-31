#include <iostream>
using namespace std;

class Test
{
public:
    Test(){a = 10;}
    void func2() {cout << this->a << endl;}
    // A const following the parameter list indicates that "this" is a pointer to const
    void func() const {cout << this->a << endl;}
    // we cannot call an ordinary member function on a const object.
    void const func3() {cout << this->a << endl;}
    const void func4() {cout << this->a << endl;}
private:
    int a;
};

int main(void)
{
    const Test t;
    t.func();
    // func2
    //t.func2();
    Test t1;
    t1.func();
    t1.func2();
    t1.func3();
    t1.func4();
    return 0;
}
