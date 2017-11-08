#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a) {cout << "int" << endl;}
    Test(string s){cout << "string" << endl;}
    Test(double d){cout << "double" << endl;}
    Test(string s, int aa){cout << "string int" << endl;}
};

int main(void)
{
    vector<Test> vecTests;
    vecTests.emplace_back(12);
    vecTests.emplace_back("test");
    vecTests.emplace_back(12.3);
    vecTests.emplace_back("test", 12);

    Test t(10);
    cout << "ddddd" << endl;
    vecTests.push_back(t);

    return 0;
}