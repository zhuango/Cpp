#include <iostream>
using namespace std;

// with out this declaration, testFriendShip cannot call friendFunc
void friendFunc();

class Test
{
    //A friend declaration affects access but is not a declaration in an ordinary sense.
    friend void friendFunc(){cout << "we are friend ?" << endl;}

public:
    void testFriendShip(){friendFunc(); cout << "yes" << endl;}
};

int main(void)
{
    Test test;
    test.testFriendShip();
}