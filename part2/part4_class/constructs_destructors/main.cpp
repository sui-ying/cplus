#include<iostream>
using namespace std;


// 构造函数的分类及其调用
// 1. 按参数分为: 有参构造和无参构造
// 2. 按类型分为: 普通构造和拷贝构造
class Person
{

public:

    int age;
    
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
    
    Person(int a){
        age = a;
        cout << "调用构造函数 有参构造" << endl;
    }

    // 将对象p上的所有属性拷贝到自己身上
    Person(const Person &p){
        age = p.age;    
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
        cout << "调用析构函数" << endl;
    }

private: 
    

};

// 构造函数和析构函数是必须有的实现，如果程序员不提供，编译器会提供一个空实现的构造函数和析构函数
void test01(){ // // 在栈上的数据，执行完改函数时，释放这个对象
    // ****** 调用方式 ******  // 
    // 1. 括号法
    cout << "括号法" << endl;
    Person p1;     // 调用默认构造函数
    Person p2(10); // 调用有参构造函数
    Person p3(p2); // 调用拷贝构造函数；  使用一个已经创建完毕的对象 来初始化

    cout << "p2.age: " << p2.age << endl;
    cout << "p2.age: " << p2.age << endl;

    // 调用默认构造函数的时候，不要加括号()
    Person p4();  // 编译器会认为这是一个函数的声明，不会认为在创建对象

    // 2. 显示法
    cout << "显示法" << endl;
    Person q1;               // 调用默认构造函数
    Person q2 = Person(10);  // 调用有参构造函数
    Person q3 = Person(q2);  // 调用拷贝构造函数
    
    // cout << "匿名对象" << endl;
    // Person(10);  // 当前执行结束后，系统会立即回收掉匿名对象(析构) 

    // 3. 隐式转换法
    cout << "隐式转换法" << endl;
    Person r1 = 10;
    Person r2 = r1;
}

// 拷贝构造函数的使用时机:
// 1. 使用一个已经创建完毕的对象 来初始化 void test01(){}
// 2. 值传递的方式给函数参数传值
void DoWork(Person p){

}

void test02(){
    Person p;
    DoWork(p);
}

// 3. 值方式返回局部对象
Person DoWork2(){
    Person p1;
    return p1;
}

void test03(){
    Person p = DoWork2();
}

int main(){
    // test01();
    // test02();
    test03();
    // Person p1;  // 在栈上的数据，执行完改函数时，释放这个对象
}

