#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

string format(const string &s)
{
    return s;
}

bool valid(const string &s)
{
    return true;
}

vector<PersonInfo>
getData(istream &is)
{
    string line, word;
    vector<PersonInfo> people;

    while(getline(is, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    return people;
}

ostream &process(ostream &os, vector<PersonInfo> people)
{
    for (const auto &entry : people)
    {
        ostringstream formatted;
        ostringstream badNums;
        for (const auto &nums : entry.phones)
        {
            if (valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
        {
            os << entry.name << " "
               << formatted.str() << endl;
        }
        else
        {
            cerr << "input error: " << entry.name
                 << " invalid numbers(s) " << badNums.str() << endl;
        }
    }
    return os;
}

void testProcess()
{
    process(cout, getData(cin));
}
int main(void)
{
    istringstream is;
    is.
    return 0;
}