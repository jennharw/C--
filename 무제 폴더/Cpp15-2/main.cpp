#include <iostream>

using namespace std;

//#include "army.h"
class Army
{
public:
    virtual void Run() {
        std::cout << std::endl;
        std::cout << _Speed << "의 속도로 ";
    }

    virtual void Attack() {
        std::cout << std::endl;
        std::cout << "[공격력 - " << _Attack << "으로 ";
    }

protected:
    int _HP;
    int _MP;
    int _Speed;
    int _Attack;
};

//#include "Units.h"
class Healer : public Army
{
public:
    Healer(){
        _HP = 50;
        _MP = 100;
        _Speed = 200;
        _Attack = 10;
    }

    void Run() {
        Army::Run();

        std::cout << "Healer 날아갑니다. " << _Speed;
    }

    void Attack() {
        Army::Attack();

        std::cout << "Healer 마볍 공격!!! ";
    }
};

class Giant : public Army
{
public:
    Giant() {
        _HP = 200;
        _MP = 0;
        _Speed = 10;
        _Attack = 200;
    }

    void Run() override {
        Army::Run();

        std::cout << "Giant 달려갑니다. " << _Speed;
    }

    void Attack() override {
        Army::Attack();

        std::cout << "Giant 공격!!! ";
    }
};

class Barbarian : public Army
{
public:
    Barbarian() {
        _HP = 100;
        _MP = 0;
        _Speed = 100;
        _Attack = 100;
    }

    void Run() override {
        Army::Run();

        std::cout << "Barbarian  달려갑니다. " << _Speed;
    }

    void Attack() override {
        Army::Attack();

        std::cout << "Barbarian [칼로] 공격!!!  ";
    }
};

void PrintAll(Army** arrArmys, int size) //void PrintAll(Army* (arrArmys)[], int size)
{
    for (int i = 0; i < 10; i++)
    {
        if (nullptr != arrArmys[i])
            arrArmys[i]->Run();
    }

    for (int i = 0; i < 10; i++)
    {
        if (nullptr != arrArmys[i])
            arrArmys[i]->Attack();
    }
}


int main()
{
    cout << "\n == 반복문과 많은 데이터를 관리 == " << endl;

    //Army* arrArmys[10]{};
    Army** arrArmys = new Army* [10];

    arrArmys[0] = new Barbarian();
    arrArmys[1] = new Giant();
    arrArmys[2] = new Healer();

    PrintAll(arrArmys, 10);

    for (int i = 0; i < 10; i++)
    {
        if (nullptr != arrArmys[i])
        {
            delete arrArmys[i];
            arrArmys[i] = nullptr;
        }
    }

    delete[] arrArmys;
    arrArmys = nullptr;

    if (nullptr == arrArmys) 
        cout << "\n\nClear delete" << endl;

    return 0;
}
 