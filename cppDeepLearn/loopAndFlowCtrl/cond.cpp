#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<unsigned> grades;

int main()
{
    unsigned i;
    while (cin >> i)
    {
        grades.push_back(i);
    }
    for (auto grade : grades)
    {
        string finalgrade =(grade < 60) ? "fail" : "pass";
        finalgrade = (grade > 90) ? "high pass"
                                    : (grade < 60) ? "fail" : "pass";
        cout << grade << " " + finalgrade << endl;
    }
    return 0;
}
