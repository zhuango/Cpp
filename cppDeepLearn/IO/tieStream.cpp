#include <iostream>
#include <fstream>

using namespace std;
int main(void)
{
    // The tied stream is an output stream object which is flushed 
    // before each i/o operation in this stream object.
    *cerr.tie() << "This is tie stream of cerr. (cout)" << endl;
    *cin.tie() << "This is tie stream of cin. (cout)" << endl;
 
    ostream *os;
    ofstream f;
    f.open("test.txt");

    os = cin.tie(&f);
    *cin.tie() << "This is inserted into the file" << endl;

    string str;
    cin >> str;
    cout << str << endl;
    
    return 0;
}
