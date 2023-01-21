#include <iostream>
#include <thread> //线程类型在此头文件中定义
#include <string>
#include <future> 

using namespace std;

class MyClass
{
public:
    void Func(int tId, int &num, string &&msgContent)
    {
        for (size_t i = 0; i < num; i++)
        {
            string str = "thread id:" + to_string(tId) +
                         "  print:" + to_string(i) + " " + msgContent + "\n";
            cout << str;
        }
    }
};

int main()
{
    MyClass obj;
    int num = 6;
     int threadNum = thread::hardware_concurrency();
    threadNum = threadNum == 0 ? 2 : threadNum;
    threadNum = min(threadNum, 6);
    cout << "max thread num: " << threadNum << endl;  
    for (size_t i = 0; i < threadNum; ++i) {
        thread t(&MyClass::Func, &obj, 0, ref(num), "content");
        t.detach();
    } 
    
    auto func = [](int num)->int {
    this_thread::sleep_for(chrono::seconds(6));
    return num;
};
    future<int> result = async(func,1);
    this_thread::sleep_for(chrono::seconds(3));
    int val = result.get();
    cout << "async result: " << val << endl;
    // auto c = getchar();
}