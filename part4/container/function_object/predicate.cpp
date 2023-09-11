#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// operator()接受一个参数: 一元谓词
class GenerateFive
{
public:
    bool operator()(int val){
        return val > 5;
    }
};

/**
 * @brief 如果operator()接受两个参数，那么叫做二元谓词
 * 
 */
class MyCompare
{
public:
    bool operator()(int val1, int val2){
        return val1 > val2;
    }
};


void test01(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GenerateFive());
    if (pos == v.end()){
        cout << "Not found" << endl;
    }
    else{
        cout << *pos << endl;
    }
}

void printVector(vector<int>& v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test02(){
    vector<int>v = {2, 3, 1, 5, 4};
    
    sort(v.begin(), v.end());  // 默认升序
    printVector(v);

    sort(v.begin(), v.end(), MyCompare());  // 使用函数对象，从大到小排序
    printVector(v);
}

int main(){
    test01();
    test02();
    return 0;
}   