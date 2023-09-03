#include<iostream>

using namespace std;


class Shape
{
public:
    double Width;
    double Height;

    Shape(double width, double height): Width(width), Height(height){}

    virtual double getArea() = 0;  // 纯虚函数，子类必须重写基类中的纯虚函数
};

class Rectangle: public Shape
{
public:
    Rectangle(double width, double height): Shape(width, height) {}
    // 子类必须重写基类中的纯虚函数
    double getArea(){
        return Width * Height;
    }
};

class Triangle: public Shape
{
public:
    Triangle(double width, double height): Shape(width, height) {}
    double getArea(){
        return 0.5 * Width * Height;
    }
};

int main(){
    // Rectangle rect(2, 3);
    // cout << "rect Area: " << rect.getArea() << endl;

    // 多态使用条件: 父类指针或者引用指向子类对象
    Shape *shape = new Rectangle(2, 3);  // 在堆区创建子类对象，并将其赋给父类指针
    cout << "rect Area: " << shape->getArea() << endl; 
    delete shape;

    shape = new Triangle(2, 3);
    cout << "rect Area: " << shape->getArea() << endl; 
    delete shape;

    return 0;
}
