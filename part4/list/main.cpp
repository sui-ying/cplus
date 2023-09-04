#include<iostream>
using namespace std;

#include<list>
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

void printlist(list<int>&l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void listConstructor(){
    list<int>l1;  // 创建list, 需要包含头文件 #include<list>

    cout << "l1.size(): " << l1.size() << endl;
    // 利用push_back在v尾部添加元素
    l1.push_back(0);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    cout << "l1.size(): " << l1.size() << endl;
    printlist(l1);

    list<int>::iterator itBegin = l1.begin();  //  起始迭代器 执行容器中的第一个元素
    list<int>::iterator itEnd = l1.end();  // 结束迭代器 指向容器 最后一个元素的下一个位置

    // 第一种遍历元素方式
    while (itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++; 
    }

    // 第二种遍历元素方式
    for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        // it 指向容器中第一个元素的地址
        cout << *it << endl;
    }

    // 第三种遍历元素方式，使用STL提供的遍历算法； 需要包含头文件 #include<algorithm>
    for_each(l1.begin(), l1.end(), MyPrint);  // 起始、末尾、函数名

    list<int>l2(l1.begin(), l1.end());
    printlist(l2);

    list<int>l3(l1);
    printlist(l3);

    list<int>l4(10, 100);
    printlist(l4);
}

/**
 * @brief list assign
 * 
 */
void listAssign(){
    list<int> l1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        l1.push_back(i);
    }

    printlist(l1);
    list<int> l4 = l1;  // 拷贝构造方式
    printlist(l4);

    list<int> l5;
    l5.assign(l1.begin(), l1.end());  //前闭后开[)
    printlist(l5);

    list<int> l6;
    l6.assign(10, 100);
    printlist(l6);

}

void listSize(){
    list<int> l1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        l1.push_back(i);
    }

    if (l1.empty()){
        cout << "l1 is empty" << endl;
    }
    else{
        // cout << "capcity of list l1: " << l1.capacity() << endl; 
        cout << "size of list l1: " << l1.size() << endl; 
    }

    l1.resize(20, 1);
    // cout << "capcity of list l1: " << l1.capacity() << endl; 
    cout << "size of list l1: " << l1.size() << endl; 
    printlist(l1);
}

/**
 * @brief list insert && erase
 * 
 */
void listInsertErase(){
    list<int> l1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        l1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    printlist(l1);

    for (int i=10; i>0; i--){
        l1.push_front(i * 10);  // 使用push_front在容器首添加元素i * 10
    }
    printlist(l1);

    l1.pop_back();  // 使用pop_back在容器末尾删除一个元素
    printlist(l1);

    l1.pop_front();  // 使用pop_back在容器首删除一个元素
    printlist(l1);

    l1.insert(l1.begin(), 100);  // 迭代器指向位置插入元素elem
    printlist(l1);

    l1.insert(l1.begin(), 2, 200);  // 迭代器指向位置pos插入count个元素elem
    printlist(l1);

    l1.erase(l1.begin());  // 删除迭代器指向的元素
    printlist(l1);

    l1.erase(l1.begin()++);  // 删除迭代器指向的元素
    printlist(l1);

    // l1.erase(l1.begin() + 4);  // 不支持随机访问
    // printlist(l1);

    l1.remove(100);  // 删除容器中所有为特定值100的元素
    printlist(l1);

    l1.erase(l1.begin(), l1.end());  // 删除迭代器从begin到end之间的元素
    printlist(l1);
    
    l1.clear();   // 清空
    printlist(l1);
}

void listAccess(){
    list<int> l1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        l1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    printlist(l1);

    // 不可以通过[]访问
    // for (int i=0; i<l1.size(); i++){
    //     cout << l1[i] << " ";  
    // }
    // cout << endl;

    // 不可以通过at访问
    // for (int i=0; i<l1.size(); i++){
    //     cout << l1.at(i) << " ";  // 通过at访问
    // }
    // cout << endl;

    cout << "First elem of l1, l1.front(): " << l1.front() << endl; // 第一个元素
    cout << "Last elem of l1, l1.back(): " << l1.back() << endl;  // 最后一个元素

}

/**
 * @brief list swap
 * 
 */
void listSwap(){
    list<int> l1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        l1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    printlist(l1);     

    list<int> l2;  // 默认构造 无参构造
    for (int i=10; i>0; i--){
        l2.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    printlist(l2);    

    l1.swap(l2);
    cout << "l1.swap(l2): " << endl;
    printlist(l1);   
    printlist(l2);   
}

/**
 * @brief 仿函数
 * 
 * @param v1 
 * @param v2 
 * @return true 
 * @return false 
 */
bool myCompare(int v1, int v2){
    return v1 > v2;
}

/**
 * @brief list reverse && sort
 * 
 */
void listReverse(){
    list<int> l1;  // 默认构造 无参构造
    l1.push_back(3);
    l1.push_back(5);
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(1);
    printlist(l1);

    l1.reverse();
    cout << "reverse l1: ";  
    printlist(l1);

    cout << "sort l1: ";  
    // sort(l1.begin(), l1.end());  // list不是连续的线性空间，不支持随机访问，不可以使用标准库算法
    l1.sort();  // 调用其成员函数， 默认升序
    printlist(l1);

    l1.sort(myCompare);  // 降序
    printlist(l1);
}


int main(){
    listConstructor();
    listAssign();
    listSize();
    listInsertErase();
    listAccess();
    listSwap();
    listReserve();
    listReverse();

}