#include<iostream>
#include<string>

using namespace std;

struct Student
{
    /* data */
    string name;
    int age;
    int score;
};

// 结构体嵌套结构体: 结构体的成员是另一个结构体. 类似dict嵌套
struct Teacher
{
    /* data */
    int id;
    string name;
    int age;
    struct Student stu;
};

/**
 * @brief 值传递: 打印struct Student的所有成员
 * @param stu 
*/
void PrintStudent(struct Student stu){
    cout << "stu.name: " << stu.name << "\t"
         << "stu.age: " << stu.age << "\t"
         << "stu.score: " << stu.score << endl;
}

/**
 * @brief 地址传递 打印struct Student的所有成员; 传入指针可以减少大量内存空间，而且不会复制新的副本出来  
 * @param p 
 */
void PrintStudent1(struct Student *p){
    cout << "name: " << p->name 
         << " age: " << p->age 
         << " score: " << p->score << endl;
}

/**
 * @brief 地址传递 打印struct Student的所有成员; 传入指针可以减少大量内存空间，而且不会复制新的副本出来  
 * @param p 
 */
void PrintStudent2(const struct Student *p){ // 加入const修饰可以防止修改
    // p->score = 100;
    cout << "name: " << p->name 
         << " age: " << p->age 
         << " score: " << p->score << endl;
}

int main(){
    
    // 初始化结构体
    // 方式1
    Student s1;
    s1.name = "aa";
    s1.age = 18;
    s1.score = 90;

    // 方式2
    Student s2 = {"bb", 19, 95};

    // 结构体数组
    struct Student stuArray[2] = {
        {"aa", 18, 90},
        {"bb", 19, 95}
    };

    // 结构体指针
    // 通过指针指向结构体变量
    Student *p = &s1;
    // 通过指针访问结构体变量中的数据: 使用操作符->
    cout << "name: " << p->name << " age: " << p->age << " score: " << p->score << endl;
    
    Teacher teacher1 = {1, "tonny", 35, s1};
    cout << "teacher1.id: " << teacher1.id << "\t"
         << "teacher1.name: " << teacher1.name << "\t"
         << "teacher1.age: " << teacher1.age << "\n"
         << "teacher1.stu.name: " << teacher1.stu.name << "\t"
         << "teacher1.stu.age: " << teacher1.stu.age << "\t"
         << "teacher1.stu.score: " << teacher1.stu.score << endl;


    // 结构体作为函数参数: 值传递、地址传递
    // 将学生s1传入到一个参数中, 打印学生的所有信息
    PrintStudent(s1);
    PrintStudent1(&s1);


    // 结构体中const使用场景

}