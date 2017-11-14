#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(void)
{
    vector<int> vec0({6, 7, 7, 8, 9});
    vector<int> vec({1, 2, 3, 4, 5});
    auto bInserter = back_inserter(vec);
    // back_insert_iterator<vector<int>> bInserter = back_inserter(vec);
    copy(vec0.cbegin(), vec0.cend(), bInserter);

    for(auto &a: vec) {cout << a << " ";};
    cout << endl;

    list<int> li({10});
    front_insert_iterator<list<int>> fInserter = front_inserter(li);
    copy(vec0.cbegin(), vec0.cend(), fInserter);
    for(auto &a : li) { cout << a << " "; };
    cout << endl;

    list<int> lli({10, 11, 12});
    insert_iterator<list<int>> inserte = inserter(lli, lli.begin());
    copy(vec0.cbegin(), vec0.cend(), inserte);
    for(auto &a: lli) { cout << a << " ";};
    cout << endl;

    return 0;
}