#include<iostream>
#include<fstream>  // 头文件包含
#include<string>
using namespace std;

/**
 * @brief 写入内容到文件
 * 学会如何写内容到一个文件中
 */
void write(){
    // 创建流对象
    ofstream ofs;

    // 指定路径和打开方式
    ofs.open("helloworld.txt", ios::out);

    // 写内容
    ofs << "hello world !" << endl;
    ofs << "MOE new growth diary ..." << endl;
    
    // 关闭文件
    ofs.close();
}

/**
 * @brief 读写文件内容：三种方法
 * 学会如何读到一个文件中内容
 */
void read(){
    // 1. 创建流对象
    ifstream ifs;
    // 2. 指定打开方式
    ifs.open("helloworld.txt", ios::in);
    // 3. 判断是否正常打开
    if ( ! ifs.is_open()){
        cout << "read file failed !" << endl;
        return;
    }

    // 4. 读数据
    // 方式1
    // char buf[1024];
    // while ( ifs >> buf ){
    //     cout << buf << endl;
    // }

    // 方式2
    // char buf[1024];
    // 按行读取
    // while ( ifs.getline(buf, sizeof(buf)) ){
    //     cout << buf << endl;
    // }

    // 方式3
    string line;
    while (getline(ifs, line)) {
        cout << line << endl;
    }

    ifs.close();
}


int main(){
    // write();
    read();
}