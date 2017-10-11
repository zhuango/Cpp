//https://msdn.microsoft.com/en-us/library/dd293608.aspx
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void testLambda()
{
    vector<int> v;
    for (int i = 1; i < 10; ++i)
    {
        v.push_back(i);
    }

    int eventCount = 0;
    for_each(v.begin(), v.end() ,[&eventCount] (int n)
    {
        cout << n;
        if (n % 2 == 0)
        {
            cout << " is even " << endl;
            ++eventCount;
        }
        else
        {
            cout << " is odd " << endl;
        }
    });

    cout << "There are " << eventCount
         << " even numbers in the vetor." << endl;
}

class FunctorClass
{
    public:
        explicit FunctorClass(int &eventCount)
            : m_eventCount(eventCount){ }
            
        // The function-call operator prints whether the number is  
        // even or odd. If the number is even, this method updates  
        // the counter.
        void operator() (int n) const
        {
            cout << n;

            if (n % 2 == 0)
            {  
                cout << " is even " << endl;  
                ++m_eventCount;  
            }
            else
            {  
                cout << " is odd " << endl;  
            }  
        }
    private:
        // Default assignment operator to silence warning C4512.  
        // FunctorClass &operator=(const FunctorClass&);
        int &m_eventCount;
};
void testFunctionObject()
{
    vector<int> v;
    for(int i = 1; i < 10; ++i)
    {
        v.push_back(i);
    }

    int eventCount = 0;
    for_each(v.begin(), v.end(), FunctorClass(eventCount));
}
int main()
{
    testLambda();
    testFunctionObject();
}