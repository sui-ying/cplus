#include<iostream>
using namespace std;

// 自增运算符重载

class MyInteger
{
//    friend ostream & operator<<(ostream &cout, MyInteger myinter);
public:
    int Num;
    // 构造函数使用列表初始化时，需要给形参赋初值
    MyInteger(int Num=0): Num(Num){};  

    // 1. 使用成员函数进行前置递增运算符符重载
    MyInteger& operator++(){
        // 先++
        Num++;
        return *this;  // 再返回
    }

    // 2. 使用成员函数进行后置递增运算符符重载
    MyInteger operator++(int){
        // 先返回，
        MyInteger tmp = *this;  // 记录单签本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++
        Num++;
        return tmp; // 返回值
    }   
};


/**
 * @brief 左移运算符重载,输出类中的成员， 其本质: operator << (cout, p)
 * @param cout 
 * @param p 
 * @return ostream& cout
 */
ostream & operator<<(ostream &cout, MyInteger myint){
    cout << myint.Num;
    return cout;
}


void test01(){
    MyInteger myint(0);
    cout << ++myint << endl;
    cout << myint << endl;
} 

void test02(){
    MyInteger myint;
    cout << myint++ << endl;
    cout << myint << endl;
} 

int main(){
    test01();
    test02();
}
