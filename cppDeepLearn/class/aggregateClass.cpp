#include <iostream>
#include <string>
using namespace std;


// All of its data members are public
// • It does not define any constructors
// • It has no in-class initializers (§ 2.6.1, p. 73)
// • It has no base classes or virtual functions, which are class-related features
struct Data
{
    int ival;
    string s;
};

int main(void)
{
    Data val1 = {0, "Anna"};
    // Data val2 = {"Anna", 1024};
    Data val3 = {0};
}