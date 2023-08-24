#include<iostream>
#include<fstream>  // 头文件包含
#include<string>
using namespace std;


class Person
{
public:
    char Name[64];
    int Age;
};


/**
 * @brief 写入内容到文件
 * 学会如何以二进制方式写内容到一个文件中
 */
void write_byte(){
    // 创建流对象
    ofstream ofs;
     
    // 指定路径和打开方式
    ofs.open("helloworld_byte.txt", ios::out | ios::binary);

    // ofstream ofs("helloworld_byte.txt", ios::out | ios::binary); // 构造函数

    // 写内容
    Person p1 = {"Momo", 18};
    ofs.write( (const char *)&p1, sizeof(Person));  // 使用 write() 方法将 Person 对象 p1 的数据写入文件
    string test = "hello";
    ofs.write( (const char *)&test, sizeof(test));  // 使用 write() 方法将字符串对象 test 的数据写入文件

    // 关闭文件
    ofs.close();
}

/**
 * @brief 读写文件内容：三种方法
 * 学会如何读到一个文件中内容
 */
void read_byte(){
    // 1. 创建流对象
    ifstream ifs;

    // 2. 指定打开方式
    ifs.open("helloworld_byte.txt", ios::in | ios::binary);

    // 3. 判断是否正常打开
    if ( ! ifs.is_open()){
        cout << "read file failed !" << endl;
        return;
    }
   
    Person p2;
    ifs.read((char *)&p2, sizeof(Person));  // read() 方法从文件中读取 Person 对象的数据，并将其赋值给 p2
    cout << "Name: " << p2.Name << "\t Age: " << p2.Age << endl;

    string test;
    ifs.read((char *)&test, sizeof(test));  // 使用 read() 方法从文件中读取字符串数据，并将其赋值给 test
    cout << test << endl;

    ifs.close();
}


int main(){
    write_byte();
    read_byte();
}