// A union is a user-defined type in which all members share the same memory location. 
// This means that at any given time a union can contain no more than one object from its list of members.
// It also means that no matter how many members a union has,
// it always uses only enough memory to store the largest member.

// Unions can be useful for conserving memory when you have lots of objects and/or limited memory.
// However they require extra care to use correctly because you are responsible for ensuring 
// that you always access the last member that was written to.
// If any member types have a non-trivial constructor,
// then you must write additional code to explicitly construct and destroy that member.
// Before using a union, consider whether the problem you are trying to solve could be better 
// expressed by using a base class and derived classes.
#include <iostream>
#include <queue>
using namespace std;

namespace BaseUnionTest
{
    union RecordType
    {
        char    ch;
        int     i;
        long    l;
        float   f;
        double  d;
        int     *int_ptr;
    };

    void testSize()
    {
        cout << "union size: " << sizeof(RecordType) << endl;
    }
    void testBase()
    {
        RecordType t;
        t.i = 5;    // t holds an int
        t.f = 7.25; // t now holds a float
    }
}

namespace DiscriminatedUnionTest
{
    // Of course, the example shows a problem that could also be solved by using classes that derive from
    // a common base class, and branching your code based on the runtime type of each object in the container.
    // This may result in code that easier to maintain and understand, but it might also be slower than 
    // using unions. Also, with a union, you can store completely unrelated types, 
    // and dynamically change the type of the value that is stored without changing the type of the union 
    // variable itself. Thus you can create a heterogeneous array of MyUnionType whose elements store different
    // values of different types. Note that the Input struct in the preceding example can be easily misused.
    // It is completely up to the user to use the discriminator correctly to access the member that holds 
    // the data.You can protect against misuse by making the union private and providing special access functions.
    enum class WeatherDataType
    {
        Temperature, Wind
    };

    struct TempData
    {
        int StationId;
        time_t time;
        double current;
        double max;
        double min;
    };

    struct WindData
    {
        int StationId;
        time_t time;
        int speed;
        short direction;
    };
    
    struct Input
    {
        WeatherDataType type;
        // In the  example, note that the union in the Input struct has no name. 
        // This is an anonymous union and its members can be accessed 
        // as if they were direct members of the struct. 
        // Names declared in an anonymous union are used directly, like nonmember
        // variables. Therefore, the names declared in an anonymous union must be 
        // unique in the surrounding scope.
        // In addition to the restrictions listed in Union Member Data, anonymous 
        // unions are subject to additional restrictions:
        //    1.They must also be declared as static if declared in file or namespace scope.
        //    2.They can have only public members; private and protected members in anonymous
        //unions generate errors.
        //    3.They cannot have member functions.
        union
        {
            TempData temp;
            WindData wind;
        };
    };

    void ProcessTemp(TempData t){}
    void ProcessWind(WindData w){}

    queue<Input> inputs;
    void Initialize()
    {
        Input first, second;
        first.type = WeatherDataType::Temperature;
        first.temp = { 101, 1418855664, 91.8, 108.5, 67.2 };
        inputs.push(first);


        second.type = WeatherDataType::Wind;
        second.wind = { 204,1418859354, 14, 27 };
        inputs.push(second);
    }
    void test()
    {
        Initialize();
        while( !inputs.empty() )
        {
            Input i = inputs.front();
            
            switch(i.type)
            {
                case WeatherDataType::Temperature:
                    ProcessTemp(i.temp);
                    break;
                case WeatherDataType::Wind:
                    ProcessWind(i.wind);
                    break;
                default:
                    break;
            }
            inputs.pop();
        }
    }
}

int main(void)
{

    BaseUnionTest::testBase();
    BaseUnionTest::testSize();
    DiscriminatedUnionTest::test();

    return 0;
}