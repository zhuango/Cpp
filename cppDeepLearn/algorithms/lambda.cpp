#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int justReturn(int &c)
{
    return ++c;
}

class Test
{
public:
    int data = 100;
};

Test justReturnObj(Test &t)
{
    t.data = t.data + 1;
    return t;
}

void justSetObj(Test &t)
{
    t.data = t.data + 1;
}

int main(void)
{
    vector<string> strs({"21312", "aaa", "dss", "wewww", "S", "a@@", "asssssssss"});
    sort(strs.begin(), strs.end(), isShorter);
    //stable_sort(strs.begin(), strs.end(), isShorter);
    for(auto &a : strs) { cout << a << " "; }
    cout << endl;

    // [capture list] (parameter list) -> return type { function body }
    auto f = [] {return 42;};
    cout << f() << endl;

    vector<string> strs1({"21312", "aaa", "dss", "wewww", "S", "a@@", "asssssssss"});
    stable_sort(strs1.begin(), strs1.end(), [](const string &a, const string &b){return a.size() < b.size();});
    for(auto &a: strs1) { cout << a << " "; };
    cout << endl;

    int sz = 3;

    auto wc = find_if(strs1.cbegin(), strs1.cend(), 
                    [sz](const string &a){return a.size() >= sz;});
    
    // The capture list is used for local nonstatic variables only; lambdas can use
    // local statics and variables declared outside the function directly.
    if(wc != strs.cend())
    {
        cout << *wc << endl;
        for_each(wc, strs1.cend(), [](const string &a){cout << a << " ";});
        cout << endl;
    }

    int a = 100;
    auto fff = [a]{return a;};
    auto fff1 = [&a]{return a;};
    a = 0;
    cout << fff() << endl;
    cout << fff1() << endl;

    // if there is no mutable and captured by value, Error: increment of read-only variable ‘a’
    // if mutable is there, then () must not be omit.
    auto fmu = [a] () mutable {return ++a;};
    cout << fmu() << endl;

    int te = 100;
    auto fmuR = [&te] () {++te; };

    int b = 12;
    auto fmuRR= [](int &a) {return ++a;};
    cout << fmuRR(b) << endl;
    cout << b << endl;

    int c = 100;
    auto fmuref= [&c](){ return justReturn(ref(c)); };
    cout << fmuref() << endl;

    Test t;
    auto fmurefClass = [&t]() {return justReturnObj(t);};
    cout << fmurefClass().data << endl;

    auto fmurefClass1 = [&t]() {return justSetObj(ref(t));};
    fmurefClass1();
    cout << t.data << endl;

    thread *th = new thread(fmurefClass1);
    th->join();
    delete th;

    return 0;
}