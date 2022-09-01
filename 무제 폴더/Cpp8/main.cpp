#include <iostream>

using namespace std;

void SetData(int**);
void SetData1(int*);

void Print(int* ptrNum)
{
	if (nullptr != ptrNum)
	{
		cout << "ptrNum: " << ptrNum << "  *ptrNum: " << *ptrNum  << endl;
	}
	else
	{
		cout << "ptrNum  nullptr: " << ptrNum << endl;
	}
}



int main()
{
	cout << "이중 포인터" << endl; //이중 포인터: 포인터의 메모리 주소를 저장하는 포인터의 포인터

    int num = 100;
    int* ptrNum = &num;
    int** ptrptrNum = &ptrNum;
    cout << "num:  " << num << endl;
	cout << "*ptrNum:  " << *ptrNum <<" " << ptrNum << endl;
	cout << "**ptrptrNum:  " << **ptrptrNum << " " << ptrptrNum << endl;

    SetData(&ptrNum);

    cout << *ptrNum << ptrNum << " " << &ptrNum << endl;


    SetData1(ptrNum);
    cout << *ptrNum << ptrNum << " " << &ptrNum << endl;




    //nullptr
    cout << "nullptr사용" << endl;

	int num1 = 100;
	int* pNum = &num1;
	Print(pNum);

    pNum = nullptr;
	Print(pNum);

    cout << "void 포인터" << endl;
	void* ptr;
	float fNum = 0.001f;
	const double DNUM = 10000.0000;

	ptr = &num1;
    /*
    void 포인터:
	타입에 제한이 없으므로 유연한 프로그래밍이 가능.
	1. 역참조시 반드시 형변환(캐스팅)후에 처리
	2. 포인터 연산 불가
	3. const는 초기화 불가
    */

    cout << "1. 역참조시 반드시 형변환(캐스팅)후에 처리: *(int*)ptr" << endl;
    cout << "*ptr: "  << *(int*)ptr << endl;	
    ptr = &fNum;
    cout << "*ptr: "  << *static_cast<float*>(ptr) << endl;

    //ptr++; 2. 포인터 연산 불가
    cout << "2. 포인터 연산 불가: ptr++" << endl;

    //ptr = &DNUM; //3. const는 초기화 불가
    cout << "3. const는 초기화 불가: const double DNUM = 10000.0000;  ptr = &DNUM;" << endl;


}

void SetData(int** pNum)
{
    int data = 500;
    *pNum = &data;
}

void SetData1(int* pNum)
{
    int data = 1000;
    *pNum = data;
}