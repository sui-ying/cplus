#include<iostream>
using namespace std;


// 构造函数的分类及其调用
// 1. 按参数分为: 有参构造和无参构造
// 2. 按类型分为: 普通构造和拷贝构造
class Person
{

public:

    int Age;
    int *Height;  // 成员: 指针

    /**
     * @brief Construct a new Person object
     * 1. 构造函数没有返回值也不写void
     * 2. 函数名称与，类名相同
     * 3. 构造函数可以有参数，因此可以发生重载
     * 4. 程序在调用对象时会自动调用构造，无须手动调用，而且只会调用一次
     */
    Person(){
        cout << "调用构造函数 无参构造" << endl;
    } 
    
    Person(int age, int height){
        cout << "调用构造函数 有参构造" << endl;
        Age = age; 
        Height = new int(height);  // 编译器提供的为浅拷贝，只需释放一次  free(): double free detected in tcache 2
        
    }

    // 利用深拷贝解决浅拷贝带来的析构释放问题
    // 将对象p上的所有属性拷贝到自己身上
    Person(const Person &p){
        cout << "调用构造函数 拷贝构造" << endl;
        Age = p.Age;    
        // Height = p.Height;  // 浅拷贝: 生成的对象指向同一块地址
        Height = new int (*p.Height);  // 深拷贝: 生成的对象将在堆区重新开辟一块内存
        
    }

    /**
     * @brief Destroy the Person object
     * 1. 析构函数，没有返回值也不写void
     * 2. 函数名称与类名相同，在名称前加上符号~
     * 3. 析构函数*不可以有参数*，因此不可以重载
     * 4. 程序在对象销毁前会自动调用析构函数，无须手动调用，而且只会调用一次
     */
    ~Person(){
        cout << "调用析构函数" << endl;
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
    // ****** 调用方式 ******  // 
    // 1. 括号法
    Person p1(10, 130);     // 调用有参构造函数
    cout << "p1 Age: " << p1.Age << "\t" << "Height: " << *p1.Height << endl;

    Person p2(p1);  // 浅拷贝: 只需释放一次
    cout << "p2 Age: " << p2.Age << "\t" << "Height: " << *p2.Height << endl;
}


int main(){
    test01();
}

