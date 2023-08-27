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


void test01(){
    // Person p1("momo", 18); // 类模板没有自动类型推导的使用方式
    Person<string, int>p1("momo", 18); // 初始化为对象时必须使用显式指定类型
    p1.ShowPerson();
}


void test02(){
    Person<string> p2("nono", 18);  // template<class NameType, class Agetype = int> 指定第二个参数为int
    p2.ShowPerson();
}


int main(){
    // test01();
    test02();
}