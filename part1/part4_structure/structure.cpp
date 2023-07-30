#include<iostream>
#include<string>
using namespace std;


// 程序结构
int main(){

    // 选择结构 if
    int score;
    cout << "Input a num: ";
    cin >> score;

    if (score > 600){
        cout << "1" << endl;
    }
    else if (score > 500){
        cout << "2" << endl;
    }
    else{
        cout << "3" << endl;
    }


    // 选择结构 switch
    // 判断时条件只能是整型或者字符型
    int tire;
    cout << "Input a num: ";
    cin >> tire;
    switch (tire)
    {
    case 1:
        cout << "score > 600" << endl; 
        break;
    case 2:
        cout << "score > 500" << endl; 
        break;
    default:
        cout << "score <= 500" << endl; 
        break;
    }


    /*
        循环结构while:     
    */
    int num = 0;
    while (num < 10){
        cout << "num: " << num << endl;
        num += 1;
    }

    /*
        循环结构do ... while:   
        先执行,在判断  
    */
    do{
        cout << "num: " << num << endl;
        num += 1;
    }while (num < 10);


    /*
        循环结构for   
    */
    for (int nm=100; nm<=999; nm++){
        int a = nm % 10;
        int b = (nm / 10) % 10;
        int c = (nm / 100) % 10;
        if (a*a*a + b*b*b + c*c*c == nm){
            cout << "nm: " << nm << endl;
        }
    }

    /*
        嵌套循环结构for   
    */
    // 打印9*9
    for (int i=1; i<10; i++){
        for (int j=1; j<10; j++){
            if (j <= i){  
                cout << i << "*" << j << "=" << i*j << "\t";
            }
        }
        cout << endl;
    }

    /*
        循环结构中，跳转语句
            break 跳出当前循环
            continue 跳过本次循环   
    */

}