#include<iostream>
using namespace std;


void pairTest(){

    // 第一种方式
    pair<string, int>p("momo", 18);
    cout << "Name: " << p.first << "\t Age: " << p.second << endl;

    // 第二种方式
    pair<string, int>p2 = make_pair("momo", 18);
    cout << "Name: " << p2.first << "\t Age: " << p2.second << endl;
}

int main(){
    pairTest();
}
