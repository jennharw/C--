#include <iostream>

using namespace std;

enum DATA
{
	TYPE_INT,
	TYPE_FLOAT,
};

void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void Swap(float* fA, float* fB)
{
	float temp = *fB;
	*fB = *fA;
	*fA = temp;
}

//void*를 매개변수로 사용하여 일반화 함수 구현(단, 실제 내부에서 캐스팅 연산을 해야함)
void SwapVoid(void* vA, void* vB, DATA dataType)
{
	switch (dataType)
	{
		case TYPE_INT:
		{
			int temp = *(static_cast<int*>(vB));
			*(static_cast<int*>(vB)) = *(static_cast<int*>(vA));
			*(static_cast<int*>(vA)) = temp;
			break;
		}

		case TYPE_FLOAT:
		{
			float fTemp = *(float*)vB;
			*(float*)vB = *(float*)vA;
			*(float*)vA = fTemp;
			break;
		}
	}
}


template<typename T>
void SwapTemplate(T* a, T* b)
{
    T temp = *b;
    *b = *a;
    *a = temp;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << "type: " << typeid(T1).name() << " a: " << a << endl;
	cout << "type: " << typeid(T2).name() << " b: " << b << endl;
}

int main()
{
	int aa = 10;
	int bb = 90;
	float fAA = 10.0f;
	float fBB = 90.0f;

	cout << "Before " << "aa: " << aa << " bb:" << bb << endl;
	Swap(&aa, &bb);
	cout << "After " << "aa: " << aa << " bb:" << bb << endl;

	cout << fixed;
	cout << "Before " << "fAA: " << fAA << " fBB:" << fBB << endl;
	Swap(&fAA, &fBB);
	cout << "After " << "fAA: " << fAA << " fBB:" << fBB << endl;

	cout << defaultfloat;
	cout << "Before " << "aa: " << aa << " bb:" << bb << endl;
	SwapVoid(&aa, &bb, DATA::TYPE_INT);
	cout << "After " << "aa: " << aa << " bb:" << bb << endl;

	cout << fixed;
	cout << "Before " << "fAA: " << fAA << " fBB:" << fBB << endl;
	SwapVoid(&fAA, &fBB, TYPE_FLOAT);
	cout << "After " << "fAA: " << fAA << " fBB:" << fBB << endl;

	cout << "========== Template ==========" << endl;

	cout << defaultfloat;
	cout << "Before " << "aa: " << aa << " bb:" << bb << endl;
	SwapTemplate(&aa, &bb);  //SwapTemplate<int>(&aa, &bb);

	cout << "After " << "aa: " << aa << " bb:" << bb << endl;

	cout << fixed;
	cout << "Before " << "fAA: " << fAA << " fBB:" << fBB << endl;
	SwapTemplate(&fAA, &fBB);
	cout << "After " << "fAA: " << fAA << " fBB:" << fBB << endl;

	Print(10, 20.9f);
	Print(10, 20.90000);

	return 0;
}
