#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void test_find(){
    vector<int>v = {2, 3, 1, 5, 4};
    vector<int>::iterator pos = find(v.begin(), v.end(), 1);  // find 1
    if (pos == v.end()){
        cout << "Not find" << endl;
    }
    else{
        cout << "find elem: " << *pos << endl;
    }
}

class Person
{
public:
    string Name;
    int Age;
    Person(string name, int age):Name(name), Age(age){}

    // 重载==
    bool operator==(const Person & p){
        if (this->Name == p.Name && this->Age == p.Age){
            return true;
        } 
        else{
            return false;
        }
    }

    // bool operator!=(const Person & p){
    //     if (this->Age != p.Age){
    //         return true;
    //     } 
    //     else{
    //         return false;
    //     }
    // }
    bool isEqualByAge(const Person &p) const {
        if (this->Age == p.Age) {
            return true;
        }
        else {
            return false;
        }
    }

    void showPerson(){
        cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
    }
};

void test_find_customData(){
    vector<Person>v;
    Person p1("xxx", 1);
    Person p2("yyy", 2);
    Person p3("ccc", 3);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    Person tp("xxx", 1);
    vector<Person>::iterator pos = find(v.begin(), v.end(), tp);  // find tp
    if (pos == v.end()){
        cout << "Not find" << endl;
    }
    else{
        cout << "find elem: " << endl;
        (*pos).showPerson();
    }
}

class Greater
{
public:
    int Val;
    Greater(int val): Val(val){}
    bool operator()(int val){
        return val > this->Val;
    }
};

void test_find_if(){
    vector<int>v = {2, 3, 1, 5, 4};
    // Todo
    vector<int>::iterator pos = find_if(v.begin(), v.end(), Greater(3));  // 按条件查找 大于3
    if (pos == v.end()){
        cout << "Not find" << endl;
    }
    else{
        cout << "find elem: " << *pos << endl;
    }
}

class PersonGreater20
{
public:
    bool operator()(const Person& p){
        return p.Age > 20;
    }
};

void test_find_if_customData(){
    vector<Person>v;
    Person p1("xxx", 10);
    Person p2("yyy", 20);
    Person p3("ccc", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    vector<Person>::iterator pos = find_if(v.begin(), v.end(), PersonGreater20());  // find_if
    if (pos == v.end()){
        cout << "Not find" << endl;
    }
    else{
        cout << "find elem: " << endl;
        (*pos).showPerson();
    }
}

void test_adjacent_find(){
    vector<int>v = {2, 3, 1, 1, 5, 5, 4};
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end()){
        cout << "Not find" << endl;
    }
    else{
        cout << "find elem: " << *pos << endl;
    }
}

void test_binary_search(){
    // vector<int>v = {2, 3, 1, 5, 4};
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    bool ret = binary_search(v.begin(), v.end(), 8);  // 从有序序列中二分查找
    if (ret){
        cout << "find elem: " << endl;
    }
    else{
        cout << "Not find" << endl;
    }
}

void test_count(){
    vector<int>v = {2, 3, 1, 1, 5, 5, 4};
    int nums = count(v.begin(), v.end(), 4);  // 统计元素为4的个数
    cout << "nums: " << nums << endl;
}

void test_count_if(){
    vector<int>v = {2, 3, 1, 1, 5, 5, 4};
    int nums = count_if(v.begin(), v.end(), Greater(4));  // 按条件统计元素大于val的个数
    cout << "nums: " << nums << endl;
}

void test_count_if_customData(){
    vector<Person>v;
    Person p1("xxx", 10);
    Person p2("yyy", 20);
    Person p3("ccc", 30);
    Person p4("zzz", 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    
    Person cp("???", 20);  // 仅仅统计Age
    // int nums = count(v.begin(), v.end(), cp);
    // lambda表达式
    int nums = count_if(v.begin(), v.end(), [&](const Person &p) { return p.isEqualByAge(cp); });
    cout << "nums: " << nums << endl;
}

int main(){
    // test_find();                  // 查找元素
    // test_find_customData();       // 查找自定义数据

    // test_find_if();              // 按条件查找
    // test_find_if_customData();   // 按条件查找自定义数据

    // test_adjacent_find();        // 查找相邻重复元素，返回第一个相同元素的第一个位置迭代器

    // test_binary_search();        // 二分查找

    test_count();     // 统计元素个数
    test_count_if();  // 按条件统计元素个数
    test_count_if_customData();  // 按条件统计自定义数据元素个数

    return 0;
}