#include <string>
#include <iostream>
using std::string;
using std::to_string;
using std::stod;
using std::cout;
using std::endl;

int main(void)
{
    int i = 12;
    string si = to_string(i);
    cout << si << endl;

    double fromstr = stod("12.3");
    cout << fromstr << endl;
}