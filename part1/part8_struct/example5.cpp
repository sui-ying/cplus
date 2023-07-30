#include<iostream>
#include<string>

using namespace std;


struct Charactor
{
    /* data */
    string name;
    int age;
    string sex;
};

void BubbleSort(struct Charactor tArray[], int len){
    for (int i=0; i<len-1; i++){
        for (int j=0; j<len-1-i; j++){
            if (tArray[j].age > tArray[j+1].age){
                struct Charactor tmp = tArray[j];
                tArray[j] = tArray[j+1];
                tArray[j+1] = tmp;
            }
        }
    }
}

void PrintInfo(struct Charactor tArray[], int len){
    for (int i=0; i<len; i++){
        cout << tArray[i].name << "\t" 
             << tArray[i].age << "\t" 
             << tArray[i].sex << endl;
    }
}


int main(){
    // 结构体数组
    struct Charactor arr[5] = {
        {"AA", 23, "M"},
        {"BB", 22, "M"},
        {"CC", 26, "M"},
        {"DD", 29, "W"},
        {"EE", 20, "W"},
    };
    int len = sizeof(arr) /sizeof(arr[0]);

    BubbleSort(arr, len);
    PrintInfo(arr, len);

}