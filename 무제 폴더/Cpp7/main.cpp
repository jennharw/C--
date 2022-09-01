//포인터

#include <iostream>

using namespace std;

void Swap(int, int);
void SwapRef(int&, int&);
void SwapPoint(int*, int*);

int main()
{
    cout << "포인터" << endl;

    int num = 100;
    int* pNum = &num;

    cout << "num: " << num << "  &num: " << &num << endl; //100
	cout << "pNum: " << pNum << "  *pNum: " << *pNum << "  &pNum: " << &pNum << endl; //, 100, -

    {
        cout << "배열 & 포인터" << endl;
        int arrNum[5] = { 0, 1, 2, 3, 4 };
        int* pArrNum = arrNum; // &arrNum[0], 주소

        for (int i = 0; i<5; i++)
        {
            cout << arrNum[i] << &arrNum[i] << endl;
            cout << endl;
        }

        cout << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << pArrNum + i << "     " << *(pArrNum + i) << endl;
        }
        /*
                                         Address│   메모리
 pArrNum   (pArrNum + 0)        ────────┼────────────────────
 arrNum    →→ &arrNum[0]   →→→    0x00  │
                                  0x01  │
                                  0x02  │      0
                                  0x03  │
             (pArrNum + 1)      ────────┼────────────────────
              &arrNum[1]   →→→    0x04  │
                                  0x05  │
                                  0x06  │      1
                                  0x07  │
             (pArrNum + 2)      ────────┼────────────────────
              &arrNum[2]   →→→    0x08  │
                                  0x09  │
                                  0x0A  │      2
                                  0x0B  │
             (pArrNum + 3)      ────────┼────────────────────
              &arrNum[3]   →→→    0x0C  │
                                  0x0D  │
                                  0x0E  │      3
                                  0x0F  │
            (pArrNum + 4)       ────────┼────────────────────
              &arrNum[4]   →→→    0x10  │
                                  0x11  │
                                  0x12  │      4
                                  0x13  │
                                ────────┼────────────────────

            */
    }



    {
        //함수의 파라미터 혹은 리턴 값으로 포인터를 사용하는 이유
        /*
        1 연속된 메모리 공간에 주소값으로 처리
        2 CallbyReference 함수에서 하나 이상의 값을 리턴하거나 변경해야 하는 경우
        3 동적할당
        4 메모리 공간의 효율적 사용 :  거대한 사용자 자료형을 함수 파라미터로 주소값만 넘기면 되므로(메모리에 복사를 줄임)
        -> 데이터 크기가 얼마이든 포인터에 해당하는 4바이트 아키텍쳐에 해당하는 기본 데이터로 통신 가능
        */
       	cout << "배열 & 포인터 & 함수" << endl;
	    cout << "CallByRefrence Vs. CallByValue" << endl;

        int num1 = 0;
        int num2 = 1000;
        cout << "Before Swap(int, int)"<< "num1: " << num1 << "  num2: " << num2 << endl;
        Swap(num1, num2);
        cout << "After Swap(int, int)" << "num1: " << num1 << "  num2: " << num2 << endl << endl;

        cout << "Before SwapRef(int&, int&)" << "num1: " << num1 << "  num2: " << num2 << endl;
        SwapRef(num1, num2); 
        cout << "After SwapRef(int&, int&)" << "num1: " << num1 << "  num2: " << num2 << endl << endl;;

        cout << "Before SwapPoint(int*, int*)" << "num1: " << num1 << "  num2: " << num2 << endl;
        SwapPoint(&num1, &num2); //int* ptrNum1 = &num1;
        cout << "After SwapPoint(int*, int*)" << "num1: " << num1 << "  num2: " << num2 << endl << endl;;
    }

}

void Swap(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void SwapRef(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void SwapPoint(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}