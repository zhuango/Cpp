#include <iostream>
using namespace std;
int main(void)
{
    int ival = 10;
    ival + 1; // useless statement.
    cout << ival << endl;

    // null statement.
    string s;
    string sought = "liu";
    while( cin >> s && s != sought );
    cout << s << endl;


    return 0;
}