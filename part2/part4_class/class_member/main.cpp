#include<iostream>
using namespace std;


// 创建类
class Phone
{
public:
    int Year;
    string Pho;

    Phone(int year, string pho):Year(year), Pho(pho)  // 初始化列表 Year = year; Pho = Pho
    {
        cout << "调用Phone 有参构造函数" << endl;
    }

    ~Phone()
    {
        cout << "调用Phone 析构函数" << endl;
    }
};


// 人类
class Person
{
public:

    int Age;
    int *Height;  // 成员: 指针
    Phone m_phone; // 类成员

    // 浅拷贝
    // 初始化列表
    Person(int age, int height, int year, string pho) : Age(age), Height(new int(height)), m_phone{year, pho} {
        cout << "调用Person 有参构造函数" << endl;
    }

    // 利用深拷贝解决浅拷贝带来的析构释放问题
    // 将对象p上的所有属性拷贝到自己身上
    Person(const Person &p) : Age(p.Age), Height(new int(*p.Height)), m_phone{p.m_phone.Year, p.m_phone.Pho}
    {
        cout << "调用构造函数 拷贝构造" << endl;
    }

    /**
     * @brief Destroy the Person object
     * 1. 析构函数，没有返回值也不写void
     * 2. 函数名称与类名相同，在名称前加上符号~
     * 3. 析构函数*不可以有参数*，因此不可以重载
     * 4. 程序在对象销毁前会自动调用析构函数，无须手动调用，而且只会调用一次
     */
    ~Person(){
        cout << "调用Person 析构函数" << endl;
        // 析构代码，将在堆区开辟的数据做释放操作
        if (Height != NULL){
            delete Height;
            Height = NULL;
        }
    }

private: 
};

// 构造函数和析构函数是必须有的实现，如果程序员不提供，编译器会提供一个空实现的构造函数和析构函数
void test01(){ // // 在栈上的数据，执行完改函数时，释放这个对象
    // 1. 括号法
    Person p(10, 130, 2022, "IPhone 13");
    Person p1(p);

}


int main(){
    test01();
}

