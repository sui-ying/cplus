// 普通员工文件
#pragma once  // 防止头文件重复包含输入
#include<iostream>  //  包含输入输出流文件
#include<string>

#include "worker.h"

class Employee: public Worker
{
public:

    // // construcot function
    // Employee(int id, string name, int did);

    // // 继承需要重写父类中的虚函数
    // void ShowInfo();
    // string GetDepartId();

    Employee(int id, string name, int did){
        this->Id = id;
        this->Name = name;
        this->DepartId = did;
    }


    void ShowInfo(){
        cout << "Employee Id: " << this->Id << "\t Name: " << this->Name << "\t DepartId" << this->DepartId 
            << "\t Duty: Complete the tasks assigned by the manager" << endl;
    }


    string GetDepartId(){
        return string("employee");
    }
};
