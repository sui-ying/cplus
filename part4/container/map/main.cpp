#include<iostream>
#include<map>

using namespace std;


void printMap(map<int, int>& m){
    // 对组第一个元素， 第二个元素
    for (map<int, int>::iterator it=m.begin(); it != m.end(); it++){
        cout << "key: " << (*it).first << "\t value: " <<(*it).second << endl;
    }
    
}

void mapConstructor(){
    map<int, int>m1;  // 默认构造 无参构造
    
    // insert
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));

    printMap(m1);  //默认按照key从小到大排序

    map<int, int>m2(m1);  //拷贝构造
    printMap(m2);

    map<int, int>m3;
    m3 = m1;  // 赋值操作
    printMap(m3);
}

void mapSizeSwap(){
    map<int, int>m1;  // 默认构造 无参构造
    
    // insert
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));

    if (m1.empty()){
        cout << "map m1 is empty" << endl;
    }
    else{
        cout << "size m1: " << m1.size() << endl;
    }

    map<int, int>m2;  // 默认构造 无参构造
    
    // insert
    m2.insert(pair<int, int>(4, 40));
    m2.insert(pair<int, int>(5, 50));
    m2.insert(pair<int, int>(2, 20));

    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

void mapInsertErase(){
    map<int, int>m1;  // 默认构造 无参构造
    
    // 推荐使用 1 2
    // insert 1
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));

    // insert 2
    m1.insert(make_pair(5, 50));

    // insert 3
    m1.insert(map<int, int>::value_type(6, 60));

    // insert 4
    m1[7] = 70;
    cout << m1[7] << endl;
    cout << m1[8] << endl;  // 自动补充value = 0
    printMap(m1);
    cout << "****************************************" << endl;

    m1.erase(m1.begin());
    printMap(m1);

    m1.erase(3);  // 删除key为3的键值对
    printMap(m1);

    m1.erase(m1.begin(), m1.end());
    printMap(m1);

    m1.clear();
    printMap(m1);
}

void mapFindCount(){
    map<int, int>m1;  // 默认构造 无参构造
    
    // 推荐使用 1 2
    // insert 1
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(2, 40));

    map<int, int>::iterator pos = m1.find(1);
    if (pos != m1.end()){
        cout << "find key-value: " << (*pos).first << " " << pos->second << endl;
    }
    else{
        cout << "not find elem" << endl;
    }

    int num = m1.count(2);  // 对于map而言，为1或者0
    cout << "num: " << num << endl;

}

class MyCompare
{
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void mapSort(){
    map<int, int, MyCompare>m1;  // 默认构造 无参构造
    
    m1.insert(make_pair(5, 50));
    m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));

    for (map<int, int, MyCompare>::iterator it=m1.begin(); it != m1.end(); it++){
        cout << "key: " << it->first << "\t value: " << it->second << endl;
    }
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
}; 

struct ComparePerson {
    map<int, Person>& m1;

    ComparePerson(map<int, Person>& m) : m1(m) {}

    bool operator()(const int& key1, const int& key2) const {
        const Person& p1 = m1.at(key1);
        const Person& p2 = m1.at(key2);

        if (p1.Age == p2.Age) {
            return p1.Name < p2.Name;
        }
        return p1.Age > p2.Age;
    }
};

void mapSortCustomData() {
    map<int, Person> m1;

    Person p1("momo", 18);
    Person p2("nono", 18);
    Person p3("lolo", 18);  
    Person p4("popo", 19);  

    m1.insert(make_pair(1, p1));
    m1.insert(make_pair(2, p2));
    m1.insert(make_pair(3, p3));
    m1.insert(make_pair(4, p4));

    ComparePerson cmp(m1);

    map<int, Person, ComparePerson> sortedMap(m1.begin(), m1.end(), cmp);

    for (const auto& pair : sortedMap) {
        pair.second.ShowPerson();
    }
}

int main(){
    // mapConstructor();
    // mapSizeSwap();
    // mapInsertErase();
    mapFindCount();
    // mapSort();
    // mapSortCustomData();
    return 0;
}