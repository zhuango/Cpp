#include <list>
#include <forward_list>
#include <iostream>
using namespace std;

int main(void)
{
    // doubly linked list.
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "initial list: ";
    for (auto it : lst)
    {
        cout << it << " ";
    }
    cout << endl;

    auto it = lst.begin();
    while (it != lst.end())
    {
        if (*it % 2)
        {
            it = lst.erase(it);
        }
        else
        {
            ++it;
        }
    }

    cout << "after erasing odd elements from lst: ";
    for (auto it : lst)
    {
        cout << it << " ";
    }
    cout << endl;

    //singly linked list.
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "initial list: ";
    for (auto it : flst)
    {
        cout << it << " ";
    }
    cout << endl;

    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    cout << "after erasing elements from flst: ";
    for(auto it : flst)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}