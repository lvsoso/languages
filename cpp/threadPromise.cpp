#include<iostream>
#include<thread>
#include<future>
#include<utility>
#include<chrono>

using namespace std;

void func(promise<int> promiseObj) {
    cout << "当前thread id: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(6));
    promiseObj.set_value(35);
    this_thread::sleep_for(chrono::seconds(6));
    cout << "线程执行完毕" << endl;
}

int main() {
    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();
    thread t(func, move(promiseObj));
    cout << futureObj.get() << endl;
    t.join();
    return 0;
}