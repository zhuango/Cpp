#include <iostream>
using namespace std;

int main(void)
{
    bool a = false;
    bool b = -a;
    //0 0
    cout << a << "  " << b << endl;

    bool c = true;
    bool d = -c;
    //1 1
    cout << c << "  " << d << endl;
}