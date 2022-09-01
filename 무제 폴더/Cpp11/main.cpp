// * DESC: 이중 포인터 동적 할당 & 함수
#define _CRT_SECURE_NO_WARNINGS //#pragma warning(disable : 4996)

#include <iostream>

using namespace std;
void InputObject(int*, int*, char**, int);
void PrintObject(int*, int*, char**, int);
int main()
{
    cout << "동적 할당 CheckPoint" << endl;

    int size = 0;

	cout << "몇개의 오브젝트를 생성할까요?";
	cin >> size;

    int* mp;
    int* hp;
    char** charName;

    mp = new int[size];
    hp = new int[size];
    charName = new char* [size];

    InputObject(mp, hp, charName, size);
    PrintObject(mp, hp, charName, size);
    delete[] mp;
    delete[] hp;

    for(int i = 0; i < size ; i ++ )
    {
        delete[] charName[i];
    }
    delete[] charName;
}


void PrintObject(int* pMp, int* pHp, char** pName, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        //cout << pMp[i] << endl;
        //cout << pHp[i] << endl;
        //cout << pName[i] << endl;

        cout << *(pMp + i) << endl;
        cout << *(pHp + i) << endl;
        cout << *(pName + i) << endl;
    }
}

void InputObject(int* pMp, int* pHp, char** pName, int size)
{
    for (int i = 0; i < size; i++)
    {
        int inputHP = 0;

        cout << "HP입력?";

        cin >> inputHP;

        pHp[i] = inputHP;

        cout << "MP입력?";
        cin >> pMp[i];

        char str[100];
        cout << "이름?";
        cin >> str;

        pName[i] = new char[strlen(str) + 1];
        strcpy(pName[i], str);
    }
}
