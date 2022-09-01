// 포인터 & 이차원 배열
#include<iostream>

using namespace std;

const int COL = 8;
const int ROW = 9;

void Init(int (*ptrArr)[ROW]);
void PrintData(int (*ptrArr)[ROW]);
void SelectData(int ptrArr[][ROW]);
int main()
{
    cout << "이중 포인터 & 배열" << endl;
    int arrResult[COL][ROW]; //72

    cout << "sizeof ArrResult " << sizeof(arrResult) << endl;

    //1: 배열에 구구단 결과를 저장
    Init(arrResult);
    
    cout << &arrResult << " " << arrResult << " " << **arrResult << endl;
    cout << **(arrResult+1) << " " << arrResult + 1 << " " << *(arrResult + 1) << endl;


    cout << &arrResult[0][1] << " " << arrResult[0][1] << " " << *(&arrResult[0][1]) << endl;
    cout << &arrResult[0][1] + 1 << " " << arrResult[0][1] + 1 << " " << *(&arrResult[0][1] + 1) << endl;

    //2: 저장된 데이터를 기반으로 화면 출력
    //PrintData(arrResult);
}

void Init(int(*ptrArr)[ROW])
{
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            ptrArr[i][j] = (i + 2) * (j + 1);
            //*(*(ptrArr + i) + j) = (i + 2) * (j + 1);
        }
    }

    cout << "sizeof(ptrArr): " << sizeof(ptrArr) << endl;
}

void PrintData(int(*ptrArr)[ROW])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << "  " << (j + 2) << " X " << (i + 1) << "= " << ptrArr[j][i];
            //cout << "  " << (j + 2) << " X " << (i + 1) << "= " << *(*(ptrArr + j) + i);
            //cout << "  " << (j + 2) << " X " << (i + 1) << "= " << (*(ptrArr + j))[i];
            //cout << "  " << (j + 2) << " X " << (i + 1) << "= " << *(ptrArr[j] + i);
        }
        cout << endl;
    }

    cout << "sizeof(ptrArr): " << sizeof(ptrArr) << endl;

    //1행의 열이 출력(이중포인터가 아닌 값참조)..
    for (int j = 0; j < COL; j++)
    {
        cout << "**ptrArr++: " << **(ptrArr++) << endl; //++는 ROW만큼 이동..
    }
}

/*
 이차원 배열[8][9]        //실제 메모리에 저장되는 형태는 아니며 이해하기 위해서 입체적으로 표현
     [0]   [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]
   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   │  2  │  4  │  6  │  8  │  10 │  12 │  14 │  16 │  18 │   (ptrArr + 0) 
   └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   │  3  │  6  │  9  │  12 │  15 │  18 │  21 │  24 │  27 │   (ptrArr + 1) 
   └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   │  4  │  8  │  12 │  16 │  20 │  24 │  28 │  32 │  36 │   (ptrArr + 2)
   └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   
                              int arrNum[8][9]
                                 Address│   메모리
 *(ptrArr + 0)                  ────────┼────────────────────
 arrNum[0] →→ arrNum[0][0] →→→    0x00  │
 &arrNum[0]  &(&arrNum[0])[0]     0x01  │
                                  0x02  │      2
                                  0x03  │
        (*(ptrArr + 0) + 1)     ────────┼────────────────────
              arrNum[0][1] →→→    0x04  │
                                  0x05  │
                                  0x06  │      4
                                  0x07  │
        (*(ptrArr + 0) + 2)     ────────┼────────────────────
              arrNum[0][2] →→→    0x08  │
                                  0x09  │
                                  0x0A  │      6
                                  0x0B  │
                                ────────┼────────────────────
              arrNum[0][3] →→→    0x0C  │
                                  0x0D  │
                                  0x0E  │      8
                                  0x0F  │
                                ────────┼────────────────────
              arrNum[0][4] →→→    0x10  │
                                  0x11  │
                                  0x12  │      10
                                  0x13  │
                                ────────┼────────────────────
              arrNum[0][5] →→→    0x14  │
                                  0x15  │
                                  0x16  │      12
                                  0x17  │
                                ────────┼────────────────────
              arrNum[0][6] →→→    0x18  │
                                  0x19  │
                                  0x2A  │      14
                                  0x2B  │
                                ────────┼────────────────────
              arrNum[0][7] →→→    0x2C  │
                                  0x2D  │
                                  0x2E  │      16
                                  0x2F  │
                                ────────┼────────────────────
              arrNum[0][8] →→→    0x30  │
                                  0x31  │
                                  0x32  │      18
                                  0x33  │
 *(ptrArr + 1)                  ────────┼────────────────────
 arrNum[1] →→ arrNum[1][0] →→→    0x34  │
                                  0x35  │
                                  0x36  │      3
                                  0x37  │
        (*(ptrArr + 1) + 1)     ────────┼────────────────────
              arrNum[1][1] →→→    0x4A  │      6
*/