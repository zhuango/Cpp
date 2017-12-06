#include <iostream>

using namespace std;

class numbered
{
    public:
    numbered():mysn(++unique) {}
    numbered(numbered &n):mysn(++unique){}
    int mysn;
    private:
    static int unique;

};

int numbered::unique = 0;

void f(const numbered &n)
{
    cout << n.mysn << endl;
}

int main(void)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    numbered d;
    f(d);
    return 0;
}