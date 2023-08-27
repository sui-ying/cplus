#pragma once
#include<iostream>

using namespace std;

template<class T>
class MyArray
{
public:
    /**
     * @brief Construct a new My Array object
     * 
     * @param capacity 容量
     */
    MyArray(int capacity){
        cout << "调用有参构造函数" << endl;
        this->Capacity = capacity;
        this->Size = 0;
        this->pAddress = new T[this->Capacity];
    }

    ~MyArray(){
        cout << "调用析构函数" << endl;
        if (this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    /**
     * @brief Construct a new My Array object
     * 
     * @param arr 
     */
    MyArray(const MyArray & arr){
        cout << "调用拷贝构造函数" << endl;
        this->Capacity = arr.Capacity;
        this->Size = arr.Size;
        // this->pAddress = arr.pAddress;  //浅拷贝

        // 深拷贝
        this->pAddress = new T[this->Capacity];
        // 将arr中的数据都拷贝过来
        for (int i=0; i<this->Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    /**
     * @brief 赋值运算符重载
     * 
     */
    MyArray & operator=(const MyArray & arr){
        cout << "赋值运算符重载" << endl;
        // 先判断原来堆区是否有数据，如果有需要释放
        if (this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->Capacity = 0;
            this->Size = 0;
        }

        // deep copy
        this->Capacity = arr.Capacity;
        this->Size = arr.Size;
        this->pAddress = new T[this->Capacity];
        // 将arr中的数据都拷贝过来
        for (int i=0; i<this->Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    /**
     * @brief 尾部插入一个元素
     * 
     * @param val 
     */
    void PushBack( const T & val){
        if (this->Capacity == this->Size){
            return;
        }
        // 更新数组
        this->pAddress[this->Size] = val;
        this->Size++;  
    }

    /**
     * @brief 删除尾部一个元素
     * 
     */
    void PopBack(){
        if (this->Size == 0){
            return;
        }
        // delete[] this->pAddress[this->Size];
        this-Size--;
    }

    /**
     * @brief 
     * 
     * @param index 
     * @return T& 
     */
    T & operator[](int index){
        return this->pAddress[index];
    }

    int GetSize(){
        return this->Size;
    }

    int GetCapacity(){
        return this->Capacity;
    }

private:
    T * pAddress;  // 
    int Capacity;  // 
    int Size;
};