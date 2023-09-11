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

void test_traversal(){
    vector<int>v = {2, 3, 1, 5, 4};

    for_each(v.begin(), v.end(), print01);   // 传入普通函数 
    cout << endl;

    for_each(v.begin(), v.end(), print02());   // 传入函数对象
    cout << endl;
}


int main(){
    test_traversal();
    return 0;
}