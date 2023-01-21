#include <iostream>
#include <chrono>
#include <future> 
#include <string>
#include <mutex> 
using namespace std;

int main() {
    mutex locker1;
    mutex locker2;
    auto readMsgList = [&]() {
        scoped_lock guard(locker1,locker2);
        this_thread::sleep_for(chrono::seconds(1)); 
        string str = "读消息容器 \n";
        cout << str;
    };

    auto writeMsgList = [&]() {
        scoped_lock guard(locker2, locker1);
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
    auto c = getchar();
}