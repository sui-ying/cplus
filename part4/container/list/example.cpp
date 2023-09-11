#include<iostream>
using namespace std;

#include<list>
#include<algorithm>  // 标准算法头文件


class Person
{
public:
    string Name;
    int Age;
    int Height;

    /**
     * @brief Construct a new Person object
     * @param name 
     * @param age 
     */
    Person(string name, int age, int height){
        this->Name = name;
        this->Age = age;
        this->Height = height;
    }

    void ShowPerson(){
        cout << "Name: " << this->Name << "\t Age: " << this->Age  << "\t Height: " << this->Height << endl;
    }
}; 

/**
 * @brief 仿函数
 * 
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool comparePerson(Person &p1, Person &p2){
    if (p1.Age == p2.Age){
        return p1.Height < p2.Height;
    }
    else{
        return p1.Age < p2.Age;
    }
    
}

void test01(){
    Person p1("momo", 18, 170);
    Person p2("nono", 19, 170);
    Person p3("lolo", 18, 175);
    Person p4("popo", 18, 160);

    list<Person>lst;
    lst.push_back(p1);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);

    for(list<Person>::iterator it=lst.begin(); it != lst.end(); it++){
        (*it).ShowPerson();
    }

    // sort: 
    lst.sort(comparePerson);
    cout <<  "After sort: " << endl;
    for(list<Person>::iterator it=lst.begin(); it != lst.end(); it++){
        (*it).ShowPerson();
    }
}

int main(){
    test01();
}