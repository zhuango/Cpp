#include <iostream>
#include <vector>
using namespace std;

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &ss) { std::cout << "X(const X&)" << std::endl; }

    ~X(){cout << "~X()" << endl;}
};

void EchoRef(X &x)
{
}

void EchoValue(X x)
{
}
X &f4(X &x)
{
    return x;
}

X f5()
{
    X x;
    return x;
}

X f6()
{
    //rvalue of type ‘X’
    return X();
}

int main(void)
{
    X *x = new X;
    vector<X> Xes;
    Xes.push_back(*x);

    cout << "=================" << endl;
    X x1;
    X x2(x1);
    cout << "=================" << endl;
    EchoRef(x1);
    EchoValue(x1);
    cout << "=================" << endl;
    f4(x1);
    cout << "=================" << endl;
    X x3(f5());
    cout << "========X x4 = f6()=========" << endl;
    X x4 = f6();
    cout << "=================" << endl;
    return 0;
}