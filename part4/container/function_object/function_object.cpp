#include<iostream>

using namespace std;


// * 函数对象在使用时，可以想普通函数那样调用，可以有参数，也可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2){
        return v1 + v2;
    }
};

// * 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    int count;
    MyPrint(){
        this->count = 0;
    }
    void operator()(string test){
        cout << test << endl;
        count++;
    }
};

// * 函数对象可以作为参数传递
void doPrint(MyPrint & mp, string message){
    mp(message);
}

void test01(){
    MyAdd myAdd;
    cout << myAdd(1, 2) << endl;
}

void test02(){
    MyPrint myPrint;
    myPrint("hello kitty!");
    myPrint("hello kitty!");
    myPrint("hello kitty!");
    myPrint("hello kitty!");
    cout << "MyPrint的调用次数: " << myPrint.count << endl;
}

void test03(){
    MyPrint myPrint;
    doPrint(myPrint, "hello kitty!");
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}