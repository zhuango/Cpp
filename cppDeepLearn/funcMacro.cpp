#include <iostream>
using namespace std;
void print()
{
    cout << __func__ << endl;
}

void print1()
{
    cout << __func__ << endl;
}

struct TestStruct
{
    TestStruct() : name(__func__){}
    const char * name;
};

int main(void)
{
    print();
    print1();

    TestStruct ts;
    cout << ts.name << endl;
    return 0;
}