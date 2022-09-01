//대입 연산자 오보로딩, 복사 생성자



#include <iostream>
//#include "BadPerson.h"
#include "GoodPerson.h"

using namespace std;



int func(int x)
{
    return x; // 복사
}


int main()
{
    int a = 1;
    int b = a; // 복사 생성자- 선언문 또는 함수의 파라미터인 경우
    func(a); // 복사 call by value

    a = b; //대입 연산자

    GoodPerson goodPerson0 ( 46.f, 153.f, "David Daehee Kim" );
    GoodPerson goodPerson1 = goodPerson0; //default 복사 얕은 복사 - 주소값 복사. person0 해제 시 다른 것도 해제
    //깊은 복사 - 모든 값 recursive 하게
    //다른 메모리 공간
    
    GoodPerson goodPerson2; // 얕은 복사
    goodPerson2 = goodPerson0; //=goodPerson1 //대입 연산자 오버로딩, 할당 연산자


    goodPerson0.print();
    goodPerson1.print();
    goodPerson2.print();

}