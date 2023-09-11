#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;


/**
 * @brief print deque v
 * 
 * @param d 
 */
void Printdeque(deque<int>& d){
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


/**
 * @brief deque Constructor function
 * 
 */
void dequeConstructor(){
    deque<int> d1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        d1.push_back(i);
    }

    Printdeque(d1);

    deque<int> d2(d1.begin(), d1.end());  // 通过区间进行构造
    Printdeque(d2);

    deque<int> d3(10, 100);  //  赋值方式
    Printdeque(d3);

    deque<int> d4 = d3;  // 拷贝构造方式 operator=
    Printdeque(d4);

    // cout << &d3[0] << endl;
    // cout << &d4[0] << endl;
}

/**
 * @brief deque assign
 * 
 */
void dequeAssign(){
    deque<int> d1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        d1.push_back(i);
    }

    Printdeque(d1);
    deque<int> d4 = d1;  // 拷贝构造方式
    Printdeque(d4);

    deque<int> d5;
    d5.assign(d1.begin(), d1.end());  //前闭后开[)
    Printdeque(d5);

    deque<int> d6;
    d6.assign(10, 100);
    Printdeque(d6);

}

void dequeSize(){
    deque<int> d1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        d1.push_back(i);
    }

    if (d1.empty()){
        cout << "d1 is empty" << endl;
    }
    else{
        // cout << "capcity of deque d1: " << d1.capacity() << endl; 
        cout << "size of deque d1: " << d1.size() << endl; 
    }

    d1.resize(20, 1);
    // cout << "capcity of deque d1: " << d1.capacity() << endl; 
    cout << "size of deque d1: " << d1.size() << endl; 
    Printdeque(d1);
}

/**
 * @brief deque insert && erase
 * 
 */
void dequeInsertErase(){
    deque<int> d1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        d1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    Printdeque(d1);

    d1.pop_back();  // 使用pop_back在容器末尾删除一个元素
    Printdeque(d1);

    d1.insert(d1.begin(), 100);  // 迭代器指向位置插入元素elem
    Printdeque(d1);

    d1.insert(d1.begin(), 2, 100);  // 迭代器指向位置pos插入count个元素elem
    Printdeque(d1);

    d1.erase(d1.begin());  // 删除迭代器指向的元素
    Printdeque(d1);

    d1.erase(d1.begin() + 4);  // 删除迭代器指向的元素
    Printdeque(d1);

    d1.push_front(0);  // 使用push_front在容器首添加一个元素
    Printdeque(d1);

    d1.pop_front();  // 使用push_front在容器首删除一个元素
    Printdeque(d1);

    d1.insert(d1.begin(), d1.begin(), d1.end());  //  在首位置插入自己
    Printdeque(d1);

    d1.erase(d1.begin(), d1.end());  // 删除迭代器从begin到end之间的元素
    Printdeque(d1);

    d1.clear(); 
}

void dequeAccess(){
    deque<int> d1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        d1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    Printdeque(d1);

    for (int i=0; i<d1.size(); i++){
        cout << d1[i] << " ";  // 通过[]访问
    }
    cout << endl;

    for (int i=0; i<d1.size(); i++){
        cout << d1.at(i) << " ";  // 通过at访问
    }
    cout << endl;

    cout << "First elem of d1, d1.front(): " << d1.front() << endl; // 第一个元素
    cout << "Last elem of d1, d1.front(): " << d1.back() << endl;  // 最后一个元素

}

/**
 * @brief 排序, 默认升序
 * 
 */
void dequeSort(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    Printdeque(d);

    sort(d.begin(), d.end());  // #include<algorithm>
    Printdeque(d);

}

int main(){
    // dequeConstructor();
    // dequeAssign();
    // dequeSize();
    // dequeInsertErase();
    // dequeAccess();
    // dequeSwap();
    // dequeReserve();
    dequeSort();
}