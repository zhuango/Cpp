#include <iostream>
#include <string>
#include <algorithm>
using std::for_each;
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;

using namespace std;

int main(void)
{
    int v1(1024);   // direct-initialization, functional form
    int v2{1024};   // direct-initialization, list initializer form
    int v3 = 1024;  // copy-initialization
    int v4 = {1024};// copy-initialization, list initializer form

    string titleA = "zhuangliu, student.";
    string titleB("zhuanglium student.");
    string all_nines(10, '9');

    initializer_list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec = li;
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    cout << endl;

    vector<int> vec2(li);
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    cout << endl;
    
    return 0;
}