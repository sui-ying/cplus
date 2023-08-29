#include "../include/employee.h"



Employee::Employee(int id, string name, int did){
    this->Id = id;
    this->Name = name;
    this->DepartId = did;
}


void Employee::ShowInfo(){
    cout << "Employee Id: " << this->Id 
         << "\t Name: " << this->Name 
         << "\t DepartId: " << this->DepartId 
         << "\t Duty: Complete the tasks assigned by the manager" << endl;
   }


string Employee::GetDepartId(){
    return string("employee");
}