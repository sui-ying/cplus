#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void myPrint(int val){
    cout << val << " ";
}

void test_set_intersection(){
    vector<int>v = {1, 2, 3, 4, 5};
    vector<int>v2 = {3, 4, 5, 6, 7};

    vector<int>vt;
    vt.resize(min(v.size(), v2.size()));  // 定义容器大小

    // 求交集
    vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), vt.begin());
    for_each(vt.begin(), itEnd, myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;
}

void test_set_union(){
    vector<int>v = {1, 2, 3, 4, 5};
    vector<int>v2 = {3, 4, 5, 6, 7};

    vector<int>vt;
    vt.resize(v.size()+v2.size());  // 定义容器大小

    // 求并集
    vector<int>::iterator itEnd = set_union(v.begin(), v.end(), v2.begin(), v2.end(), vt.begin());
    for_each(vt.begin(), itEnd, myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;
}

void test_set_difference(){
    vector<int>v = {1, 2, 3, 4, 5};
    vector<int>v2 = {3, 4, 5, 6, 7};

    vector<int>vt1;
    vt1.resize(max(v.size(), v2.size()));  // 定义容器大小
    // 求v1与v2的差集
    vector<int>::iterator itEnd1 = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), vt1.begin());
    for_each(vt1.begin(), itEnd1, myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;

    vector<int>vt2;
    vt2.resize(max(v.size(), v2.size()));  // 定义容器大小
    // 求v2与v1的差集
    vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v.begin(), v.end(), vt2.begin());
    for_each(vt2.begin(), itEnd2, myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;
}

int main(){
    test_set_intersection();       // 求交集
    test_set_union();              // 求并集
    test_set_difference();         // 求差集
    return 0;
}