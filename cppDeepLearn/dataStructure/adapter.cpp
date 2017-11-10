#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    deque<int> deq(10, 3);
    // by default, stack use the deque as its underlaying implement.
    stack<int> stk(deq);
    while(!stk.empty()) { cout << stk.top() << " "; stk.pop();}
    cout << endl;

    vector<int> vec(10 , 2);
    stack<int, vector<int>> stk_vec(vec);
    while(!stk_vec.empty()) { cout << stk_vec.top() << " "; stk_vec.pop(); }
    cout << endl;

    for (int i = 0; i < 10; ++i)
    {
        stk_vec.push(i);
    }

    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << que.front() << endl;
    cout << que.back() << endl;
    que.pop();
    cout << que.front() << endl;
    cout << que.back() << endl;

    priority_queue<int> pque;
    pque.push(11);
    pque.push(1);
    pque.push(200);
    pque.push(23);
    cout << pque.top() << endl;
    pque.pop();
    cout << pque.top() << endl;
    pque.pop();
    cout << pque.top() << endl;
    pque.pop();
    cout << pque.top() << endl;



    return 0;
}