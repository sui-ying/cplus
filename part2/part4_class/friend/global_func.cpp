#include<iostream>
#include<string>
using namespace std;


class Building
{
    // 告知编译器 函数MyFriend 是Building类的友元函数，可以访问类中的私有成员
    friend void MyFriend(Building *building);
public:
    string LivingRoom;

    Building(){
        this->BedRoom = "000";
        this->LivingRoom = "001";
    }

private:
    string BedRoom;

    void PrintInfo(){
        cout << "Call private member functions" << endl;
    }
};


void MyFriend(Building *building){
    cout << "The global function is accessing the object Building: " << building->LivingRoom << endl;

    cout << "The global function is accessing the object Building: " << building->BedRoom << endl;
    building->PrintInfo();
}

void test01(){
    Building building;
    MyFriend(&building);
}

int main(){
    test01();
}