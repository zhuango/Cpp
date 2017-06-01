#include <iostream>
using namespace std;

struct People
{
    public:
        int hand;
        static People * all;
};

int main(void)
{
    People p;
    cout << sizeof(p.hand) << endl;
    cout << sizeof(People::all) << endl;
    // a Error in C++98, can not sizeof to a no-static member through class name.
    cout << sizeof(People::hand) << endl; 
    cout << sizeof(((People*)0)->hand) << endl;

    return 0;
}