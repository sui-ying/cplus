#include<iostream>
using namespace std;


struct Point
{
    /* data */
    double x;
    double y;
};


class Circle{

public:

    void SetRadius(double r){
        R = r;
    }

    void SetPointCenter(Point p0){
        center.x = p0.x;
        center.y = p0.y;
    }

    int CalculateDistance(Point p){
        double dis = (p.x - center.x)*(p.x - center.x) + (p.y - center.y)*(p.y - center.y);
        if (dis < R*R)
        {
            return -1;
        }
        else if (dis == R*R)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

protected:

private:
    Point center;
    double R;

};

int main(){

    Circle c1;
    Point p0 = {0, 0};
    c1.SetPointCenter(p0);
    c1.SetRadius(10);

    Point p1 = {5, 6};
    int ret = c1.CalculateDistance(p1);
    cout << "ret: " << ret << endl;
    if (ret == -1){
        cout << "In circle c1" << endl;
    }
    else if (ret == 0)
    {
        cout << "On circle c1" << endl;
    }
    else
    {
        cout << "out of circle c1" << endl;
    }
    
}