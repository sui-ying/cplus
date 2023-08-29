#pragma once  // 防止头文件重复包含输入
#include<iostream>  //  包含输入输出流文件
#include<string>

using namespace std; //  使用标准命名空间


class Worker
{
public:
    int Id;
    string Name;
    int DepartId;

    // pure virtual function 
    virtual void ShowInfo() = 0;
    virtual string GetDepartId() = 0;
};