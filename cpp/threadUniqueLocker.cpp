#include <iostream>
#include <chrono>
#include <string>
#include <future>
#include <mutex>
using namespace std;

class Message
{
public:
    string SenderId;
    string MsgContent;
};

int main()
{
    Message msg;
    mutex locker;
    auto setMsg = [&](string &&senderId, string &&msgContent)
    {
        unique_lock guard(locker);
        msg.SenderId = senderId;
        this_thread::sleep_for(chrono::seconds(1));
        msg.MsgContent = msgContent;
        string str = msg.SenderId + "  " + msg.MsgContent + "\n";
        cout << str;
    };
    auto i = 4;
    while (i > 0)
    {
        auto t1 = thread(setMsg,
                         "sender" + to_string(i),
                         "content" + to_string(i));
        t1.detach();
        i -= 1;
    }
    return 0;
}