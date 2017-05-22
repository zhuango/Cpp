#include <iostream>
#include <functional>
#include <string>
using namespace std;

int main()
{
    char nts1[] = "Test";
    chat nts2[] = "Test";
    std::string str1(nts1);
    std::string str2(nts2);

    std::hash<char *> ptr_hash;
    std::hash<std::string> str_hash;

    cout << ptr_hash(nts1) == ptr_hash(nts2) << endl;
    cout << str_hash(str1) == str_hash(str2) << endl;

    return 0;
}