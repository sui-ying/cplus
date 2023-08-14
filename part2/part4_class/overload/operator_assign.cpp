#include<iostream>
using namespace std;


class Person
{
public:
    int *Money; 

    // 构造函数使用列表初始化时，需要给形参赋初值
    Person(int money=0){
        Money = new int(money);  // 在堆区开辟一块内存，释放需要由程序员自己释放
    }  
    
    // 析构函数    
    ~Person(){
        if (Money != NULL){
            delete Money;
            Money = NULL;
        }
    }

    // 重载赋值运算符
    Person& operator=(Person &p){
        if (Money != NULL){
            delete Money;
            Money = NULL;
        }

        // 编译器提供的是浅拷贝，指向同一块地址
        // Money = p.Money;

        // 深拷贝 解决浅拷贝带来的重复释放问题
        Money = new int(*p.Money);  // 在堆区重新开辟一块内存
        return *this;  // 返回对象本身
    }

};


void test01(){
    Person p1(2);
    Person p2(3);
    Person p3(4);
    p2 = p1;  // 深拷贝解决浅拷贝带来的重复释放问题
    cout << "p2.Money: " << *p2.Money << endl; 
    p3=p2=p1;
    cout << "p3.Money: " << *p3.Money << endl;
} 

int main(){
    test01();
}
