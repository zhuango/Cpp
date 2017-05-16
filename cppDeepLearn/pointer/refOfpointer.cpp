#include <iostream>
using namespace std;

int main(void)
{
    int i = 1024;
    // pointer
    int *p = &i;
    // ref
    int &r = i; 
    // 1024 1024 1024
    cout << i << " " << *p << " " << r << endl;
    
    int j = 42;
    int *p2 = &j;
    int *&pref = p2;

    //42
    cout << *pref << endl;

    pref = &i;
    // 1024
    cout << *pref << endl;

    *pref = 0;
    //0 0
    cout << i << " " << *pref << endl;

    return 0;
    
}