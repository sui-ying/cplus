#include<iostream>
using namespace std;

#include "../include/MyArray.hpp"


class Person
{
public:
    string Name;
    int Age;

    // 需要写默认的构造函数
    Person(){

    }

    /**
     * @brief Construct a new Person object
     * @param name 
     * @param age 
     */
    Person(string name, int age){
        this->Name = name;
        this->Age = age;
    }

    void ShowPerson(){
        cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
    }
}; 

void test01(){
    MyArray<int>arr1(5);  // 测试 有参构造函数 析构函数

    MyArray<int>arr2(arr1); // 测试 拷贝构造函数

    MyArray<int>arr3(100);
    arr3 = arr1;  // 测试 赋值运算符重载函数

}

// 打印数组元素
void PrintMyarray(MyArray<int>& arr){
    for (int i=0; i<arr.GetSize(); i++){
        cout << arr[i] << endl;
    }
}

// 打印数组元素
void PrintMyarrayPerson(MyArray<Person>& arr){
    for (int i=0; i<arr.GetSize(); i++){
        cout << "Name: " << arr[i].Name << "\t Age: " << arr[i].Age << endl;
    }
}

void test02(){
    MyArray<int>arr1(5);

    // 添加元素
    for (int i=0; i<5; i++){
        arr1.PushBack(i);
    }
    
    PrintMyarray(arr1);

    MyArray<int>arr2(arr1); // 测试 拷贝构造函数
    PrintMyarray(arr2);

    arr2.PopBack();
    PrintMyarray(arr2);
    cout << "Capacity of arr2: " << arr2.GetCapacity() << endl;
    cout << "Size of arr2: " << arr2.GetSize() << endl;

}


void test03(){
    MyArray<Person> arr(10);
    Person p1("momo", 18);
    Person p2("nono", 18);
    Person p3("lolo", 18);  

    arr.PushBack(p1);
    arr.PushBack(p2);
    arr.PushBack(p3);

    PrintMyarrayPerson(arr);
    cout << "Capacity of arr: " << arr.GetCapacity() << endl;
    cout << "Size of arr: " << arr.GetSize() << endl;
    
    arr.PopBack();
    PrintMyarrayPerson(arr);
    cout << "Capacity of arr: " << arr.GetCapacity() << endl;
    cout << "Size of arr: " << arr.GetSize() << endl;

}
int main(){
    // test01();  // 测试 
    // test02(); // 测试功能
    test03(); // 测试自定义数据类型
}