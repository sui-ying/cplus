#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void myPrint(int val){
    cout << val << " ";
}

/**
 * @brief copy
 * 
 */
void test_copy(){
    vector<int>v = {2, 3, 1, 5, 4};
    vector<int>v2;
    v2.resize(v.size());   // 需要给目标容器分配空间
    copy(v.begin(), v.end(), v2.begin());  // 

    for_each(v2.begin(), v2.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;

    v2.resize(v.size() * 2);
    for_each(v2.begin(), v2.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;

    copy(v.begin(), v.end(), v2.begin()+v.size()); 
    for_each(v2.begin(), v2.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;
}

void test_replace(){
    vector<int>v = {2, 3, 1, 5, 4};
    replace(v.begin(), v.end(), 1, 10);     // 替换算法: (beg, end, oldValue, newValue)
    for_each(v.begin(), v.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;
}

class Replace
{
public:
    int Thres;
    Replace(int thres=0): Thres(thres){}

    bool operator()(int val){
        return val > this->Thres;  // 大于Thres
    }
};

void test_replace_if(){
    vector<int>v = {2, 3, 1, 5, 4};
    replace_if(v.begin(), v.end(), Replace(3), 10);     // 按条件替换算法: (beg, end, _predicate, newValue)
    for_each(v.begin(), v.end(), myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;
}

void test_swap(){
    vector<int>v = {2, 3, 1, 5, 4};
    vector<int>v2;
    v2.resize(v.size());
    // v.swap(v2);  
    swap(v, v2);  // 交换两个容器

    for_each(v.begin(), v.end(), myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;

    for_each(v2.begin(), v2.end(), myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;
}

int main(){
    test_copy();         // 拷贝算法
    test_replace();      // 替换算法
    test_replace_if();   // 按条件替换算法

    test_swap();         // 交换算法
    return 0;
}