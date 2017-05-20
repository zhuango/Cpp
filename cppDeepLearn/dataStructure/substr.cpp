#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    try
    {
        string s("hello world");
        cout << s.substr(0, 5) << endl;
        cout << s.substr(6) << endl;
        cout << s.substr(6, 11) << endl;
        cout << s.substr(12) << endl;
    }
    catch(out_of_range)
    {
        cout << "caught out_of_range" << endl;
    }
    return 0;
}