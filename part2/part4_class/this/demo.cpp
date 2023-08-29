#include<iostream>
#include<string>
using namespace std;


// 人类
class Person
{
public:
    int Age;  // 成员变量和成员函数分开存储, 只有非静态成员变量才属于类的对象

    static int Height;
    void SetAge(){}
    static void SetHeight(int height)
    {
        Height = height;
    }
private: 
   
};



void test01(){ 
    Person p;
    cout << "sizeof(p): " << sizeof(p) << endl;
}


int main(){
    test01();
}

