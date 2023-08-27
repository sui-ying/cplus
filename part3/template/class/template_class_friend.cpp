#include<iostream>
using namespace std;

template<class NameType, class Agetype>  // 如果类中有两种数据类型，创建两种数据类型; 告诉编译器Agetype为int
class Person;

template<class U, class V>
void PrintPersonInfo2(Person<U, V>p);

// 类模板
template<class NameType, class Agetype>  // 如果类中有两种数据类型，创建两种数据类型; 告诉编译器Agetype为int
class Person
{   
    /**
     * @brief 全局函数，类内实现
     * 
     */
    friend void PrintPersonInfo(Person<NameType, Agetype>p){
        cout << "Name: " << p.Name << "\t Age: " << p.Age << endl;
    }

    /**
     * @brief 全局函数，类外实现
     * 
     * @tparam NameType 
     * @tparam Agetype 
     */
    template<class U, class V>
    friend void PrintPersonInfo2(Person<U, V> p);


public:
    NameType Name;
    Agetype Age;

    // 模板类构造函数类内声明，类外实现
    Person(NameType name, Agetype age);
    // 模板类成员函数类内声明，类外实现
    void ShowPerson();

}; 

// 构造函数类外实现
template<class NameType, class Agetype>
Person<NameType, Agetype>::Person(NameType name, Agetype age){
    this->Name = name;
    this->Age = age;
}

// 成员函数类外实现
template<class NameType, class Agetype>
void Person<NameType, Agetype>::ShowPerson(){
    cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
}

void test01()
{
    Person<string, int>p1("momo", 18);
    p1.ShowPerson();
}

void test02(){
    Person<string, int>p2("nono", 18);
    PrintPersonInfo(p2);
}

template<class U, class V>
void PrintPersonInfo2(Person<U, V>p){
    cout << "Name: " << p.Name << "\t Age: " << p.Age << endl;
}

void test03(){
    Person<string, int>p3("lolo", 18);
    PrintPersonInfo2(p3);
}

int main(){
    // test01();  // 测试成员函数类外实现
    test02();  // 测试友元函数实现 方式1 类内实现
    test03();  // 测试友元函数实现 方式2 类外实现
}