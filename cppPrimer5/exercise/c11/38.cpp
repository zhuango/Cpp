#include <unordered_map>
#include <iostream>

using namespace std;

int main(void)
{
    unordered_map<string, size_t> wordCount;
    string s;
    while(cin >> s)
    {
        ++wordCount[s];
    }
    for (const auto &s : wordCount)
    {
        cout << s.first << "   " << s.second << endl;
    }

    return 0;
}