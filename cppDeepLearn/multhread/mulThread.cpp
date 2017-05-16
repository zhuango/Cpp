#include <thread>
#include <iostream>
#include <mutex>

using namespace std;
int shareVariable = 100;
mutex mtex;
void threadfunction(int a, string b, double c)
{
    //while(true){}
    mtex.lock();
    shareVariable ++;
    mtex.unlock();
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
int main(void)
{
    cout << sizeof(sizeof(mtex)) << endl;
    thread first(threadfunction, 12, "liuzhuang", 12.3);
    thread second(threadfunction, 12, "liuzhuang", 12.3);
    thread third(threadfunction, 12, "liuzhuang", 12.3);
    
    first.join();
    second.join();
    third.join();
    int i = 0;
    double j = 1.0;

    auto fun = [i, j](int k){cout << k << " "<< i << " " << j << endl;};
    thread lamThread(fun, 10);
    lamThread.join();
    return 0;
}