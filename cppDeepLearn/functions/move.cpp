#include <algorithm>
using std::for_each;
#include <utility>
using std::move;
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Test
{
    public:
        Test(int s){ i = s; }
        void print() { cout << i << endl; }
        void set(int ei){ i = ei; }
    private:
        int i;
};

void TestMove(vector<Test> &myTests)
{
    Test a(1);
    myTests.push_back(a);
    // another version of push_back which takes a rvalue reference arg,
    // and moves to a 
    myTests.push_back(Test(200));
    Test b(10);
    //Returns an rvalue reference to arg.
    myTests.push_back(move(b));

    cout << "b: ";
    b.print();

    a.set(1000);
}
int main(void)
{
    string foo = "foo-string";
    string bar = "bar-string";
    vector<string> myvector;

    myvector.push_back(foo); // copies
    myvector.push_back(move(bar)); // remove
    cout << "++++++" << bar << "++++++" << endl; //empty.
    cout << "myvector contains: ";
    for (auto &s : myvector)
    {
        cout << ' ' << s;
    }
    cout << endl;

    vector<Test> myTests;
    TestMove(myTests);
    for_each(myTests.begin(), myTests.end(), [](Test t) { t.print(); });

    return 0;
}