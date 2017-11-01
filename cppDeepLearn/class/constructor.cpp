#include <iostream>
using namespace std;

class Test
{
public:
    // We are defining this constructor only because we want to provide other
    // constructors as well as the default constructor
    Test() = default;

    Test(int aa){cout << "test" << endl; a = aa;}
    //void SetA(int aa)  const {a = aa;}
    int GetA()const {return a;}
private:
    int a = 5;

};
int main(void)
{
    const Test test(11);
    cout << test.GetA() << endl;
    //test.SetA(10);

    Test test2;
    cout << test2.GetA() << endl;
    return 0;
}