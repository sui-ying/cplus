#include<iostream>
#include<string>
using namespace std;


// 人类
class Person
{
public:
    int Age;  // 成员变量和成员函数分开存储, 只有非静态成员变量才属于类的对象
    Person(int Age)
    {
        // Age = Age;
        this->Age = Age;  // 当形参和成员名称相同时，解决名称冲突
    }

    Person& PersonAddPerson(Person p)
    {
        this->Age += p.Age;
        return *this;  // 返回对象本身
    }

    static int Height;
    void SetAge(){}
    static void SetHeight(int height)
    {
        Height = height;
    }
private: 
   
};



void test01(){ 
    Person p(18);
    cout << "p.Age: " << p.Age << endl;
    Person p2(10);

    p2.PersonAddPerson(p).PersonAddPerson(p);
    cout << "p2.Age: " << p2.Age << endl;
}


int main(){
    test01();
}

