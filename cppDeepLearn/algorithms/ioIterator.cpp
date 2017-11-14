#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

int main(void)
{
    istream_iterator<int> isIter(cin);
    // default init isEof as eof.
    istream_iterator<int> isEof;

    vector<int> vec;
    while(isIter != isEof)
    {
        //++ > *
        // ++ makes cin read a new int.
        // postfix increment read the stream and return the old value of the iterator.
        // dereference that iterator to get the previous value read from the stream.
        vec.push_back(*isIter++);
    }
    cout << "istream is : " << cin.good() << endl;
    cin.clear();
    cout << "istream is : " << cin.good() << endl;
    char a ;
    cin >> a;

    for(auto &a : vec) { cout << a << " ";};
    cout << endl;

    ifstream ifs("find.cpp");
    istream_iterator<string> isIterF(ifs);
    istream_iterator<string> fEof;
    vector<string> strs;
    while(isIterF != fEof)
    {
        ///cout << *isIterF << endl;
        strs.push_back(*isIterF++);
    }
    for (auto &a: strs) { cout << a << " ";};

    istream_iterator<int> isiter0(cin);
    vector<int> vec0(isiter0, isEof);
    for(auto & a : vec0) { cout << a << " "; };
    cout << endl;
    
    cin.clear();
    cin >> a;

    istream_iterator<int> isiter1(cin), eof1;
    cout << accumulate(isiter1, eof1, 1) << endl;
    cin.clear();
    cin >> a;

    {
        istream_iterator<int> *isiter = new istream_iterator<int>(cin);
        delete isiter;
    }
    cout << "DDDDDDDDDDDDDDDD" << endl;


    return 0;
}