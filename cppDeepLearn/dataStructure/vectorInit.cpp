#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void)
{
    vector<string> vs1{"Hi"};
    for(auto &str : vs1) cout << str << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;

    vector<string> vs2{10, "Hi"};
    for(auto &str : vs2) cout << str << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;

    vector<int> v5(10, 1);
    for(auto &inte : v5) cout << inte << " ";
    cout << endl << "++++++++++++++++++++++++" << endl;

    vector<int> v6{10, 1};
    for(auto &inte : v6) cout << inte << " ";
    cout << endl << "++++++++++++++++++++++++" << endl;

    return 0;
}