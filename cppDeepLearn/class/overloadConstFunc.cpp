#include <iostream>
using namespace std;

const int add(int a, int b)
{
    return a + b;
}
// ambiguating new declaration of ‘int add(int, int)’
// int add(int a, int b)
// {
//     return a + b;
// }

class Test
{
public:
    int getA() {return a;}
    int getA() const {cout << "nonconst" << endl; return a;}
private:
    int a = 1;
};
int main(void)
{
    int b = add(1, 2);
    Test t;
    cout << t.getA() << endl;

    const Test t1;
    cout << t1.getA() << endl;
    return 0;
}