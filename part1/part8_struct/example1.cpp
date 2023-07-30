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
    // int id;
    string name;
    // int age;
    struct Student sArray[5];
};


void AllocatSpace(struct Teacher tArray[], int len){
    // 
    string nameSeed = "ABCDE";
    for (int i=0; i<len; i++){
        tArray[i].name = "Teancher_";
        tArray[i].name += nameSeed[i];

        for (int j=0; j<5; j++){
            tArray[i].sArray[j].name = "student_";
            tArray[i].sArray[j].name += nameSeed[j];

            int random = rand() % 61 + 40; // 40~100
            tArray[i].sArray[j].score = random;
        }
    }
}

void PrintInfo(Teacher tArray[], int len){
    for (int i=0; i<len; i++){
        cout << "Teacher name: " << tArray[i].name << endl;
        for (int j=0; j<5; j++){
            cout << "Student name: " << tArray[i].sArray[j].name << "\t"
                 << "Score: " << tArray[i].sArray[j].score << endl;
        }
    }
}

int main(){
    // 创建老师数组
    struct Teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    
    // 调用函数赋值
    AllocatSpace(tArray, len);

    // 调用函数打印
    PrintInfo(tArray, len);
}