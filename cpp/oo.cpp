#include <iostream>
#include <random>
#include <string>

using namespace std;

class Message
{
public:
    Message() : MessageId{createMessageId()} {}
    const int MessageId;
    virtual void SendMessage() {}

private:
    int createMessageId()
    {
        random_device dev;
        return dev();
    }
};

class TextMessage : public Message
{
public:
    TextMessage() : Message() {}
    void SendMessage() override
    {                                                                 // 重写父类消息
        cout << "发送文本消息：" << MessageId << ":" << Text << endl; // MessageId来自父类
    }
    string Text;
};

class FileMessage : public Message
{
public:
    FileMessage() : Message() {}
    void SendMessage() override
    {                                                                     // 重写父类消息
        cout << "发送文件消息：" << MessageId << ":" << FilePath << endl; // MessageId来自父类
    }
    string FilePath;
};

void Send(Message &msg)
{
    msg.SendMessage();
}

int main()
{
    {
        TextMessage txtMsg;
        txtMsg.Text = "发个消息";
        Send(txtMsg);
    }

    {
        FileMessage fileMsg;
        fileMsg.FilePath = "hello.png";
        Send(fileMsg);
    }
}