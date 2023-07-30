#include<iostream>
#include<string.h>

using namespace std;

/**
 * @brief 冒泡排序函数
 * @param arr 数组首地址
 * @param len 数组长度
 */
void bubble_sort(int *arr, int len){
    for (int i=0; i<len-1; i++){
        for (int j=0; j<len-1-i; j++){
            // 判断大小
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

/**
 * @brief 逐一打印数组中元素的值
 * @param arr 数组首地址
 * @param len 数组长度
 */
void PrintArray(int *arr, int len){
    for (int i=0; i<len; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}


int main(){

    //  创建数组
    int arr[9] = {6, 3, 5, 7, 8, 4, 2, 9, 1};
    // 数组长度
    int len = sizeof(arr)/sizeof(arr[0]);
    // 函数调用
    bubble_sort(arr, len);
    PrintArray(arr, len);
    
}