#pragma once  // 防止头文件重复包含输入
#include<iostream>  //  包含输入输出流文件
#include "worker.h"
using namespace std; //  使用标准命名空间


class WorkManager
{
public:

    // 记录职工人数
    int EmpNum;
    // 职工数组指针
    Worker **EmpArray;
    bool file_is_empty;
    
    // construct functioin
    WorkManager();

    // Member function
    void ShowMenu();  // show menu info
    void ExitSystem();  // exit EMS

    
    void Add_Emp();  // add info of Employee
    void Save_Emp();  // save the info of Employee to txt
    int Get_EmpNum(); // get number of employee, return number
    void init_Emp();
    void Show_Emp();  // show employee info
    void Delete_Emp();
    int IsExist(int id);
    void Modify_Emp();
    void Search_Emp();
    void Sort_Emp();
    void Clear_Emp();
    
    // desctruct function
    ~WorkManager();
};



