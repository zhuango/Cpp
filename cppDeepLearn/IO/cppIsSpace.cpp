#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::isspace
#include <string>
using namespace std;

int main()
{
    locale loc;
    string str = "Example sentence to test isspace\n";
    char c;

    for (string::size_type i = 0; i < str.length(); ++i)
    {
        c = str[i];
        if (isspace(c, loc)) c = '\n';
        cout << c;
    }
}