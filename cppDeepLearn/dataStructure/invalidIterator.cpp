#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vi = {0, 1, 2, 3, 4, 5};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            // advance past this element and the one inserted before it
            iter += 2;
        }
        else
        {
            // don't advance the iterator; iter denotes the element after the one we erased
            iter = vi.erase(iter);
        }
    }

}