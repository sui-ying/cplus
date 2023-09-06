#include<iostream>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

#define Num 10
#define Planning 1
#define Publicity 2
#define RD 3
/*********************************** 需求 ***********************************/
// 10 employee(ABCDEFGHIJ)，指定工作部门(planning, publicity, RD)
// empoyloyee info: Name, Salary; 随机给定工资和分配部门
// 通过multimap进行信息的插入: 部门编号id，员工
// 分部门显示员工信息

class Employee
{
public:
    string Name;
    int Salary;

    void printEmployee(){
        cout << "Name: " << this->Name << "\t Salary: " << this->Salary << endl;
    }
};

void creatEmployee(vector<Employee>& v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i=0; i<Num; i++){
        Employee em;
        em.Name = "emp_";
        em.Name += nameSeed[i];
        em.Salary = rand()%20 + 20;  // 20~40k
        v.push_back(em);
    }
}

void printVectorEmployee(vector<Employee>& v){
    for(vector<Employee>::iterator it=v.begin(); it != v.end(); it++){
        (*it).printEmployee();
        
    }
}

void setGroup(vector<Employee>& v, multimap<int, Employee>& ms){
    for(vector<Employee>::iterator it=v.begin(); it != v.end(); it++){
        int depId = rand()%3 + 1;
        ms.insert(make_pair(depId, *it));  // key-value: depId && Employee
    }
}

void printEmployeeByGroup(multimap<int, Employee>& memp){
    multimap<int, Employee>::iterator pos = memp.find(Planning);
    int count = memp.count(Planning);
    int index = 0;
    cout << "**************** " << count << " Planning: ****************"<< endl;
    for(; pos != memp.end() && index<count; pos++, index++){
        cout << "Name: " << pos->second.Name << "\t Salary: " << pos->second.Salary << endl;
    }

    pos = memp.find(Publicity);
    count = memp.count(Publicity);
    cout << "**************** " << count << " Publicity: ****************"<< endl;
    index = 0;
    for(;pos != memp.end() && index<count; pos++, index++){
        cout << "Name: " << pos->second.Name << "\t Salary: " << pos->second.Salary << endl;
    }
    
    pos = memp.find(RD);
    count = memp.count(RD);
    cout << "**************** " << count << " RD: ***********************"<< endl;
    index = 0;
    for(; pos != memp.end() && index<count; pos++, index++){
        cout << "Name: " << pos->second.Name << "\t Salary: " << pos->second.Salary << endl;
    }
}


int main(){

    srand((unsigned int)time(NULL));

    vector<Employee>emp;
    // 1. create Employee
    creatEmployee(emp);
    // printVectorEmployee(emp);

    // 2. grouping
    multimap<int, Employee>memp;
    setGroup(emp, memp);

    // 3. printEmployeeByGroup
    printEmployeeByGroup(memp);

    return 0;
}