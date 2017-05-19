#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    vector<int> ivec;

    cout << "ivec size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    
    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
    {
        ivec.push_back(ix);
    }

    cout << "ivec size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    ivec.reserve(50);//sets capacity to at least 50; might be more

    cout << "ivec size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    
    while (ivec.size() != ivec.capacity())
    {
        ivec.push_back(0);
    }
    cout << "ivec size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    ivec.push_back(42);

    // size should be 51; capacity will be >= 51 and is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;
    
    ivec.shrink_to_fit();

    // size should be unchanged; capacity is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;

    return 0;
}