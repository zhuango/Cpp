#include <iostream>
using namespace std;

class Employee
{
  public:
    Employee() : id(++unique){};
    Employee(string &s) : name(s), id(++unique) {}

  private:
    string name;
    int id;

    static int unique;
};

int Employee::unique = 0;

int main(void)
{

    return 0;
}