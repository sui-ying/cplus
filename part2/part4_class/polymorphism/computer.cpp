#include<iostream>
using namespace std;


/**
 * @brief 抽象类；子类继承时需要重写父类的虚函数
 * 
 */
class CPU
{
public:
    virtual void Calculator() = 0;
};

/**
 * @brief 抽象类；子类继承时需要重写父类的虚函数
 * 
 */
class GraphicsCard
{
public:
    virtual void Display() = 0;
};

/**
 * @brief 抽象类；子类继承时需要重写父类的虚函数
 * 
 */
class Memory
{
public:
    virtual void Storage() = 0;
};


class Computer
{
public:
    Computer(CPU *cpu, GraphicsCard *gc, Memory *mem)
    {
        m_cpu = cpu;
        m_gc = gc;
        m_mem = mem;
    }

    void work(){
        m_cpu->Calculator();

        m_gc->Display();

        m_mem->Storage();
    }

    ~Computer(){
        if (m_cpu != NULL){
            cout << "free m_cpu." << endl;
            delete m_cpu;   // 手动释放
        }

        if (m_gc != NULL){
            cout << "free m_gc." << endl;
            delete m_gc;
        }

        if (m_mem != NULL){
            cout << "free m_mem." << endl;
            delete m_mem;
        }
    }

private:
    CPU * m_cpu;  // 堆区创建的数据，需要手动释放
    GraphicsCard * m_gc;
    Memory * m_mem;
};

// inherit
class InterCPU: public CPU
{
public:
    void Calculator(){
        cout << "Inter CPU start calculating !" << endl;
    }
};

class InterGraphicsCard: public GraphicsCard
{
public:
    void Display(){
        cout << "Inter GraphicsCard start displaying !" << endl;
    }
};

class InterMemory: public Memory
{
public:
    void Storage(){
        cout << "Inter Memory start storaging !" << endl;
    }
};

// inherit
class LenovoCPU: public CPU
{
public:
    void Calculator(){
        cout << "Lenovo CPU start calculating !" << endl;
    }
};

class LenovoGraphicsCard: public GraphicsCard
{
public:
    void Display(){
        cout << "Lenovo GraphicsCard start displaying !" << endl;
    }
};

class LenovoMemory: public Memory
{
public:
    void Storage(){
        cout << "Lenovo Memory start storaging !" << endl;
    }
};


void test01(){
    CPU * interCPU = new InterCPU;
    GraphicsCard * interCard = new InterGraphicsCard;
    Memory *interMemory = new InterMemory;

    Computer *computer1 = new Computer(interCPU, interCard, interMemory);
    computer1->work();
    delete computer1;

    cout << "********************* Assemble computer2 ... ********************* " << endl;
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoGraphicsCard, new LenovoMemory);
    computer2->work();
    delete computer2;
}

int main(){
    test01();
}