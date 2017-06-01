#include <iostream>
using namespace std;

int main(void)
{
    cout << "Standard Clib: " << __STDC_HOSTED__ << endl;
    cout << "Standard C: " << __STDC__ << endl;
    //cout << "C Standars Version: " << __STDC_VERSION__ << endl;
    cout << "IOS/IEC " << __STDC_ISO_10646__ << endl;

    return 0;
}