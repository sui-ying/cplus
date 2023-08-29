#include<iostream>
using namespace std;

class Animal
{
public:
    // 关键字virtual 虚函数; 编译器在编译的时候就不能确定函数调用了
    virtual void speak(){
        cout << "Animal speak !" << endl;
    }
};

class Cat: public Animal
{
public:
    void speak()
    {
        cout << "cat speak !" << endl;
    }
};

class Dog: public Animal
{
public:
    void speak()
    {
        cout << "Dog speak !" << endl;
    }
};

/**
 * @brief 
 * @param animal 
 */
void DoSpeak(Animal & animal){
    animal.speak();
}

// 多态满足条件:
// 1. 有继承关系
// 2. 子类重写父类虚函数

// 多态使用
//  父类指针或引用 指向子类对象

void test(){
    Cat cat;
    DoSpeak(cat);  // & animal = cat;

    Dog dog;
    DoSpeak(dog);
}

int main(){
    cout << "sizeof(Animal): " << sizeof(Animal) << endl;
    test();
    cout << "sizeof(Animal): " << sizeof(Animal) << endl;
}