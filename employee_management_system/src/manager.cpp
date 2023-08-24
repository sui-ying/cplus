#include "../include/manager.h"



Manager::Manager(int id, string name, int did){
    this->Id = id;
    this->Name = name;
    this->DepartId = did;
}


void Manager::ShowInfo(){
    cout << "Manager Id: " << this->Id << "\t Name: " << this->Name << "\t DepartId" << this->DepartId 
         << "\t Duty: Complete the tasks assigned by the BOSS and distribute tasks to employees" << endl;
   }


string Manager::GetDepartId(){
    return string("manager");
}