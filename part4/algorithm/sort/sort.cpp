#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>

using namespace std;


void printVector(vector<int>& v){

    // for (const auto& element : v) {
    //     std::cout << element << " ";
    // }
    // cout << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void myPrint(int val){
    cout << val << " ";
}

void test_sort(){
    vector<int>v = {2, 3, 1, 5, 4};
    printVector(v);
    
    sort(v.begin(), v.end());  // Ascending sort
    printVector(v);

    sort(v.begin(), v.end(), greater<int>());  // Descending sort
    printVector(v);
}

void test_random_shuffle(){
    srand((unsigned int)time(NULL));   // #include<ctime>
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    printVector(v);
    random_shuffle(v.begin(), v.end());  // 洗牌算法

    for_each(v.begin(), v.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;

}

void test_merge(){
    vector<int>v1 = {2, 3, 1, 5, 4};
    vector<int>v2 = {6, 1, 5, 9};

    vector<int>vTarget;
    // vTarget.resize(100);
    vTarget.resize(v1.size() + v2.size());  // 需要给目标容器分配空间
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;
}

void test_reverse(){
    vector<int>v = {2, 3, 1, 5, 4};
    reverse(v.begin(), v.end());            // 容器反转
    for_each(v.begin(), v.end(), myPrint);  // 遍历算法: 传入普通函数 
    cout << endl;
}

int main(){
    test_sort();
    test_random_shuffle();
    test_merge();
    test_reverse();
    return 0;
}