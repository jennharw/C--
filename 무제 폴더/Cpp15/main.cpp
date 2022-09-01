/*-----------------------------------------------------------------------------
 * Name: class
 * DESC: 클래스 상속, 가상함수(virtual함수 ~ override), 동적바인딩, 다형성
 * 다형성도 결국 반복문과 많은 데이터를 관리하기 위한 것..
 * static_cast는 runtime시 에러 체크X
 * dynamic_cast는 runtime시 실패하면 nullptr리턴
-----------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

class Base
{
public:
    Base();
    Base(int num);
    virtual void Print();

    int GetNum() const;

private: 
    int num;
};

Base::Base() : num(0) {}
Base::Base(int num) : num(num) {}


//virtual int Base::Print() //virutal에러..
void Base::Print()
{
    cout << "Base::Print()" << endl;
    cout << "num: " << num << endl;
}

int Base::GetNum() const
{
    return num;
}

class ChildAA : public Base
{
public:
    ChildAA(int aa);
    ChildAA(int, int);

    void Print() override; //override는 C++11 이후 추가..

private:
    int aa;
};

ChildAA::ChildAA(int aa = 0) : aa(aa), Base(0) { }
ChildAA::ChildAA(int num, int aa) : Base(num), aa(aa) {}

void ChildAA::Print() //override
{   
    //Base::Print();
    cout <<"\t ChildAA::Print()" << endl;
    cout << "\t num: " << GetNum() << endl;
    cout << "\t aa: " << aa << endl;
}


int main()
{
    Base base = Base(100);
    base.Print();

    Base* childAA = new ChildAA(1000, 1000); //동적바인딩.. 
    childAA->Print();

    cout << typeid(childAA).name() << endl;

    cout << "\n=== (typeid(childAA) == typeid(Base*)) ===" << endl;

    if (typeid(childAA) == typeid(Base*))
    {
        cout << typeid(childAA).name() << endl;
        cout << typeid(Base*).name() << endl;
    }

    ChildAA* aa = dynamic_cast<ChildAA*>(childAA); //dynamic_cast는 runtime시 실패하면 nullptr리턴
    if (nullptr != aa) aa->Print();

    cout << "\n=== (typeid(*childAA) == typeid(ChildAA)) ===" << endl;

    if (typeid(*childAA) == typeid(ChildAA))
    {
        cout << typeid(*childAA).name() << endl;
        cout << typeid(ChildAA).name() << endl;
    }

    delete childAA;

    return 0;

}

/*
───────────────────────────┼┼
            class
───────────────────────────┼┼
 - 객체의 틀
 - 클래스를 만든다(사용자 자료형)
 ==> 클래스 변수로 사용
 ==> 클래스 포인터로 사용
────────────────────────────┼┼
            상속
────────────────────────────┼┼
 - 부모 class를 상속
 받아서 부모 class의
 함수, 변수 등등사용가능
 - IS - A관계
 - Virtual, override
 - 다형성
───────────────────────────┼┼
    순수 가상 함수
────────────────────────────┼┼
- 순수 가상함수를 포함하는
클래스는 추상 클래스(Abstract Class)
- 가상함수는 객체 생성 불가!!
- override하려면 가상함수로
- 가상함수가 있다면
주의!!: 소멸자도 가상함수로
문법:
class AA {
    //virtual void Func() = NULL;
    virtual void Func() = 0;
    virtual ~AA() {}
};
────────────────────────────┼┼
 Has - A로 메니저클래스 구현
────────────────────────────┼┼
class A{};
class B{};
class C{};
class Manager
{
    A aa[100];
    B bb[100];
    C cc[100];
};
────────────────────────────┼┼
객체 복사에서 주의할 것 this point
=> 깊은 복사 & 얕은 복사
=> 복사 생성자 및 연산자 오버로딩
────────────────────────────┼┼
 //포인터 배열: int* ptr[4]; int pointer를 저장하는 배열
 //배열 포인트: int (*ptr)[4]; 배열의 포인터
 */
 