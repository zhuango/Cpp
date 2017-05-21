#include<algorithm>
using std::sort;
using std::for_each;
#include<functional>
using std::bind;
using namespace std::placeholders;
#include<string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isShorter(const string &s1, const string&s2)
{
    return s1.size() < s2.size();
}

bool LT(const string &s1, const string &s2)
{
    return s1 < s2;
}

void print(const vector<string> &words)
{
    for_each(words.begin(), words.end(), 
            [](const string &s){ cout << s << " "; });
    cout << endl;
}

int main(void)
{
    vector<string> words;
    string next_word;
    while(cin >> next_word)
    {
        words.push_back(next_word);
    }
    print(words);
    vector<string> cpy = words;
    sort(words.begin(), words.end());

    words = cpy;
    sort(words.begin(), words.end(), LT);
    print(words);

    words = cpy;
    sort(words.begin(), words.end());
    auto it = unique(words.begin(), words.end(), isShorter);
    print(words);
    
    words = cpy;
    stable_sort(words.begin(), words.end(), isShorter);
    print(words);

    words = cpy;
    sort(words.begin(), words.end(), bind(isShorter, _2, _1));
    print(words);

    return 0;
}