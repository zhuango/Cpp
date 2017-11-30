#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> strs = {"liuzhuag", "kaili", "ssss"};
    {
        vector<string> strs2 = {"aaa", "bbb", "ccc", "rrr"};
        strs = strs2;
        strs2.push_back("DDDDDDDDDD");
        cout << strs2.size() << endl;
    }
    cout << strs.size() << endl;


    return 0;
}