#include<iostream>
#include<string>
#include <limits>

#define MAX 1000
using namespace std;

/**
 * @brief 显示菜单
 */
void ShowMenu(){
    cout << "*************************************"<< endl;
    cout << "***** 1. add    contact person *****" << endl;
    cout << "***** 2. show   contact person *****" << endl;
    cout << "***** 3. delect contact person *****" << endl;
    cout << "***** 4. search contact person *****" << endl;
    cout << "***** 5. modify contact person *****" << endl;
    cout << "***** 6. clear  contact person *****" << endl;
    cout << "***** 0.      exit system      *****" << endl;
    cout << "************************************" << endl;
}

// 创建联系人结构体
struct ContactPerson{
    string name;
    int age;
    int sex;
    string phone;
    string address;
};

// address_book struct
struct Adreessbooks{
    struct ContactPerson personarray[MAX];
    int m_size;
};

void pauseProgram() {
    cout << "按下回车键继续...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Add contact person
 * 
 */
void AddPerson(Adreessbooks *abs){
    if (abs->m_size == MAX){
        cout << "Adreessbooks is fulled !" << endl;
        return;
    }
    else
    {
        string name;
        cout << "Input name: ";
        cin >> name;
        cout << endl;
        abs->personarray[abs->m_size].name = name;

        cout << "1 -- Man; 2 -- Women" << endl;
        cout << "Inpu sex: ";
        int sex;
        while (true){
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personarray[abs->m_size].sex = sex;
                break;
            }
            cout << "input error, please input 1 or 2" << endl;
        }

        int age;
        cout << "Input age: ";
        cin >> age;
        abs->personarray[abs->m_size].age = age;

        string phone;
        cout << "Input phone: ";
        cin >> phone;
        abs->personarray[abs->m_size].phone = phone;
        
        string adress;
        cout << "Input Adrees: ";
        cin >> adress;
        abs->personarray[abs->m_size].address = adress;
        
        abs->m_size++;
        cout << "AddPerson Successfully" << endl;

        pauseProgram();
        system("clear");
    }
    
}

/**
 * @brief print Adreessbooks
 * @param abs 
 */
void ShowPerson(Adreessbooks *abs){
    if (abs->m_size == 0){
        cout << "Adreessbooks is empty !" << endl;
        return;
    }
    else
    {
        for (int i =0; i<abs->m_size; i++){
            cout << "name:  " << abs->personarray[i].name << "\t"
                 << "age:   " << abs->personarray[i].age << "\t"
                 << "sex:   " << (abs->personarray[i].sex == 1 ? "Man" : "Women") << "\t"
                 << "phone: " << abs->personarray[i].phone << "\t"
                 << "adress:" << abs->personarray[i].address << endl;
        }

        cout << "print Adreessbooks Successfully" << endl;
        pauseProgram();
        system("clear");
    }
    
}



/**
 * @brief whether i_name exist
 * @param abs 
 * @param i_name 
 * return bool: 1 for exist, 0 for not exist
 */
int Isexit_person(Adreessbooks *abs, string i_name){
    for (int i =0; i<abs->m_size; i++){
        if (abs->personarray[i].name == i_name){
            return i;
        }
    }
    return 0;
}


/**
 * @brief delete the person of Adreessbooks
 * @param abs 
 */
void DeletePerson(Adreessbooks *abs, int ret){
    // 删除数组中的一个元素: 前移
    for (int i=ret; i<abs->m_size; i++){
        abs->personarray[i] = abs->personarray[i+1];
    }
    abs->m_size--;
    cout << "Delete person Successfully" << endl;
    pauseProgram();
    system("clear");
}

void FindPerson(Adreessbooks *abs, int ret){
    cout << "name:  " << abs->personarray[ret].name << "\t"
        << "age:   " << abs->personarray[ret].age << "\t"
        << "sex:   " << (abs->personarray[ret].sex == 1 ? "Man" : "Women") << "\t"
        << "phone: " << abs->personarray[ret].phone << "\t"
        << "adress:" << abs->personarray[ret].address << endl;
}


void ModifyPerson(Adreessbooks *abs, int ret){
     
}

int main(){

    ShowMenu();
    Adreessbooks abs;
    int select;
    while (true)
    {
        cin >> select;
        switch (select)
        {
            case 1:
                AddPerson(&abs); 
                break;
            case 2:
                ShowPerson(&abs); 
                break;
            case 3:
            {
                string i_name;
                cout << "Input find name: ";
                cin >> i_name;
                int ret = Isexit_person(&abs, i_name);
                if (ret){
                    DeletePerson(&abs, ret);
                }
                else{
                   cout << i_name << " not exist in AdressBooks" << endl; 
                }
                break;
            }
            case 4: 
            {
                string s_name;
                cout << "Input search name: ";
                cin >> s_name;
                int ret = Isexit_person(&abs, s_name);
                if (ret){
                    FindPerson(&abs, ret); 
                }
                else{
                   cout << s_name << " not exist in AdressBooks" << endl; 
                }
                break;
            }
            case 5: 
                break;
            case 6: 
                break;
            case 0:
                cout << "exit system" << endl;
                return 0;
                break;
            default:
                
                break;
        }
    }
    
    
}