#include<iostream>
#include<string.h>

using namespace std;


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "arr[] 首地址为: " << arr << endl;
    int *p = arr;
    cout << "*p访问的第一个元素 : " << *p << endl;  
    cout << "指针p访问第一个元素的地址为: " << p << endl;

    // 通过指针访问数组元素
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout << "*p访问的元素是 : " << *p << endl;  
        cout << "指针p访问元素的地址为: " << p << endl;
        p++; // 指针偏移
    }

}