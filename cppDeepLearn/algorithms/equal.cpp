#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    list<const char *> roster1;
    vector<string> roster2;
    roster2 = {"hello", "so long", "tata"};
    roster1 = {"hello", "so long"};


	// roster2 should have at least as many elements as roster1
    auto b = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

    (b) ? cout << "true" : cout << "false";
    cout << endl;
    return 0;
}