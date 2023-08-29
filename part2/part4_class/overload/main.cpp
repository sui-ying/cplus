#include<iostream>
using namespace std;


class Person
{
public:
    int House;
    int Car; 

    // 构造函数使用列表初始化时，需要给形参赋初值
    Person(int house=0, int car=0): House(house), Car(car){};  

    // 1. 使用成员函数进行运算符符重载
    Person operator+(Person &p){
        Person tmp;
        tmp.House = this->House + p.House;
        tmp.Car = this->Car + p.Car;
        return tmp;
    }
};


// 通过全局函数进行运算符符重载
// Person operator+(Person &p1, Person &p2){
//     Person tmp;
//     tmp.House = p2.House + p1.House;
//     tmp.Car = p2.Car + p1.Car;
//     return tmp;
// }

// 通过全局函数进行运算符符重载: 也可以发生函数重载
Person operator+(Person &p1, int num){
    Person tmp;
    tmp.House = num + p1.House;
    tmp.Car = num + p1.Car;
    return tmp;
}

void test01(){
    Person p1(2, 3);
    Person p2(3, 4);
    Person p3 = p1 + p2;
    cout << "p3.House: " << p3.House << " p3.Car: " << p3.Car << endl;
    Person p4 = p1 + 1;
    cout << "p4.House: " << p4.House << " p4.Car: " << p4.Car << endl;  // 通过全局函数进行运算符符重载: 也可以发生函数重载
} 

int main(){
    cout << 1 + 1 << endl;
    test01();
}
