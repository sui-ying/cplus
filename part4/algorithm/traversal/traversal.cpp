#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void print01(int val){
    cout << val << " ";
}

class print02
{
public:
    void operator()(int val){
        cout << val << " ";
    }

};

class Transform
{
public:
    int operator()(int val){
        return -val;
    }
};

void test_traversal(){
    vector<int>v = {2, 3, 1, 5, 4};
    // Todo
    for_each(v.begin(), v.end(), print01);   // 传入普通函数 
    cout << endl;

    for_each(v.begin(), v.end(), print02());   // 传入函数对象
    cout << endl;
}

void test_transform(){
    vector<int>v = {2, 3, 1, 5, 4};
    vector<int>v2;
    v2.resize(v.size());
    
    transform(v.begin(), v.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), print01);   // 传入普通函数 
    cout << endl;


}

int main(){
    test_traversal();
    test_transform();
    return 0;
}