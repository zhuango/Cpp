#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    Test() {}
    Test(int a) {aa = a;}
    explicit Test(string &s) { ss = s;}
    
    int GetAA() const {return aa;}
    string GetBB() const {return ss;}
private:
    int aa;
    string ss;
};

void processTestObj(Test t)
{
    cout << t.GetAA() << endl;
}

void processTestObj1(Test &t)
{
    cout << t.GetAA() << endl;
}

void processTestObj2(const Test &t)
{
    cout << t.GetAA() << endl;
}

void processTestObj3(const Test &t)
{
    cout << t.GetBB() << endl;
}
int main(void)
{
    Test t;
    processTestObj(t);
    processTestObj(12);
    // Error: cannot bind non-const lvalue reference of type ‘Test&’ to an rvalue of type ‘Test’
    // processTestObj1(1);
    processTestObj2(2);
    // two class-type conversion is not allowed, const char * -> string, string -> Test
    // processTestObj3("sdfsf");

    string s = "zhuangliu";
    processTestObj3(s);
    return 0;
}