#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    unordered_map<string, size_t> word_count;
    string word;
    while(cin >> word)
    {
        word_count[word] ++;
    }
    for(const auto &a : word_count)
    {
        cout << a.first << " occurs " << a.second
             << ((a.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}