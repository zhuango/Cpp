#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

class Test
{
public:
    Test(int a){aa = a;}
private:
    int aa;
};

int main(void)
{
    Test t(100);
    // Error Test has no default constructor.
    // vector<Test> tests1(10);
    vector<Test> tests2(10, t);
    cout << (tests2.size()) << endl;

    using ListOfDeque = list<deque<int>>;
    typedef list<deque<int>> ListOfDeque;

    vector<int>::value_type aInt = 100;
    cout << aInt << endl;

    vector<int>::const_reference constRef = 231;
    // readOnly
    // constRef = 1;
    cout << constRef << endl;

    vector<int>::const_iterator constIter;
    return 0;
}