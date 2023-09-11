#include<iostream>
#include<set>

using namespace std;


void printSet(set<int>&s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printMultiset(multiset<int>&ms){
    for (multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void setConstructor(){
    set<int>st1;

    // insert 
    st1.insert(1);
    st1.insert(20);
    st1.insert(2);
    st1.insert(10);
    st1.insert(3);
    st1.insert(4);

    // access
    printSet(st1);

    set<int>st2;
    st2 = st1;  // 赋值
    printSet(st2);

    set<int>st3(st2);  // 拷贝构造
    printSet(st3);

}

void setSize(){
    set<int> st1;  // 默认构造 无参构造
    // insert 
    st1.insert(1);
    st1.insert(20);
    st1.insert(2);
    st1.insert(10);
    st1.insert(3);
    st1.insert(4);

    if (st1.empty()){
        cout << "st1 is empty" << endl;
    }
    else{
        // cout << "capcity of set st1: " << st1.capacity() << endl; 
        cout << "size of set st1: " << st1.size() << endl; 
        printSet(st1);
    }
    
    set<int> st2;  // 默认构造 无参构造
    st2.insert(6);
    st2.insert(8);
    st2.insert(3);
    st2.insert(9);

    st1.swap(st2);
    cout << "After swap: " << endl;
    printSet(st1);
    printSet(st2);
}

void setInsertErase(){
    set<int> st1;  // 默认构造 无参构造
    // insert 
    st1.insert(1);
    st1.insert(20);
    st1.insert(2);
    st1.insert(10);
    st1.insert(3);
    st1.insert(4);
    // st1.insert(10);
    printSet(st1);

    st1.erase(st1.begin());  // 删除特定位置
    printSet(st1);

    st1.erase(10);  // 删除特定元素
    printSet(st1);

    st1.erase(st1.begin(), st1.end());
    printSet(st1);

    st1.clear();
    printSet(st1);

}

void setFind(){
    set<int> st1;  // 默认构造 无参构造
    // insert 
    st1.insert(1);
    st1.insert(20);
    st1.insert(2);
    st1.insert(10);
    st1.insert(3);
    st1.insert(4);
    printSet(st1);

    set<int>::iterator pos = st1.find(20);
    if (pos != st1.end()){
        cout << "find elem: " << *pos << endl;
    }
    else{
        cout << "not find elem" << endl;
    }

    int num = st1.count(20);  // 对于set而言，为1或者0
    cout << "num: " << num << endl;
}

void multisetConstructor(){
    set<int>st1;
    pair<set<int>::iterator, bool> ret = st1.insert(1);  // 对组pair
    if (ret.second){
        cout << "第一次插入数据成功" << endl;
    }
    else{
        cout << "重复数据， 插入数据失败" << endl;
    }

    ret = st1.insert(1);  // 重复数据
    if (ret.second){  // 取对组的第二个元素 bool
        cout << "第一次插入数据成功" << endl;
    }
    else{
        cout << "重复数据， 插入数据失败" << endl;
    }
    printSet(st1);

    multiset<int>ms1;
    ms1.insert(1);
    ms1.insert(1);
    ms1.insert(1);
    printMultiset(ms1);
}

class myCompare
{
public:
    /**
     * @brief 仿函数 重载函数
     * 
     * @param v1 
     * @param v2 
     * @return true 
     * @return false 
     */
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void setSort(){
    set<int> st1;  // 默认构造 无参构造
    // insert 
    st1.insert(1);
    st1.insert(20);
    st1.insert(2);
    st1.insert(10);
    st1.insert(3);
    st1.insert(4);
    printSet(st1); // 此时已经是从小到大排序

    set<int, myCompare> st2;  // 默认构造 无参构造
    // insert 
    st2.insert(1);
    st2.insert(20);
    st2.insert(2);
    st2.insert(10);
    st2.insert(3);
    st2.insert(4);

    for (set<int, myCompare>::iterator it=st2.begin(); it != st2.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}


class Person
{
public:
    string Name;
    int Age;

    /**
     * @brief Construct a new Person object
     * @param name 
     * @param age 
     */
    Person(string name, int age){
        this->Name = name;
        this->Age = age;
    }

    void ShowPerson() const {
        cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
    }

    // 重载 < 运算符
    bool operator<(const Person& p) const {
        return Age < p.Age || (Age == p.Age && Name < p.Name);
    }
}; 

void setSortCustomData(){
    set<Person>s1;

    Person p1("momo", 18);
    Person p2("nono", 18);
    Person p3("lolo", 18);  
    Person p4("popo", 19);  

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    for (set<Person>::iterator it=s1.begin(); it != s1.end(); it++){
        (*it).ShowPerson();
    }

    // for (const auto& person : s1) {
    //     person.ShowPerson();
    // }

}

int main(){
    setConstructor();
    setSize();
    setInsertErase();
    setFind();
    multisetConstructor();
    setSort();  // 利用仿函数
    setSortCustomData();
    return 0;
}