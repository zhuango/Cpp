#include<list>
struct ListNode
{
    int Data;
    ListNode *Next;
};

template<class item_type>
class List
{
    public:
        List(item_type)
        List *Search(item_type x);
        List *Insert();
        List *Precursor();
    private:
        ListNode *mHead;
};
