#include<iostream>
using namespace std;

class Animal
{
public:
    string *Name;  // 定义字符串指针
    
    // 纯虚函数
    virtual void speak() = 0;

    /**
     * @brief Construct a new Animal object
     * *Name为字符串指针，使用之前为其分配内存空间
     * @param name 
     */
    Animal(string name):Name(new string(name)){
        cout << "Call constructor function of class Animal !" << endl;
    }

    // 父类的指针在析构时，不会调用子类的析构函数，如果子类有在堆区创建的数据，则不会释放导致内存泄露
    // 可以将父类中析构函数改为虚析构可以解决上述问题: 因为虚析构在子类调用时需要重写
    // virtual ~Animal(){
    //     cout << "Call destructor function of class Animal !" << endl;
    // }

    // 纯虚析构： 需要声明也需要实现
    // 如果有纯虚析构函数，类也称之为抽象类
    virtual ~Animal() = 0;
};

Animal::~Animal(){
    cout << "Call destructor function of class Animal !" << endl;
}


class Cat: public Animal
{
public:
    Cat(string name): Animal(name){
        cout << "Call constructor function of class Cat !" << endl;
    }

    ~Cat(){
        if (Name != NULL){
            cout << "Call destructor function of class Cat !" << endl;
            delete Name;
            Name = NULL;
        }
    }

    void speak()
    {
        cout << *Name << " cat speak !" << endl;
    }
};


void test(){
    Animal *animal = new Cat("momo");  // 多态使用: 父类指针指向子类对象
    animal->speak();
    // 父类的指针在析构时，不会调用子类的析构函数，如果子类有在堆区创建的数据，则不会释放导致内存泄露
    // 可以将父类中析构函数改为虚析构可以解决上述问题
    delete animal;
}

int main(){
    cout << "sizeof(Animal): " << sizeof(Animal) << endl;
    test();
    cout << "sizeof(Animal): " << sizeof(Animal) << endl;
}