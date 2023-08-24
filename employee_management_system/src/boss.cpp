#include "../include/boss.h"



Boss::Boss(int id, string name, int did){
    this->Id = id;
    this->Name = name;
    this->DepartId = did;
}


void Boss::ShowInfo(){
    cout << "Boss Id: " << this->Id << "\t Name: " << this->Name << "\t DepartId" << this->DepartId 
         << "\t Duty: Manage everything in the company" << endl;
   }


string Boss::GetDepartId(){
    return string("Boss");
}