#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/**
 * @brief stack Constructor function
 * 
 */
void stackConstructor(){
    stack<int> s1;  // 默认构造 无参构造

    // 不具有遍历行为
    // for (int i=0; i<10; i++){
    //     s1.push_back(i);
    // }

    // 入栈 push
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    // 是否为空
    while (!s1.empty()){
        cout << "s1.size(): " << s1.size() << " 栈顶元素: " << s1.top() << endl;
        s1.pop();  // 出栈
    }

}


int main(){
    stackConstructor();
}