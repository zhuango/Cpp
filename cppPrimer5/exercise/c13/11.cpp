#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr & hasptr):ps(new string(*hasptr.ps)), i(hasptr.i)
    { }
    HasPtr & operator= (const HasPtr & hp);
    
    ~HasPtr()
    {
        delete ps;
        ps = nullptr;
    }
    private:
    string *ps;
    int i;
};

HasPtr & HasPtr::operator= (const HasPtr & hp)
{
    string *newps = new string(*hp.ps);
    delete ps;
    ps = newps;
    i = hp.i;
    return *this; 
}

int main(void)
{
    return 0;
}