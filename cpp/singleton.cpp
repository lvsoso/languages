#include <iostream>
#include <random>

using namespace std;

class Message
{
    public:
        Message(const Message& msg) = delete;
        void operator=(const Message& msg) = delete;
        ~Message(){
            instance = nullptr;
        }

        static Message* getInstance(){
            if(instance == nullptr){
                instance = new Message();
            }
            return instance;
        }
        int MessageId;

    private:
        Message():MessageId{createMessageId()}{}
        int createMessageId(){
            std::random_device dev;
            return dev();
        }
        inline static Message* instance{nullptr};
};


int main() {
    auto msg1 = Message::getInstance();
    auto msg2 = Message::getInstance();
    cout << "msg1->MessageId：" << msg1->MessageId << endl //输出：msg1->MessageId：1053936909
    << "msg2->MessageId：" << msg2->MessageId << endl;  //输出：msg2->MessageId：1053936909
    delete msg2;
    //因为msg2与msg1关联的是相同的堆空间，所以msg2释放之后，msg1也不能再使用了
    //cout << "msg1->MessageId：" << msg1->MessageId << endl;  
    auto msg3 = Message::getInstance(); //重新创建了一个对象，MessageId发生了变化
    cout << "msg3->MessageId：" << msg3->MessageId << endl; //输出：msg3->MessageId：1032253099
    return 0;
}