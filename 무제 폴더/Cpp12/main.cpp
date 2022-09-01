#include<iostream>

using namespace std;

struct MyAA 
{
   int num1;
   int num2;
   float fNum;
};

void Print(MyAA);
void PrintArray(MyAA[]);
void PrintRef(MyAA*);
int main()
{
    cout << "struct 기초 & typedef" << endl;

    MyAA aa;
    //MyAA aa = {10, 20, 0.01f}; //초기화 방법..
    aa.num1 = 10;
    aa.num1 = 10;
    aa.num2 = 20;
    aa.fNum = 0.01f;

    cout << "&aa: " << &aa << "  sizeof(aa): " << sizeof(aa) << endl << endl;
    cout << aa.num1 << " &(aa.num1): " << &(aa.num1) << endl;
    cout << aa.num2 << " &(aa.num2): " << &(aa.num2) << endl;
    cout << aa.fNum << " &(aa.fNum): " << &(aa.fNum) << endl;

    //return 0;

    cout << "struct & 함수 & 포인터 & 배열" << endl;

    MyAA arrayAA[2] = { {1, 1, 0.01f}, {2, 2, 0.02f} };  //MyAA arrayAA[2] = { 1, 1, 0.01f, 2, 2, 0.02f };

    cout << arrayAA[0].num1 << " " << arrayAA[0].num2 << " " << arrayAA[0].fNum << endl;

    MyAA temp = arrayAA[1]; // 복사
    cout << temp.num1 << " " << temp.num2 << " " << temp.fNum << endl;

    Print(arrayAA[0]); //MyAA _arrayAA = arrayAA[0];
    cout << "After " << arrayAA[0].num1 << " " << arrayAA[0].num2 << " " << arrayAA[0].fNum << endl;

    PrintArray(arrayAA);
    cout << "After " << arrayAA[0].num1 << " " << arrayAA[0].num2 << " " << arrayAA[0].fNum << endl;

    PrintRef(arrayAA);  //PrintRef(&arrayAA[0]); 배열의 이름이 곧 주소
    cout << "After " << arrayAA[0].num1 << " " << arrayAA[0].num2 << " " << arrayAA[0].fNum << endl;

}

//Call By Value
void Print(MyAA _arrayAA)
{
    cout << "\t Print(MyAA _arrayAA) sizeof(_arrayAA): " << sizeof(_arrayAA) << endl;
    _arrayAA.num1 = 100;
}

//Call By Refrence
void PrintArray(MyAA _arrayAA[]) //MyAA _arrayAA[2]
{
    cout << "\t PrintArray(MyAA _arrayAA[]) sizeof(_arrayAA): " << sizeof(_arrayAA) << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << _arrayAA[i].num1 << " " << _arrayAA[i].num2 << " " << _arrayAA[i].fNum << endl;
    }

    _arrayAA[0].num1 = 100;
}

//Call By Refrence
void PrintRef(MyAA* _refAA)
{
    cout << "\t  PrintRef(MyAA* _refAA) sizeof(_refAA): " << sizeof(_refAA) << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << (*(_refAA + i)).num1 << " " <<
            (_refAA + i)->num2 << " " <<
            _refAA[i].fNum << endl;
    }

    (*(_refAA + 0)).num1 = 100000000; //_refAA[0].num1 = 100000000
}

/*
struct MyAA {...};  //int num;
         num1  num2   fNum
        ┌─────┬─────┬──────┐
   MyAA │  5  │  6  │ 0.01f│
        └─────┴─────┴──────┘
         0x00   0x04  0x08  => 전체 공간은(12Byte)
    총 4바이트 3개의 공간이 메모리에 생성되며 순차적으로
    연결된 메모리 공간을 가지게 된다.
//===============================================
//   '->' 연산자 사용
//===============================================
    int num = 100;
    int* pNum = &num;
    *pNum = 0; //역참조
    MyAA aa;
    MyAA* pAA = &aa;
    *pAA.num1 => 이런 방식은 불가 => *(pAA.num1) 이렇게 인식되므로 => (*pAA).num1이런식으로 접근해야 한다.
    => 이런 방식을 '->'연산자를 통해서 쉽게 접근하도록 수정 => pAA->num1
    문법: (*pAA).num1 == pAA->num1 동일..

*/