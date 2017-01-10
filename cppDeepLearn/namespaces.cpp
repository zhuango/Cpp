#include <iostream>
#include <exception>

using namespace std;

namespace ContosoData
{
    class ObjectManager
    {
        public:
            void DoSomething()
            {
                cout << "in ObjectManager" << endl;
            }
    };
    void Func(ObjectManager mgr)
    {
        mgr.DoSomething();
    }
}
void direct()
{
    ContosoData::ObjectManager mgr;
    mgr.DoSomething();
    ContosoData::Func(mgr);
}
void usingNamespace()
{
    using namespace ContosoData;

    ObjectManager mgr;
    mgr.DoSomething();
    Func(mgr);
}
void usingIden()
{
    using ContosoData::Func;
    using ContosoData::ObjectManager;

    ObjectManager mgr;
    mgr.DoSomething();
    Func(mgr);
}
int main(void)
{
    direct();
    usingNamespace();
    usingIden();
    return 0;
}