#include <iostream>
#include <set>
using std::set;
using std::multiset;

#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());

    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;

    auto iter = iset.find(1);
    cout << *iter << endl;
    auto end = iset.find(11);
    cout << iset.count(1) << endl;
    cout << iset.count(11) << endl;

    cout << miset.count(1) << endl;
    cout << miset.count(11) << endl;

    set<string> set1;
    set1.insert("the");
    set1.insert("and");

    ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    set2.insert({1, 3, 5, 7, 1, 3, 5, 7});
    
    return 0;
}