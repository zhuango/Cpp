#include <map>
using std::map;
#include <set>
using std::set;
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "Or", "An", "A",
	                       "the", "but", "and", "or", "an", "a"};
    string word;

    while(cin >> word)
    {
        if(exclude.find(word) == exclude.end())
        {
            ++word_count[word];
        }
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}