#include <iostream>
#include <string>

using namespace std;

void readLineTest()
{
    char line[256];
    char ch;
    cin >> ch;
    cout << "#########" << ch << "##############" << endl;
    //from current char to the end of that line.(no "\n")
    cin.getline(line, 256);
    cout << "#######" << line << "###############" << endl;

    string str;
    getline(cin, str);
    cout << "#######" << str << "#######" << endl;
}

void flagCheck()
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
    
    // if cin failed above, then getline would not be execute.
    // operator << calls the sentry's constructor, which checks if any of the internal flags of
    // this stream is set.
    string str;
    getline(cin, str);
    cout << "#######" << str << "#######" << endl;
}
int main(void)
{
    flagCheck();
    //readLineTest();
    return 0;
}