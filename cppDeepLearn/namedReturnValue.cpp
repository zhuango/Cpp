#include <iostream>
using namespace std;

class test;
class testWithCopyConstructor;

test foo(double val)
{
    test local;

    local.array[0] = val;
    local.array[99] = val;
    return local;
}


testWithCopyConstructor fooWithCC(double)
{
    testWithCopyConstructor local;

    local.array[0] = val;
    local.array[99] = val;
    return local;
}

class test
{
    friend test foo(double);
    public:
    test()
    {
        memset(array, 0, 100 * sizeof(double));
    }
    private:
    double array[100];
};

class testWithCopyConstructor
{
    friend testWithCopyConstructor fooWithCC(double);
    public:
    inline test(const test &t)
    {
        memcpy(this, &t, sizeof(test));
    }    
    test()
    {
        memset(array, 0, 100 * sizeof(double));
    }
    private:
    double array[100];
};

int main(void)
{
    for (int cnt = 0; cnt < 10000000; cnt++)
    {
        test t = foo(double(cnt));
    }
    cout << "=======================" << endl;
    for (int cnt = 0; cnt < 10000000; cnt++)
    {
        testWithCopyConstructor t = fooWithCC(double(cnt));
    }
    cout << "=======================" << endl;
    return 0;
}