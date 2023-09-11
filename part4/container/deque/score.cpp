#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

#include<ctime>

/**
 * @brief 
 * 
 */
class Person
{
public:
    string Name;
    int Score;
    Person(string name, int score): Name(name), Score(score){}

    void printPerson(){
        cout << "Name: " << Name << " Score: " << Score << endl;
    }
};

void createPersonVector(vector<Person>&v){
    string nameSeed = "ABCDE";
    for (int i=0; i<5; i++){
        string name = "player_";
        name += nameSeed[i];  // player_A
        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}


void printPersonVector(vector<Person>&v){
    for (vector<Person>::iterator it=v.begin(); it != v.end(); it++){
        (*it).printPerson();
    }
}


void scoringPerson(vector<Person>&v){
    for (vector<Person>::iterator it=v.begin(); it != v.end(); it++){
        // 将打分放到容器deque
        deque<int>d;
        for (int i=0; i<10; i++){
            int score = rand() % 41 + 60;  // 60 ~ 100
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();   // 去掉最高分
        d.pop_front();  // 去掉最低分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            sum += *dit;
        }
        int ave_score = sum / d.size();  // 平均分
        it->Score = ave_score;

        // cout << it->Name << ": ";
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
        //     cout << *dit << " ";
        // }
        // cout << endl;
    }
}


void displayScore(vector<Person>&v){
    for (vector<Person>::iterator it=v.begin(); it != v.end(); it++){
        (*it).printPerson();
    }
}

int main(){

    // 1. create 5 person
    vector<Person> v;
    createPersonVector(v);
    printPersonVector(v);

    // 2. scoring for 5 person
    srand((unsigned int)time(NULL));  // 随机数种子: 每次程序运行时，种子都会不同，从而产生不同的随机数序列。
    scoringPerson(v);
    
    // 3. display final score
    printPersonVector(v);

}