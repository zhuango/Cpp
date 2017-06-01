#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
using namespace std;

mutex mux;

void sleepThread(int elem)
{
    this_thread::sleep_for(chrono::milliseconds(elem));
    mux.lock();
    cout << elem << endl;
    mux.unlock();
    //sorted->push_back(elem);
}

void sleepSort(vector<int> &array)
{
    vector<thread> threads;
    for(auto elem : array)
    {
        threads.push_back(thread(sleepThread, elem));
    }
    for(auto &thr : threads)
    {
        thr.join();
    }
}

int main()
{
    vector<int> array = {234, 234 ,1, 6, 567, 34, 57, 324, 6};
    sleepSort(array);
}