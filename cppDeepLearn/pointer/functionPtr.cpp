#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

string::size_type sumLength(const string &s1, const string &s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

decltype(sumLength) *getFunc(const string &);
auto getFunc(const string&) -> string::size_type(*)(const string&, const string&);
string::size_type (*getFunc(const string&))(const string &, const string&);

decltype(sumLength) * getFunc(const string &fetch)
{
    if (fetch == "sum")
    {
        return sumLength;
    }
    return largerLength;
}

int main(void)
{
	cout << getFunc("sum")("hello", "world!") << endl;    // prints 11
	cout << getFunc("larger")("hello", "world!") << endl; // prints 6

    return 0;
}