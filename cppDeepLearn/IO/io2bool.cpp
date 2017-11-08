#include <iostream>
#include <string>
using namespace std;

class Test
{
public:
    operator bool(){return true;}
};

int main(void)
{
    string s;
    while(cin >> s)
    {
        cout << s << endl;
    }

    Test t;
    if (t) { cout << "wo cao" << endl;}
    return 0;
}