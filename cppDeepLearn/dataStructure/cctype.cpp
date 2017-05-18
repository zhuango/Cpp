#include <string>
#include <cctype>
#include <iostream>
using namespace std;

int main(void)
{
    string s("Hello World!!");
    decltype(s.size()) punct_cnt = 0;

    for(auto c : s)
    {
        if (ispunct(c))
            ++punct_cnt;
    }
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
    string orig = s;
    for (auto &c : s)
    {
        c = toupper(c);
    }
    cout << s << endl;

    s = orig;
    decltype(s.size()) index = 0;

    while(index != s.size() && !isspace(s[index]))
    {
        s[index]= toupper(s[index]);
        ++index;
    }
    cout << s << endl;
}