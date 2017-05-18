#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<string> text;

    string s;
    // ctrl-d to stop.
    while(getline(cin, s))
    {
        text.push_back(s);
    }
    cout << "text.size: " << text.size() << endl;

    for (auto it = text.cbegin(); 
        it != text.cend() && !(*it).empty(); ++it)
    {
        cout << *it << endl;
    }
    cout << "+++++++++++++++++++++++" << endl;
    for (auto it = text.cbegin();
        it != text.cend() && !it->empty(); ++it)
    {
        cout << *it << endl;
    }
    cout << "+++++++++++++++++++++++" << endl;
    return 0;
}