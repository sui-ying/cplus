#include<iostream>
#include<string>
using namespace std;


// 数组: 数组元素都是相同的数据类型，由连续的内存位置组成的
int main(){
    
    // 定义方式1
    int score[5] = {95, 85, 75};  // 若没有初始化，整型数组默认为0

    // 定义方式2
    string students[] = {"A", "B", "C", "D"};

    // 定义方式3
    int tier[4] = {1, 2, 3, 4};


    // 数组所占用的内存空间
    cout << "Menmory of array score: " << sizeof(score) << endl;
    // 统计数组中的元素个数
    int length = sizeof(score) / sizeof(score[0]);
    cout << "length of array score: " << length << endl;
        
    // 取数据元素; 和python类似
    for (int i=0; i<length; i++){
        cout << "score[" << i << "] == " << score[i] << "\t";
    }
    cout << endl;

    // 获取数组中内存的首地址
    cout << "The address of first element in the array score: " << &score[0] << endl;
    // cout << &score[1] << endl;
    
    // 数组逆置
    for (int i=0; i<length/2; i++){
        int tmp = score[i];
        score[i] = score[length-1-i];
        score[length-1-i] = tmp;
    }
    for (int i=0; i<length; i++){
        cout << score[i] << "\t";
    }
    cout << endl;


    // 冒泡排序
    int arr[] = {6, 3, 5, 7, 8, 4, 2, 9, 1};
    for (int i=0; i<sizeof(arr)/sizeof(arr[0])-1; i++){
        for (int j=0; j<sizeof(arr)/sizeof(arr[0])-1-i; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}