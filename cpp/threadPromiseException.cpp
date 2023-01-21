#include<iostream>
#include<thread>
#include<future> 
#include<utility>
#include<chrono>

using namespace std;

void func(promise<int> promiseObj) {
    try
    {
        throw "allen";
    }
    catch (...)
    {
        promiseObj.set_exception(std::current_exception());
    }
    
}

int main() {
    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();
    thread t(func, move(promiseObj));
    try
    {
        cout << futureObj.get() << endl;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
    }    
    t.join();
    return 0;
}