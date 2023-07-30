#include<iostream>

using namespace std;

// 常量引用: 用来修饰形参，防止误操作

void ShowValue(int &val){
    val = 100;
    cout << "val: " << val << endl; 
}

/**
 * @brief // 加入const之后变为只读，不可以修改
 * @param val 
 */
void ShowValue1(const int &val){
    // val = 100;
    cout << "val: " << val << endl; 
}

int main(){
    const int &ref = 10;
    // ref = 20; // 加入const之后变为只读，不可以修改
    
    int a = 10;
    ShowValue(a);

    ShowValue1(a); // 不可更改
}