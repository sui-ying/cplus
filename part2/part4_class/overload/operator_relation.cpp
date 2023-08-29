#include<iostream>
using namespace std;

// 关系运算符重载

class Person
{
//    friend ostream & operator<<(ostream &cout, Person &p);
public:
    string Name;
    int Age; 

    // 构造函数使用列表初始化时，需要给形参赋初值
    Person(string name, int age): Name(name), Age(age){};  

    // 1. 使用成员函数进行关系运算符符重载
    bool operator==(Person &p){
        if (this->Name == p.Name && this->Age == p.Age)
            return true;
        return false;
    }
};


void test01(){
    Person p1("momo", 18);
    Person p2("noon", 18);
    if (p2 == p1){
        cout << "p2 == p1" << endl;
    }
    else{
        cout << "p2 != p1" << endl;
    }
}


int main(){
    test01();
}