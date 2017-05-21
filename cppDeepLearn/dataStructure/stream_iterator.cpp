#include <numeric>
using std::accumulate;
#include <iostream>
#include <iterator>
using namespace std;

int main(void)
{
    istream_iterator<int> in(cin);
    istream_iterator<int> eof;
    cout << accumulate(in, eof, 0) << endl;
    // operator++ of istream_iterator: Internally, the function extracts an element from its associated stream and stores it internally to be returned when dereferenced.
    cout << (*in.operator->()) << endl;
    cout << *in << endl;
    return 0;
}