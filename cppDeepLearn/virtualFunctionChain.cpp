#include <iostream>
using namespace std;
class A
{
    public:
        virtual void foo(){cout << "foo in A" << endl;}
    private:
};

class B: public A
{
    public:
        void foo(){cout << "foo in B" << endl;}
};

class C: public B
{
    public:
        void foo(){cout << "foo in C" << endl;}
};

int main(void)
{
    A * ac = new C();
    ac->foo();

    B * bc = new C();
    bc->foo();
}