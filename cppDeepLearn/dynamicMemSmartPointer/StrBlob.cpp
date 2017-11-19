#include "StrBlob.h"

StrBlob::StrBlob() : data(make_shared<std::vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> li): data(make_shared<std::vector<string>>(li)){}
void StrBlob::check(size_type index, const string &msg) const
{
    if (index >= data->size())
    {
        throw out_of_range(msg);
    }
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}