#include<iostream>
using namespace std;


class Person
{
public:
    int House;
    int Car; 

    // 构造函数使用列表初始化时，需要给形参赋初值
    Person(int house=0, int car=0): House(house), Car(car){};  
    
    // 
    // 1. 使用成员函数进行加法运算符符重载
    Person operator+(Person &p){
        Person tmp;
        tmp.House = this->House + p.House;
        tmp.Car = this->Car + p.Car;
        return tmp;
    }


};


void test01(){
    Person p1(2, 3);
    Person p2 = p1;
    cout << "p2.House: " << p2.House << " p2.Car: " << p2.Car << endl; 
} 

int main(){
    cout << 1 + 1 << endl;
    test01();
}
