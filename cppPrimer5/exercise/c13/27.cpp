#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
  public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new int(0)) {}
    HasPtr(const HasPtr &hasptr) : ps(hasptr.ps), i(hasptr.i), use(hasptr.use)
    {
        ++*hasptr.use;
    }
    HasPtr &operator=(const HasPtr &hp);

    ~HasPtr()
    {
        if (--*this->use == 0)
        {
            delete ps;
            delete use;
        }
    }

  private:
    string *ps;
    int i;
    int *use;
};

HasPtr &HasPtr::operator=(const HasPtr &hp)
{
    if (--this->use == 0)
    {
        delete ps;
        delete use;
    }
    ps = hp.ps;
    i = hp.i;
    *use = ++*hp.use;
    return *this;
}

int main(void)
{
    return 0;
}