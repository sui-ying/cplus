// 普通员工文件
#pragma once  // 防止头文件重复包含输入
#include<iostream>  //  包含输入输出流文件
#include<string>

#include "worker.h"

class Boss: public Worker
{
public:

    // construct function
    // Boss(int id, string name, int did);
    

    // // 继承需要重写父类中的虚函数
    // void ShowInfo();
    // string GetDepartId();

    Boss(int id, string name, int did){
    this->Id = id;
    this->Name = name;
    this->DepartId = did;
    }


    void ShowInfo(){
        cout << "Boss Id: " << this->Id << "\t Name: " << this->Name << "\t DepartId" << this->DepartId 
            << "\t Duty: Manage everything in the company" << endl;
    }


    string GetDepartId(){
        return string("Boss");
    }
};
