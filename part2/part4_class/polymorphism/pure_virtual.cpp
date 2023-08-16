#include<iostream>
using namespace std;


/**
 * @brief 用多态方法实现计算器
 * 基类
 * 当虚函数为纯虚函数时，此时类也成为抽象类:
 */
class CalculatorBase
{
public:
    int A, B;
    CalculatorBase(int a=0, int b=0):A(a), B(b){
        cout << "call CalculatorBase constractor !" << endl;
    };
    // 虚函数: vitual 返回值类型 函数名 (参数列表) = 0；
    virtual double GetResult() = 0;
};

/**
 * @brief 实现加法: 继承，重写虚函数
 *  
 */
class AddCalculator: public CalculatorBase
{
public:
    // 构造函数，列表解析
    AddCalculator(int a=0, int b=0): CalculatorBase(a, b){
        cout << "call AddCalculator constractor !" << endl;
    };
    // 重写虚函数： 函数名 返回类型 参数列表完全一致
    double GetResult(){
        return A + B;
    }
}; 

class SubCalculator: public CalculatorBase
{
public:
    SubCalculator(int a=0, int b=0): CalculatorBase(a, b){
        cout << "call SubCalculator constractor !" << endl;
    };
   double GetResult(){
        return A - B;
    }
}; 

class MulCalculator: public CalculatorBase
{
public:
    MulCalculator(int a=0, int b=0): CalculatorBase(a, b){
        cout << "call SubCalculator constractor !" << endl;
    };
   double GetResult(){
        return A * B;
    }
};

void test02(){
    // 多态使用条件: 父类指针或者引用指向子类对象
    CalculatorBase *calcu = new AddCalculator(2, 3);  // 堆区数据手动创建，
    cout << calcu->A << " + " << calcu->B << " =  " << calcu->GetResult() << endl;

    delete calcu;  // 堆区创建的数据用完记得销毁
    calcu = new SubCalculator(2, 3);  // 列表初始化
    cout << calcu->A << " + " << calcu->B << " =  " << calcu->GetResult() << endl;

    delete calcu;  // 堆区创建的数据用完记得销毁
    calcu = new MulCalculator(2, 3);  // 列表初始化
    cout << calcu->A << " + " << calcu->B << " =  " << calcu->GetResult() << endl;
    delete calcu;  // 堆区创建的数据用完记得销毁
}


int main(){
    // test01();
    test02();
}