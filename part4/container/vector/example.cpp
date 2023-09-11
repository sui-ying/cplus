#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>  // 标准算法头文件


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

    void ShowPerson(){
        cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
    }
}; 


void MyPrint(int val){
    cout << val << endl;
}

void test01(){
    vector<int>v;  // 创建vector, 需要包含头文件 #include<vector>

    cout << "v.size(): " << v.size() << endl;
    // 利用push_back在v尾部添加元素
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << "v.size(): " << v.size() << endl;

    vector<int>::iterator itBegin = v.begin();  //  起始迭代器 执行容器中的第一个元素
    vector<int>::iterator itEnd = v.end();  // 结束迭代器 指向容器 最后一个元素的下一个位置

    // 第一种遍历元素方式
    while (itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++; 
    }

    // 第二种遍历元素方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        // it 指向容器中第一个元素的地址
        cout << *it << endl;
    }

    // 第三种遍历元素方式，使用STL提供的遍历算法； 需要包含头文件 #include<algorithm>
    for_each(v.begin(), v.end(), MyPrint);  // 起始、末尾、函数名
}


void test02(){
    vector<Person> v;

    Person p1("momo", 18);
    Person p2("nono", 18);
    Person p3("lolo", 18);  

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        // cout << "Name: " << it->Name << "\t Age: " << it->Age << endl;
        (*it).ShowPerson();  // 打印信息； it为指针， (*it)为person对象
    }

}

void test03(){
    vector<Person*> v;  // 存放Person 类型指针

    Person p1("momo", 18);
    Person p2("nono", 18);
    Person p3("lolo", 18);  

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        // cout << *it << endl;  // *it 为person对象的地址
        // cout << **it << endl; // **it 为person对象
        // cout << "Name: " << (*it)->Name << "\t Age: " << (*it)->Age << endl;
        (*(*it)).ShowPerson();  // 打印信息； it为指针， (*it)为person对象
       
    }
}


void test04(){
    vector<vector<int>>v;

    // 初始化小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 小容器添加元素
    for (int i=0; i<4; i++){
        v1.push_back(i);
        v2.push_back(i);
        v3.push_back(i);
        v4.push_back(i);
    }

    // 大容器添加小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 打印大容器信息
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++){
        // *it ---- vector<int>
        for (vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); jt++){
            cout << *jt << " ";
        }
        cout << endl;
    }

}

int main(){
    // test01(); // 认识vector
    // test02(); // 测试 存放Person类型数据
    // test03(); //   测试 存放Person类型指针数据
    test04();   // 测试 vector嵌套vector
}