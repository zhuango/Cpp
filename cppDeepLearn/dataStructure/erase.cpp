#include <algorithm>
using std::find;
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    /*
sequence (1)    string& erase (size_t pos = 0, size_t len = npos);
character (2)   iterator erase (const_iterator p);
range (3)       iterator erase (const_iterator first, const_iterator last);
    */
    list<string> slist;
    string s;
    while (cin >> s)
    {
        slist.push_back(s);
    }

    auto iter = find(slist.begin(), slist.end(), "zhuangliu");
    if (iter != slist.end())
    {
        slist.erase(iter);
    }

    auto orig = slist;
    slist.clear();
    cout << "after clear, size is: " << slist.size() << endl;

    slist = orig;
    slist.erase(slist.begin(), slist.end());
    cout << "after erase begin to end, size is: " << slist.size() << endl;

    slist = orig;
    auto elem1 = slist.begin();
    auto elem2 = slist.end();

    elem1 = slist.erase(elem1, elem2);
    cout << "after erase elem1 to elem2 size is:  " << slist.size() << endl;

    if (elem1 != elem2)
    {
        cout << "simethings wrong" << endl;
    }
    else
    {
        cout << "okay, they'are equal" << endl;
    }
    return 0;
}