#include<iostream>
#include<vector>

using namespace std;


/**
 * @brief print vector v
 * 
 * @param v 
 */
void PrintVector(vector<int>& v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


/**
 * @brief vector Constructor function
 * 
 */
void vectorConstructor(){
    vector<int> v1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }

    PrintVector(v1);

    vector<int> v2(v1.begin(), v1.end());  // 通过区间进行构造
    PrintVector(v2);

    vector<int> v3(10, 100);  //  赋值方式
    PrintVector(v3);

    vector<int> v4 = v3;  // 拷贝构造方式 operator=
    PrintVector(v4);

    // cout << &v3[0] << endl;
    // cout << &v4[0] << endl;
}

/**
 * @brief vector assign
 * 
 */
void vectorAssign(){
    vector<int> v1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }

    PrintVector(v1);
    vector<int> v4 = v1;  // 拷贝构造方式
    PrintVector(v4);

    vector<int> v5;
    v5.assign(v1.begin(), v1.end());  //前闭后开[)
    PrintVector(v5);

    vector<int> v6;
    v6.assign(10, 100);
    PrintVector(v6);

}

void vectorCapacitySize(){
    vector<int> v1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }

    if (v1.empty()){
        cout << "v1 is empty" << endl;
    }
    else{
        cout << "capcity of vector v1: " << v1.capacity() << endl; 
        cout << "size of vector v1: " << v1.size() << endl; 
    }

    v1.resize(20, 1);
    cout << "capcity of vector v1: " << v1.capacity() << endl; 
    cout << "size of vector v1: " << v1.size() << endl; 
    PrintVector(v1);
}

/**
 * @brief vector insert && erase
 * 
 */
void vectorInsertErase(){
    vector<int> v1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        v1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    PrintVector(v1);

    v1.pop_back();  // 使用pop_back在容器末尾删除一个元素
    PrintVector(v1);

    v1.insert(v1.begin(), 100);  // 迭代器指向位置插入元素elem
    PrintVector(v1);

    v1.insert(v1.begin(), 2, 100);  // 迭代器指向位置pos插入count个元素elem
    PrintVector(v1);

    v1.erase(v1.begin());  // 删除迭代器指向的元素
    PrintVector(v1);

    v1.erase(v1.begin() + 4);  // 删除迭代器指向的元素
    PrintVector(v1);

    v1.erase(v1.begin(), v1.end());  // 删除迭代器从begin到end之间的元素
    PrintVector(v1);

    v1.clear(); 
}

void vectorAccess(){
    vector<int> v1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        v1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    PrintVector(v1);

    for (int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";  // 通过[]访问
    }
    cout << endl;

    for (int i=0; i<v1.size(); i++){
        cout << v1.at(i) << " ";  // 通过at访问
    }
    cout << endl;

    cout << "First elem of v1, v1.front(): " << v1.front() << endl; // 第一个元素
    cout << "Last elem of v1, v1.front(): " << v1.back() << endl;  // 最后一个元素

}

/**
 * @brief vector swap
 * 
 */
void vectorSwap(){
    vector<int> v1;  // 默认构造 无参构造
    for (int i=0; i<10; i++){
        v1.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    PrintVector(v1);     

    vector<int> v2;  // 默认构造 无参构造
    for (int i=10; i>0; i--){
        v2.push_back(i);  // 使用push_back在容器末尾添加元素i
    }
    PrintVector(v2);    

    v1.swap(v2);
    cout << "v1.swap(v2): " << endl;
    PrintVector(v1);   
    PrintVector(v2);   

    
    vector<int> v3;  // 默认构造 无参构造
    for (int i=0; i<100000; i++){
        v3.push_back(i);  // 使用push_back在容器末尾添加元素i
    }

    cout << "v3.capacity(): " << v3.capacity() << " v3.size(): " << v3.size() << endl;
    v3.resize(3);
    cout << "v3.capacity(): " << v3.capacity() << " v3.size(): " << v3.size() << endl;
    // 实际用途: 利用swap收缩空间
    vector<int>(v3).swap(v3);  // 匿名对象, 系统回收析构
    cout << "v3.capacity(): " << v3.capacity() << " v3.size(): " << v3.size() << endl;

}

/**
 * @brief vector 预留空间
 * 
 */
void vectorReserve(){
    
    vector<int> v;  // 默认构造 无参构造
    int num = 0;  // 统计vector开辟次数
    int *p = NULL;

    for (int i=0; i<100000; i++){
        v.push_back(i);  // 使用push_back在容器末尾添加元素i
        if (p != &v[0]){
            p = &v[0];
            num++;
            cout << "v.capacity(): " << v.capacity() << " v.size(): " << v.size() << endl;
        }
    }
    cout << "num: " << num << endl;

    vector<int> v1;
    v1.reserve(10000);   // 提前知道vector大小，可以提前预留空间
    int num1 = 0;  // 统计vector开辟次数
    int *p1 = NULL;

    for (int i=0; i<100000; i++){
        v1.push_back(i);  // 使用push_back在容器末尾添加元素i
        if (p1 != &v[0]){
            p1 = &v[0];
            num1++;
            cout << "v1.capacity(): " << v1.capacity() << " v1.size(): " << v1.size() << endl;
        }
    }
    cout << "num1: " << num1 << endl;

}

int main(){
    vectorConstructor();
    vectorAssign();
    vectorCapacitySize();
    vectorInsertErase();
    vectorAccess();
    vectorSwap();
    vectorReserve();

}