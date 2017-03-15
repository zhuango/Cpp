#include <iostream>
using namespace std;

class test
{
    public:
    test()
    ///
    :b(1), a(b)
    ///
    {}
    
    int Geta(){return a;}
    int Getb(){return b;}
    private:
    int a;
    int b;
};

int main(void)
{
    test t;
    cout << t.Geta() << endl;
    cout << t.Getb() << endl;
    return 0;
}