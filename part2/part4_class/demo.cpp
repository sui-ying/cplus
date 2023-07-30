#include<iostream>

using namespace std;
#define PI 3.14159


/**
 * @brief 
 * 
*/
class Circle
{
// 访问权限: 公共权限
public:
    // 属性
    double radius;

    /**
     * @brief 行为: 求圆的周长
     * @return double 
     */
    double Calculate_C()
    {
        return 2 * PI * radius;
    } 
};

int main(){

    Circle c1;  // 实例化一个类
    c1.radius=10;
    cout << "C: " << c1.Calculate_C() << endl;
}