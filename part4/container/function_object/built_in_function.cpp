#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @brief 算术仿函数
 * 
 */
void test_arithmetic_function(){
    negate<int>n;  // 一元仿函数 取反仿函数
    cout << n(50) << endl;

    plus<int>p;   // 二元仿函数 加法
    cout << p(1, 2) << endl;
}

void printVector(vector<int>& v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test_relational_function(){
    vector<int> v = {2, 1, 4, 3, 5};
    printVector(v);
    sort(v.begin(), v.end());  // 从小到大排序
    printVector(v);
    sort(v.begin(), v.end(), greater<int>());  // 从大到小排序
    printVector(v);
}

void test_logical_function(){
    vector<bool> v = {true, false, true, false, true};
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it ? "true" : "false") << " ";
    }
    cout << endl;

    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());  // 逻辑非

    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++){
        cout << (*it ? "true" : "false") << " ";
    }
    cout << endl;
}

int main(){
    test_arithmetic_function();
    test_relational_function();
    test_logical_function();
    return 0;
}