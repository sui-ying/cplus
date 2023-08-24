#include<iostream>
#include<fstream>

#include "../include/EMS.h"
#include "../include/worker.h"
#include "../include/employee.h"
#include "../include/manager.h"
#include "../include/boss.h"

using namespace std;

#define filepath "employee_info.txt"

/**
 * @brief Construct a new Work Manager:: Work Manager object
 * 
 */
WorkManager::WorkManager(){

    // 1. filepath not exit
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if (!ifs.is_open()){
        cout << filepath << " is not exist." << endl;
        // init 
        this->EmpNum = 0;
        this->EmpArray = NULL;
        this->file_is_empty = true;
        ifs.close();
        return;
    }

    // 2. file is empty
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << filepath << " is empty" << endl;
        this->EmpNum = 0;
        this->EmpArray = NULL;
        this->file_is_empty = true;
        ifs.close();
        return;
    }

    // 3. file exist, and update this->EmpNum, this->EmpArray, this->file_is_empty
    int num = this->Get_EmpNum();
    cout << "number of employeee: " << num << endl;
    this->EmpNum = num;
    this->EmpArray = new Worker*[this->EmpNum];
    this->init_Emp();

    for (int i=0; i<this->EmpNum; i++){
        cout << "Id: " << this->EmpArray[i]->Id 
             << "\tName: " << this->EmpArray[i]->Name
             << "\tdepartId: " << this->EmpArray[i]->DepartId << endl;
    }

    
}

/**
 * @brief member function implementation: show menu
 * 
 */
void WorkManager::ShowMenu(){
    cout << "********************************************************************" << endl;
    cout << "************* Welcome to Employee Management System ! **************" << endl;
    cout << "***************** 0. Exit Employee Management System. **************" << endl;
    cout << "******************** 1. Add Employee Info.  ************************" << endl;
    cout << "******************** 2. Show Employee Info. ************************" << endl;
    cout << "*************** 3. Delete Employee Management System. **************" << endl;
    cout << "*************** 4. Modify Employee Management System. **************" << endl;
    cout << "*************** 5. Search Employee Management System. **************" << endl;
    cout << "*************** 6. Sort Employee Management System. ****************" << endl;
    cout << "*************** 7. Exit Employee Management System. ****************" << endl;
}


/**
 * @brief ExitSystem
 * 
 */
void WorkManager::ExitSystem(){
    cout << "welcome to use the system next time !" << endl;
}

/**
 * @brief Add employee
 * 
 */
void WorkManager::Add_Emp(){
    cout << "please input number of add employee: ";
    int addNum = 0;
    cout << endl;

    cin >> addNum;
    if (addNum > 0){
        int newSize = this->EmpNum + addNum;
        Worker ** newSpace = new Worker *[newSize];
        if (this->EmpArray != NULL){
            for (int i=0; i<this->EmpNum; i++){
                newSpace[i] = this->EmpArray[i];
            }
        }

        cout << "********************************************************************" << endl;
        cout << "Add employee exmple: " << endl;
        cout << "Id: 1" << endl;
        cout << "Name: xxx" << endl;
        cout << "Department: 1 -> Boss, 2 -> Manager, 3 -> Employee" << endl;

        for (int i=0; i<addNum; i++){
            int id;
            string name;
            int dSelect;
            cout << "********************************************************************" << endl;
            cout << "Please enter the employee number: " << i+1 << endl;
            cout << "Id: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Department: ";
            cin >> dSelect;

            Worker *Worker = NULL;
            switch (dSelect)
            {
            case 1:
                Worker = new Boss(id, name, 1);
                break;
            case 2:
                Worker = new Manager(id, name, 2);
                break;
            case 3:
                Worker = new Employee(id, name, 3);
                break;    
            default:
                break;
            }

            // 创建职工职责 保存到数组中
            newSpace[this->EmpNum + i] = Worker;

        }

        delete[] this->EmpArray;
        this->EmpArray = newSpace;
        this->EmpNum = newSize;

        cout << "********************************************************************" << endl;
        cout << "susseccfully add " << newSize << " employee" << endl;
        
        this->Save_Emp();
    }
    else{
        cout << "input error" << endl;
    }
}

/**
 * @brief get number of employee
 * 
 * @return int: num
 */
int WorkManager::Get_EmpNum(){
    ifstream ifs;
    ifs.open(filepath, ios::in);
    int Id;
    string Name;
    int departId;

    int num = 0;
    while(ifs >> Id && ifs >> Name && ifs >> departId){
        num++;
    }
    // string line;
    // while (getline(ifs, line)) {
    //     if (!line.empty()) {
    //         num++;
    //     }
    // }
    return num;
}

/**
 * @brief save employee info to txt
 * 
 */
void WorkManager::Save_Emp(){
    if (this->EmpNum > 0){
        ofstream ofs;
        ofs.open("employee_info.txt", ios::out);
        for (int i=0; i<this->EmpNum; i++){
            ofs << this->EmpArray[i]->Id << "\t "
                << this->EmpArray[i]->Name << "\t " 
                << this->EmpArray[i]->DepartId << endl;  
        }
        cout << "write " << this->EmpNum << " employee susseccfully!" << endl;
    }
    
}

/**
 * @brief 
 * 
 */
