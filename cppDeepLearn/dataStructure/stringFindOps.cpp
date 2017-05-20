#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    string numbers("0123456789");
    string name("r2d2");
    // Searches the string for the first character 
    // that matches any of the characters specified in its arguments.
    auto pos = name.find_first_of(numbers);
    if (pos != string::npos)
    {
        cout << "found number at index: " << pos
             << " elements is " << name[pos] << endl;
    }
    else
    {
        cout << "no number in: " << name << endl;
    }
    pos = 0;
    while((pos = name.find_first_of(numbers, pos)) != string::npos)
    {
        cout << "found number at index: " << endl
             << " element is " << name[pos] << endl;
        ++ pos;
    }
    string river("Mississippi");
    // find string.
    auto first_pos = river.find("is");
    auto last_pos  = river.rfind("is");
    cout << "find returned: " << first_pos
         << "rfind returned: " << last_pos << endl;
    string dept("03714p3");
    pos = dept.find_first_not_of(numbers);
    cout << "first_not returned: " << pos << endl;
}