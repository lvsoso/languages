#include <iostream>
#include <chrono>
#include <future> 
#include <string>
#include <mutex>
using namespace std;

int main() {
    mutex locker;
    auto readMsgList = [&]() {
        unique_lock guard(locker);
        this_thread::sleep_for(chrono::seconds(1)); 
        string str = "读消息容器 \n";
        cout << str;
    };
    auto writeMsgList = [&]() {
        unique_lock guard(locker);
        this_thread::sleep_for(chrono::seconds(2)); 
        string str = "写消息容器\n";
        cout << str;
    };
    auto i = 16;
    while (i>0)
    {
        if (i % 2 == 0) {
            auto t1 = thread(readMsgList);
            t1.detach();
        }
        else {
            auto t1 = thread(writeMsgList);
            t1.detach();
        }
        i -= 1;
    }
    return 0;
}