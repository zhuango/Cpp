#include<iostream>
using namespace std;

void test()
{
    // Error, has both extern and initializer.
    //extern int externalVariable = 1;
    cout << externalVariable << endl;
}
int main(void)
{
    test();
    extern int externalVariable;
    cout << externalVariable << endl;

    return 0;
}