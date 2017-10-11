#include <iostream>
using namespace std;
int main(void)
{
    int i = 1, j = 2;
    // Any well-defined type conversion, 
    // other than those involving low-level const, 
    // can be requested using a static_cast
    // A static_cast is often useful when a larger arithmetic type is assigned to a smaller type.
    double slope = static_cast<double>(j) / i;
    
    int d = 100;
    void *p = &p;
    int *dp = static_cast<int*>(p);

    // A const_cast changes only a low-level const in its operand
    // using a const_cast in order to write to a const object is undefined.
    // we cannot use a const_cast to change the type of an expression
    const char *pc;
    char *p1 = const_cast<char *>(pc);

    char str[] = "nullptr";
    char str1[] = "liuzhuang";
    char *const pc1 = str;
    char *p2 = const_cast<char*>(pc1);

    // A reinterpret_cast generally performs a low-level 
    // reinterpretation of the bit pattern of its operands. 
    int *pint;
    char *pchar = reinterpret_cast<char*>(pint);

    int ii;
    double dd;
    const string *ps;
    char *pcc ="a";
    void *pv;

    cout << "DDDDDDDDD" << endl;
    pv = static_cast<void*>(const_cast<string*>(ps));
    cout << "DDDDDDDDD" << endl;
    ii = static_cast<int>(*pcc);
    cout << "DDDDDDDDD" << endl;
    pv = static_cast<void*>(&dd);
    cout << "DDDDDDDDD" << endl;
    pv = reinterpret_cast<void*>(&dd);

    return 0;
}