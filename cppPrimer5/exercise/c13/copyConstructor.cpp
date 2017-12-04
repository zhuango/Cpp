#include <iostream>
using namespace std;

class Test
{
public:
    // must Test &t for cppy constructor.
    Test() = default;
    Test(const Test &t){cout << "copy constructor." << endl;}
    Test &operator= (Test t){ cout << "copy assignment operator." << endl; return *this;}
    // can be
    // Test &operator= (Test &t){ cout << "copy assignment operator." << endl;}
};

Test echo(Test t)
{
    return t;
}
int main(void)
{
    Test t;
    Test t1 = t;
    Test t2(t);

    Test *t3 = new Test(t);
    t = t1;
    cout << "=============================" << endl;
    Test ts[4] = {t, t1, *t3};
    cout << "=============================" << endl;
    Test t5 = echo(t1);
    return 0;
}