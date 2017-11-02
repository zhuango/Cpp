#include<iostream>
using namespace std;

class Test
{
public:
    void MutableTest0()const {b = 100;}
    // Error const member function cannot modify a member variable that is not mutable.
    //void MutableTest1()const {a = 100;}
    int getB() const {return b;}
    int setB(int bb) { b = bb; }
    Test & GetObj(){return *this;}
    // error: binding ‘const Test’ to reference of type ‘Test&’ discards qualifiers
    // Test & GetObjConst()const {return *this;}

    // A const member function that returns *this as a reference should have a
    // return type that is a reference to const.
    const Test & GetObjConst()const {return *this;}
private:
    int a = 1;
    mutable int b = 10;
};

int main(void)
{
    Test test;
    test.MutableTest0();
    cout << test.getB() << endl;
    test.GetObj().setB(2);
    // error: passing ‘const Test’ as ‘this’ argument discards qualifiers
    // test.GetObjConst().setB(2);

    const Test test1;
    test1.MutableTest0();
    cout << test1.getB() << endl;

}