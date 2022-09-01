#include<iostream>

using namespace std;


int main()
{
    const int COL = 8;
    const int ROW = 9;

    //1: 배열에 구구단 결과를 저장
    int arrResult[COL][ROW]; //72개의 구구단 결과를 저장..
    int selectCol = 0;
    
    //72개의 구구단 결과를 저장..
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            arrResult[i][j] = (i + 2) * (j + 1);
        }
    }

    //2: 저장된 데이터를 기반으로 화면 출력
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << "  " << (j + 2) << " X " << (i + 1) << "= " << arrResult[j][i];
        }
        cout << endl;
    }

    //3: 원하는 구구단 결과만 따로 출력..
    cout << endl << "몇 단을 보여드릴까요? ";
    cin >> selectCol;

    //배열의 인덱스는 0부터 시작됩니다. 다시 인덱스 계산
    selectCol -= 2;

    for (int i = 0; i < ROW; i++)
    {
        cout << "  " << (selectCol + 2) << " X " << (i + 1) << "= " << arrResult[selectCol][i] << endl;
    }

    return 0;
}