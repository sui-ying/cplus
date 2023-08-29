#include<iostream>
using namespace std;



void SwapInt(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void SwapDouble(double &a, double &b){
    double tmp = a;
    a = b;
    b = tmp;
}

/** 
 * @brief 函数模板
 * 
 * @tparam T 
 * @param a 
 * @param b 
 */
template<typename T>  // 声明一个模板，告诉编译器后面的代码中紧跟着的T不要报错，T是一个通用数据类型
void Swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief 使用下面无参函数时，一定要告诉编译器函数类型
 * 
 * @tparam T 
 */
template<typename T>
void func(){
    cout << "call func()" << endl;
}

/**
 * @brief selection sort template
 * 
 * @tparam T 
 * @param arr 
 * @param len 
 */
template<typename T>
void SelectionSort(T *arr, int len){
    // int len = sizeof(arr)/sizeof(arr[0]);  // 计算数组长度是错误的，因为当参数传递为指针时，无法获取到数组的真实长度
    for (int i=0; i<len; i++){
        int min_index = i;
        for (int j=i+1; j<len; j++){
            if (arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        Swap<T>(arr[i], arr[min_index]);
    }
}

/**
 * @brief print arr template
 * 
 * @tparam T 
 * @param arr 
 * @param len 
 */
template<typename T>
void PrintArr(T *arr, int len){
    for (int i=0; i<len; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}


// ********************** 普通函数与函数模板的区别 ************************ //
/**
 * @brief 普通函数调用是可以发生自动类型转换
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int TwoNumAdd1(int a, int b){
    return a+b;
}

/**
 * @brief 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
 * 
 * @tparam T 
 * @param a 
 * @param b 
 * @return T 
 */
template<typename T>
T TwoNumAdd2(T a, T b){
    return a+b;
}


// ********************** 普通函数与函数模板的调用规则 ************************ //

void PrintInfo(int a, int b){
    cout << "call normal function PrintInfo" << endl;
}

template<typename T>
void PrintInfo(T a, T b){
    cout << "call template function PrintInfo" << endl;
}

void test01(){
    int a = 10;
    int b = 20;
    SwapInt(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    double c = 1.1;
    double d = 2.2;
    SwapDouble(c, d);
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    // 函数模板的两种使用方式
    // 1. 自动类型推导
    Swap(a, b);  // template
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // 2. 显示指定类型  Swap<double>
    Swap<double>(c, d);  
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    // Swap(a, c);  //数据类型不一致

}

void test02(){
    // func();
    func<int>();  // 必须确定函数类型
}

void test03(){
    int arr[] = {1, 3, 6, 2, 4, 5};
    // char arr[] = "agesve";
    int len = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, len);
    PrintArr(arr, len);
    
}

void test04(){
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << TwoNumAdd1(a, b) << endl;
    cout << TwoNumAdd1(a, c) << endl;  

    // cout << TwoNumAdd2(a, c) << endl;  // 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
    cout << TwoNumAdd2<int>(a, c) << endl; // 如果利用显示指定类型的方式，可以发生隐式类型转换

}

void test05(){
    int a = 10;
    int b = 20;
    PrintInfo(a, b); // 如果普通函数和模板函数都可以调用，优先调用普通函数

    // PrintInfo<>(a, b); // 通过空参数列表，可以强制调用模板函数

    // PrintInfo(a, b, 1); // 通过函数重载，调用模板函数

    char c = 'c';
    char d = 'd';
    // 通过函数模板产生更好的匹配，优先调用函数模板
    PrintInfo(c, d);  // 如果函数模板可以产生更好的匹配，优先调用函数模板；此处调用普通函数的话需要对数据进行转换
}

int main(){
    // test01();
    // test02();
    // test03();  // 模板示例: 选择排序

    // test04(); // 测试普通函数和模板函数

    test05(); // 普通函数和模板函数的调用规则
}