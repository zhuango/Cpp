#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    ofstream of;
    of.open("test", ofstream::ate|ofstream::out);
    of << "zhuangliu" << endl;

    return 0;
}