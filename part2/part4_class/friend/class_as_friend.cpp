#include<iostream>
#include<string>
using namespace std;

// class building;
// class MyBestie;
class MyBosom;

class Building
{
    // 告知编译器 函数MyFriend 是Building类的友元函数，可以访问类中的私有成员
    friend void MyFriend(Building *building);
    // 告知编译器 类MyBestie 是Building类的友元类，可以访问类中的私有成员
    friend class MyBestie;
    // 告知编译器 类成员函数MyBosom::visit() 是Building类的友元，可以访问类中的私有成员
    friend void MyBosom::visit(); // 友元函数声明 MyBosom::visit()

public:
    string LivingRoom;

    Building(){
        this->BedRoom = "bedroom";
        this->LivingRoom = "livingroom";
    }

private:
    string BedRoom;

    void PrintInfo(){
        cout << "Call private member functions" << endl;
    }
};

// 全局函数做类Building的友元
void MyFriend(Building *building){
    cout << "The global function is accessing the object Building: " << building->LivingRoom << endl;
    cout << "The global function is accessing the object Building: " << building->BedRoom << endl;
    // building->PrintInfo();
}


// 类做类Building的友元
class MyBestie
{
public:
    MyBestie(){
        // 在堆区创建一个对象
        building = new Building;
    }

    void visit(){
        cout << "The class MyBestie is accessing the object Building: " << building->LivingRoom << endl;
        cout << "The class MyBestie is accessing the object Building: " << building->BedRoom << endl;
    }
  
private:
    Building *building;
};


// 使类中的成员函数作为类Building的友元
class MyBosom
{
public:
    MyBosom(){
        // 在堆区创建一个对象
        building = new Building;
    }
    void visit();
    void visit1();
  
private:
    Building *building;
};

void MyBosom::visit(){
        cout << "The class MyBosom is accessing the object Building: " << building->LivingRoom << endl;
        // cout << "The class MyBosom is accessing the object Building: " << building->BedRoom << endl;
    }

void MyBosom::visit1(){
    cout << "The class MyBosom is accessing the object Building: " << building->LivingRoom << endl;
    // cout << "The class MyBosom is accessing the object Building: " << building->BedRoom << endl;
}

void test01(){
    Building building;
    MyFriend(&building);
}

void test02(){
    MyBestie mybestie;
    mybestie.visit();
}

void test03(){
    MyBosom mybosom;
    mybosom.visit();
}

int main(){
    test01();
    test02();
    test03();
}