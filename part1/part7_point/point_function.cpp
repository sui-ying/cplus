#include<iostream>
#include<string.h>

using namespace std;

// 值传递: 不改变实参
void swap(int a, int b){
    int tmp = a;
    a = b;
    b = a;
}

// 地址传递: 改变实参
void swap1(int *p1, int *p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main(){
    int a=1, b=2;
    swap(a, b);
    cout << "a: " << a << " b: " << b << endl;

    swap1(&a, &b);
    cout << "a: " << a << " b: " << b << endl;
}