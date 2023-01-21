#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int main()
{
    mutex locker;
    condition_variable cv;
    auto func = [&]()
    {
        unique_lock guard(locker);
        cv.wait(guard);
        cout << "thread start" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "thread unlock" << endl;
        guard.unlock();
        cv.notify_one();
        this_thread::sleep_for(chrono::seconds(3));
        cout << "thread end" << endl;
    };
    std::cout << "main start" << endl;
    std::thread t(func);
    t.detach();
    this_thread::sleep_for(chrono::seconds(3));
    cv.notify_one();
    unique_lock guard(locker);
    cv.wait(guard);
    guard.unlock();
    std::cout << "main end" << endl;
    return 0;
}