#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> aa(4, 1);
    vector<int> bb(2, 3);
    aa = bb;
    // two elements
    for(auto &a:aa){cout << a << " ";}
    cout << endl;

    aa = vector<int>(10, 5);
    for (auto &a:aa) {cout << a << " ";}
    cout << endl;

    aa = {1, 2, 3, 4};
    for (auto &a:aa) {cout << a << " ";}
    cout << endl;

    swap(aa, bb);
    for(auto &a:aa) {cout << a << " ";}
    cout << endl;
    for(auto &a:bb) {cout << a << " ";}
    cout << endl;

    aa.swap(bb);
    for(auto &a:aa) {cout << a << " ";}
    cout << endl;
    for(auto &a:bb) {cout << a << " ";}
    cout << endl;

    bb.assign(aa.begin(), aa.end());
    for(auto &a:bb) {cout << a << " ";}
    cout << endl;

    aa.assign(6, -1);
    for(auto &a:aa){cout << a << " ";}
    cout << endl;

    aa.assign({1, 2, 3, 4, 5, 6, 7, 8});
    for(auto &a:aa){cout << a << " ";}
    cout << endl;

    aa.assign(aa.begin(), aa.end() - 2);
    for(auto &a:aa) {cout << a << " ";}
    cout << "\n" << aa.size() << endl;

    return 0;
}