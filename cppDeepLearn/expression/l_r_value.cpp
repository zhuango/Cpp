#include <iostream>
using namespace std;
int main(void)
{
    int i = 100;
    // Assignment requires a (nonconst) lvalue as its left-hand operand 
    // and yields itsleft-hand operand as an lvalue.
    (i = 200) = 300;
    cout << i << endl;

    
    return 0;
}