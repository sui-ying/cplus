#include<iostream>
using namespace std;

template<class T>
class Base
{
public:
    T m;
};


/**
 * @brief 当子类继承父类模板时，子类在声明的时候，要指定父类的类型
 * 
 */
class Son1: public Base<int> 
{
public:
    
};

/**
 * @brief 如果想灵活指定父类T 的类型，子类也需要变为类模板
 * @tparam T1 
 * @tparam T2 
 */
template<class T1, class T2>
class Son2: public Base<T2> 
{
public:
    T1 obj;
    /**
     * @brief Construct a new Son 2 object
     * 
     */
    Son2(){
        cout << "T1的数据类型: " << typeid(T1).name() << endl;
        cout << "T2的数据类型: " << typeid(T2).name() << endl;
    }
};

void test01(){
    Son1 s1;
}

void test02(){
    Son2<int, char> s2;
}

int main(){
    test01();
    test02();
}