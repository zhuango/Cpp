#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s = "some string";
    string s2 = "some other string";
    s.insert(s.begin(), s2.begin(), s2.end());
    cout << "insert iterators version: " << s << endl;

    s = "some string";
    s.insert(0, s2);
    cout << "insert string at given position: " << s << endl;

    s = "some string";
    s.insert(0, s2, 0, s2.size());
    cout << "insert positional version : " << s << endl;

    s = "some string";
    s.insert(0, s2, 0, s2.size());
    cout << "insert positional version: " << s << endl;

    return 0;
}