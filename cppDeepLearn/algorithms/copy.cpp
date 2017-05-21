#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

void print(const string &label, const list<int> &lst)
{
    cout << label << endl;
    for (auto iter : lst)
    {
        cout << iter << " ";
    }
    cout << endl;
}

int main(void)
{
    list<int> lst = {1, 2, 3, 4};
    print("lst", lst);

    list<int> lst2, lst3;
    copy(lst.begin(), lst.end(), front_inserter(lst2));

    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    print("lst2", lst2);
	print("lst3", lst3);

    vector<int> v = {1, 2, 3, 4, 5};
    list<int> new_lst = {6, 7, 8, 9};
    auto it = new_lst.begin();
    copy(v.begin(), v.end(), inserter(new_lst, it));
    print("new_lst", new_lst);

    cout << "unique copy++++++++++++++++" << endl;
    istream_iterator<int> init_it(cin);
    istream_iterator<int> init_eof;
    vector<int> vec(init_it, init_eof);
    sort(vec.begin(), vec.end());
    ostream_iterator<int> out(cout, " ");
    unique_copy(vec.begin(), vec.end(), out);
    cout << endl;
    ofstream out_file("outFile2");
    ostream_iterator<int> out_iter(out_file, " ");
    copy(vec.begin(), vec.end(), out_iter);
    out_file << endl;

    return 0;
}