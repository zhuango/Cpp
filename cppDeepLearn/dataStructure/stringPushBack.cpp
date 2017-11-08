#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

int main(void)
{
    string s = "liuzhuang";
    s.push_back('2');
    cout << s << endl;

    vector<int> vec(10, 2);
    // has no push_front
    // vec.push_front(10);

    list<int> li(10,2);
    li.push_front(10);
    for(auto &a: li) {cout << a << " ";};
    cout << endl;

    li.push_back(1);
    for(auto &a: li) {cout << a << " ";};
    cout << endl;

    forward_list<int> fli(3, 10);
    fli.push_front(12);
    // has no push_back
    // fli.push_back(0);
    for(auto &a: fli) {cout << a << " ";};
    cout << endl;

    return 0;
}