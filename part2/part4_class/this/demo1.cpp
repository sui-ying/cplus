#include<iostream>
#include<string>
using namespace std;

// 人类
class Person
{
public:
    int Age;  // 成员变量和成员函数分开存储, 只有非静态成员变量才属于类的对象
    mutable int Money;  // 特殊变量mutable，即使在函数中，也可以修改这个值，

    Person(int age=0, int money=0):Age(age), Money(money)
    {
        cout << "调用Person 有参构造函数" << endl;
    }

    void ShowClassName(){
        cout << "this is class Person" << endl;
    }

    // this指针的本质： 指针常量，指针的指向不可以修改
    // 在成员函数后面加上 const, 修饰的this的指向，让指针指向的值也不可以修改； 于是变成了常函数
    void ShowPersonInfo() const
    {
        // this->Age = 18;  // 错误：const 成员函数不能修改非 mutable 成员变量
        this->Money = 54366;  // 正确：mutable 成员变量可以在 const 成员函数中被修改
        // cout << "Age: " << this->Age << endl;
        cout << "Money: " << this->Money << endl;
    }

private: 
   
};

void test01(){ 
    Person p;
    p.ShowPersonInfo();
}

void test02(){ 
    const Person p{18, 10000};  // 常对象: 声明对象前加const
    p.ShowPersonInfo();  // 常对象只能调用常函数
    // p.ShowClassName();
}

int main(){
    test01();
    test02();
}
