#include <algorithm>
#include <functional>
using std::bind;
// namespace placeholders {
//   extern /* unspecified */ _1;
//   extern /* unspecified */ _2;
//   extern /* unspecified */ _3;
//   // ...
// }
using namespace std::placeholders;
#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

int main(void)
{
    string s;
    vector<string> words;
    while(cin >> s)
    {
        words.push_back(s);
    }

    for_each(words.begin(), words.end(), bind(print, ref(cout), _1, ' '));
    cout << endl;

    ofstream os("outFile1");
    for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));

    os << endl;

    ifstream is("outFile1");
    istream_iterator<string> in(is), eof;
    for_each(in, eof, bind(print, ref(cout), _1, '\n'));
    cout << endl;

    return 0;
}