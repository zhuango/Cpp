#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> a(10, 1);
    for(auto &a : a)
    {
        cout << a << " ";
    }
    cout << endl;

    vector<int>::difference_type distance = a.begin() - a.end();
    cout << distance << endl;

    // vector<int>::difference_type distance2 = a.begin() + a.end();
    // cout << distance2 << endl;
    return 0;
}