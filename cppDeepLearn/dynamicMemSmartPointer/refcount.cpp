#include <memory>
#include <iostream>

using namespace std;

class Test
{
    public:
        Test(){cout << "Test is created" << endl;}
        ~Test(){cout << "Test is destroied" << endl;}
};
int main(void)
{
    auto r = make_shared<Test>();
    auto q = make_shared<Test>();

    r = q;
    cout << "+++++++++++++++++++++++++++++" << endl;
    return 0;
}