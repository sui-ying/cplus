#include<iostream>
using namespace std;

// 类模板
template<class NameType, class Agetype = int>  // 如果类中有两种数据类型，创建两种数据类型; 告诉编译器Agetype为int
class Person
{
public:
    NameType Name;
    Agetype Age;

    /**
     * @brief Construct a new Person object
     * @param name 
     * @param age 
     */
    Person(NameType name, Agetype age){
        this->Name = name;
        this->Age = age;
    }

    void ShowPerson(){
        cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
    }
}; 

// *************************** 类模板对象作函数参数 *************************** //
// 1. 传入指定类型
void PrintPerson1(Person<string, int>&p){
    p.ShowPerson();
}

void test01(){
    // Person p1("momo", 18); // 类模板没有自动类型推导的使用方式
    Person<string, int>p1("momo", 18); // 初始化为对象时必须使用显式指定类型
    // p1.ShowPerson();
    PrintPerson1(p1);
}

// 2. 参数模板化
template<class NameType, class Agetype>
void PrintPerson2(Person<NameType, Agetype>&p){
    p.ShowPerson();
}

void test02(){
    Person<string> p2("nono", 18);  // template<class NameType, class Agetype = int> 指定第二个参数为int
    PrintPerson2(p2);
}

// 3. 整个类模板化
template<class T>
void PrintPerson3(T &p){
    cout << "T的数据类型: " << typeid(T).name() << endl;  // 来获取一个表达式的动态类型信息
    p.ShowPerson();
}

void test03(){
    Person<string> p3("popo", 18);  // template<class NameType, class Agetype = int> 指定第二个参数为int
    PrintPerson3(p3);
}

int main(){
    test01();  // 1. 传入指定类型测试
    test02();  // 2. 参数模板化测试
    test03();  // 3. 整个类模板化

}