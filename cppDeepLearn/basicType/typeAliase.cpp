#include <iostream>
using namespace std;
int main(void)
{
    typedef double wages;
    wages a = 100;

    typedef wages base, *p;
    p b = nullptr;

    typedef char *pstring;
    const pstring cstr = 0;// cstr is a constant pointer to char
    const pstring *ps;// ps is a pointer to a constant pointer to char
    return 0;
}
