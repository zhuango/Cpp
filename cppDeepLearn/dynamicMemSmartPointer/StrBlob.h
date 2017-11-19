#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class StrBlob
{
    public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> li);
    ~StrBlob(){cout << "mea" << endl;}
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const string &t){data->push_back(t);}
    void pop_back();
    string &back();
    string &front();


    private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type index, const std::string &msg)const;
};