void WorkManager::init_Emp(){
    ifstream ifs;
    ifs.open(filepath, ios::in);
    int Id;
    string Name;
    int departId;

    int index = 0;
    while(ifs >> Id && ifs >> Name && ifs >> departId){
        Worker *Worker = NULL;
        if (departId == 1){
            Worker = new Boss(Id, Name, departId);
        }
        else if (departId == 2){
            Worker = new Manager(Id, Name, departId);
        }
        else{
            Worker = new Employee(Id, Name, departId);
        }
        this->EmpArray[index] = Worker;
        index++;
    }
    ifs.close();
}

void WorkManager::Show_Emp(){
    // file is exist or empty
    if (this->file_is_empty){
        cout << "file is exist or empty" << endl;
    }
    else{
        for (int i=0; i<EmpNum; i++){
            this->EmpArray[i]->ShowInfo();
        }
    }
}

void WorkManager::Delete_Emp(){
    cout << "please input deleted employee id: ";
    int id;
    cin >> id;
    int index = this->IsExist(id);
    if ( index != -1){
        for (int i=index; i<this->EmpNum; i++){
            this->EmpArray[i] = this->EmpArray[i+1];
        }
        this->EmpNum--;
        
        this->Save_Emp(); 
        cout << "delete employee id succesfully !" << endl;
    }


}

int WorkManager::IsExist(int id){
    int index = -1;
    for (int i=0; i<this->EmpNum; i++){
        if (this->EmpArray[i]->Id == id){
            index = i;
            break;
        }
    }
    return index;
}


void WorkManager::Modify_Emp(){
    cout << "please input modifying Employee id: ";
    int id;
    cin >> id;

    int index = this->IsExist(id);
    if (index != 1){
        delete this->EmpArray[index];
        int new_id;
        string new_name;
        int new_departId;
        cout << "Modifying Employee: " << endl;
        cout << "Id: ";
        cin >> new_id;
        cout << "Name: ";
        cin >> new_name;
        cout << "departId: ";
        cin >> new_departId;
        switch (new_departId)
        {
            case 1:
                this->EmpArray[index] = new Boss(new_id, new_name, new_departId);
                break;
            case 2:
                this->EmpArray[index] = new Manager(new_id, new_name, new_departId);
                break;
            case 3:
                this->EmpArray[index] = new Employee(new_id, new_name, new_departId);
                break;
            default:
                break;
        }
        cout << "Modify Succefully !" << endl;
        this->Save_Emp();
    }
    else{
        cout << "id of employee not exist" << endl;
    }

}

void WorkManager::Search_Emp(){
    int flag; // 1 for id, 2 for name
    cout << "please select search mothod: 1->id, 2->name" << endl;
    cin >> flag;
    if (flag == 1){
        int id;
        cout << "Please input search id of employee " << endl;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1){
            cout << "The employee whose id is " << id << " exist" << endl;
            this->EmpArray[index]->ShowInfo();
        }
        else{
            cout << "The employee whose id is " << id << " not exist" << endl;
        }
    }
    else if (flag == 2){
        string s_name;
        cout << "Please input search name of employee " << endl;
        cin >> s_name;
        for (int i=0; i<this->EmpNum; i++){
            if (this->EmpArray[i]->Name == s_name){
                cout << "The employee whose name is " << s_name << " exist" << endl;
                this->EmpArray[i]->ShowInfo();
            }
        }
    }
}

void WorkManager::Sort_Emp(){
    cout << "Sort method: 1->up sort, 2->down sort" << endl;
    int flag;
    cout << "Plese input Sort method: " << endl;
    cin >> flag;

    for (int i=0; i<this->EmpNum; i++){
        int max_index = i;
        for (int j=i+1; j<this->EmpNum; j++){
            if (this->EmpArray[max_index]->Id > this->EmpArray[j]->Id){
                max_index = j;
            }
        }
    }

    this->Show_Emp();
    this->Save_Emp();
}

void WorkManager::Clear_Emp(){
    cout << "Whether clear Emp: 1->yes" << endl;
    int select;
    cout << "please input num: 1-> clear";
    cin >> select;

    if (select == 1){
        ofstream ofs(filepath, ios::trunc); // 删除文件后创建
        ofs.close();

        if (this->EmpArray != NULL){
            for (int i=0; i<this->EmpNum; i++){
                delete this->EmpArray[i];  // 删除堆区的数据
                this->EmpArray[i] = NULL;
            }
        }

        delete[] this->EmpArray;
        this->EmpArray = NULL;
        this->EmpNum=0;
        this->file_is_empty = false;
    }
}

WorkManager::~WorkManager(){ 
    // free heap data 
    if (this->EmpArray != NULL){
        delete[] this->EmpArray;
        this->EmpArray = NULL;
    } 
}


int main(){

    WorkManager wm;  // 类实例化为对象
    wm.ShowMenu();  // 调用成员函数

    cout << "Please input number 0~7" << endl;
    int select;
    cin >> select;

    switch (select)
    {
    case 0:
        wm.ExitSystem();
        break;
    case 1:
        wm.Add_Emp();
        break;
    case 2:
        wm.Show_Emp();
        break;
    case 3:
        wm.Delete_Emp();
        break;
    case 4:
        wm.Modify_Emp();
        break;
    case 5:
        wm.Search_Emp();
        break;
    case 6:
        wm.Sort_Emp();
        break;
    case 7:
        wm.Clear_Emp();
        break;
    default:
        break;
    }

}