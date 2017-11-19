#include <string>
#include <iostream>

// for nothrow and bad_alloc
#include<new>

using namespace std;

class Test
{
    public:
    Test() {cout << "Test" << endl;}
};

int main(void)
{
    string *a = new string; // default initialize empty string.
    string *b = new string(); // value initialize empty string.

    int *pi1 = new int; // default initialize *pi1 is not defined/
    int *pi2 = new int(); // value initialize 0; *pi2 is 0.

    Test *t = new Test;
    Test *t1= new Test();

    auto pp = new auto(1);
    auto pp1 = new auto("DDDDDDDDDD");

    const int *toConst = new const int(100);

    // return null if there are not enough memory to new.
    int *ppNoThrow = new(nothrow) int;

    return 0;
}