#include<iostream>
#include<string>
using namespace std;

int main(){
    
    // 定义方式1: 维度；初始化
    int arr1[2][3] = {};
    // 
    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[0][2] = 3;
    arr1[1][0] = 4;
    arr1[1][1] = 5;
    arr1[1][2] = 6;
    
    // (推荐）定义方式2: 维度 + 初始化
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // 定义方式3: 维度 + 初始化
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};
    
    // 定义方式4: 维度 + 初始化
    int arr4[][3] = {1, 2, 3, 4, 5, 6};

    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }


    // 查看二位数组所占用的内存空间
    cout << "sizeof(arr2): " << sizeof(arr2) << endl;
    // 查看二维数组的首地址
    cout << "二维数组的首地址arr2[0][0]: " << &arr2 << endl;

    // 查看二维数组元素的个数
    cout << sizeof(arr2)/sizeof(arr2[0][0]) << endl;
    // 计算二维组数的行数
    cout << "二维组数的行数: " << sizeof(arr2)/sizeof(arr2[0]) << endl;
    // 计算二维组数的列数
    cout << "二维组数的列数: " << sizeof(arr2[0])/sizeof(arr2[0][0]) << endl;

    
}