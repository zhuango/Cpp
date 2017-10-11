#include <iostream>
using namespace std;
int main(void)
{
    int i, j;
    while(cin >> i >> j)
    {
        try
        {
            if (i == j)
            {
                throw runtime_error("same Number!");
            }
            cout << i << " " << j << endl;
        }
        catch(runtime_error err)
        {
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
            {
                break;
            }
        }
    }
    return 0;
}