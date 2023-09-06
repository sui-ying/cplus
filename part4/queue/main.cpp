#include<iostream>
#include<queue>
using namespace std;

/**
 * @brief queue Constructor function
 * 
 */
void queueConstructor(){
    queue<int> q1;  // 默认构造 无参构造


    // 入队 push
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    // 是否为空
    while (!q1.empty()){
        cout << "q1.front(): " << q1.front() << " q1.back() " << q1.back() << endl;
        q1.pop();  // 出队
    }

}

int main(){
    queueConstructor();
}