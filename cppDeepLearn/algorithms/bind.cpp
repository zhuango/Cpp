#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int main(void)
{
    auto newCallable = bind(check_size, _1, 10);
    cout << newCallable("sdfsdf") << endl;
    cout << newCallable("sdfsdfddddddddddd") << endl;

    return 0;
}