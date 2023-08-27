#include<iostream>
using namespace std;


template<typename T>
bool compare(T &a, T &b){
    if (a == b){
        return true;
    }
    else{
        return false;
    }
}

class Person
{
public:
    string Name;
    int Age;

    Person(string name, int age) {
        Name = name;
        Age = age;
    }

};

// 1. 运算符重载
// 2. 利用具体化的Person类型，优先调用
template<> bool compare(Person &p1, Person &p2){
    if (p1.Name == p2.Name && p2.Age == p2.Age){
        return true;
    }
    else{
        return false;
    }
}

void test01(){
    int a = 10;
    int b = 20;
    bool ret = compare(a, b);
    if (ret){
        cout << "a == b" << endl; 
    }
    else{
        cout << "a != b" << endl; 
    }
}

void test02(){
    Person p1("momo", 10);
    Person p2("nono", 10);

    bool ret = compare(p1, p2);
    if (ret){
        cout << "a == b" << endl; 
    }
    else{
        cout << "a != b" << endl; 
    }
}

int main(){
    // test01();
    test02();
}