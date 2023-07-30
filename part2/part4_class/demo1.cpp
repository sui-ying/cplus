#include<iostream>

using namespace std;


// //  结构体： 默认权限为公共权限
// struct Stuedent
// {
//     string name;
//     int id;
// };

// 设计一个类: 默认权限为私有
class Stuedent
{
// 公共属性
public:
    // 属性
    string name;
    int id;
    
    // 行为: 也是函数
    void ShowInfo(){
        cout << "name: " << name << " id: " << id << endl;
    }

    void SetName(string I_name){
        name = I_name;
    }

    void SetId(int I_id){
        id = I_id;
    }

    void SetAge(int I_age){
        if (age < 0 || age > 150){
            return ;
        }
        age = I_age;
    }

    int GetAge(){
        return age;
    }

    void SetLover(string *arr){
        for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
            lover[i] = arr[i];
        }
    }

// 保护属性
protected:

// 私有属性
private:
    int age;
    string lover[2];

};


int main(){
    Stuedent s1;  // 实例化类为对象
    s1.name = "xyc";
    s1.id = 001;

    s1.ShowInfo();
    string lovers[] = {"momo", "nono"}; 
    s1.SetLover(lovers);
}