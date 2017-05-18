#include <iostream>
using namespace std;

int main()
{
    char ch;
    unsigned vowelCnt = 0;
    unsigned otherCnt = 0;

    while (cin >> ch)
    {
        switch(ch)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                ++vowelCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }
    cout << "Number of vowels: \t" << vowelCnt << '\n'
         << "Total non-vowels: \t" << otherCnt << '\n';
    return 0;
}