#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<string, size_t> word_count;
    word_count["Anna"] = 1;
    cout << word_count["Anna"] << endl;

    ++word_count["Anna"];
    cout << word_count["Anna"] << endl;

    string word = "AA";
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));

    typedef map<string, size_t>::value_type valType;
    word_count.insert(valType(word, 1));

    pair<map<string, size_t>::iterator, bool> insert_ret;
    insert_ret = word_count.insert({"Anna", 1});
    if (insert_ret.second == false)
    {
        insert_ret.first->second++;
    }
    cout << word_count["Anna"] << endl;

    auto map_it = word_count.begin();
    cout << map_it->first;
    cout << " " << map_it->second;
    ++map_it->second;

    return 0;
}