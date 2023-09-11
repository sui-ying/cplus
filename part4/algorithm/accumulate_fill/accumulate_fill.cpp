#include<iostream>
#include<vector>
#include<algorithm>

#include<numeric>

using namespace std;

void myPrint(int val){
    cout << val << " ";
}

void test_accumulate(){
    vector<int>v = {2, 3, 1, 5, 4};
    int total = accumulate(v.begin(), v.end(), 0);  // #include<numeric> (beg, end, 起始值)
    cout << "total: " << total << endl;
}

void test_fill(){
    vector<int>v = {2, 3, 1, 5, 4};
    v.resize(10);
    fill(v.begin(), v.end(), 100);    // 将容器区间的元素填充为特定值
    for_each(v.begin(), v.end(), myPrint);              // 遍历算法: 传入普通函数 
    cout << endl;

}

int main(){
    test_accumulate();         // 求和
    test_fill();
    return 0;
}