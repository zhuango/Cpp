#include <iostream>
#include <map>
using std::multimap;
#include <string>
#include <utility>
using std::pair;
using namespace std;

int main(void)
{
    multimap<string, string> authors;
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});

    string search_item("Alain de Botton");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);

    while(entries)
    {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
         beg != end; ++beg)
    {
        cout << beg->second << endl;
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    // Returns the bounds of the subrange that includes all the elements of the range [first,last) with values equivalent to val.
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
    {
        cout << pos.first->second << endl;
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    return 0;
}