#include <iostream>
#include <string>

using namespace std;

void readLineTest()
{
    char line[256];
    char ch;
    cin >> ch;
    cout << "#########" << ch << "##############" << endl;
    cin.getline(line, 256);
    cout << line;

    string str;
    getline(cin, str);
    cout << str;
}
int main(void)
{
    int val0;
    int val1;
    int val2;
    cin >> val0 >> val1 >> val2;
    if (cin)
    {
        //Returns true if none of the stream's error state flags (eofbit, failbit and badbit) is set.
        std::cout << "success!" << cin.good() << endl;
    }
    else
    {
        std::cout << "failed!" << cin.good() << endl;
    }

    //equals to
    //Returns whether an error flag is set (either failbit or badbit).
    //The function returns false if at least one of these error flags is set, and true otherwise.
    cout << cin.operator bool() << endl;
    return 0;
}