//template 

//함수 템플릿
#include <iostream>

using std::cout;
using std::endl;

//함수 템플릿
template<typename T>
void swap(T& x, T& y)
{
    int temp = x;
    x = y;
    y = temp;
}

template<int N, typename T>
int getSize(T(&nums) [N])
{
    return N;
};

// 템플릿의 파라메터로 int 값을 받는다
template<int N>
int func(int (&nums)[N])
{
    return N;
}


int main()
{
    {
        int x = 10, y = 20;
        swap<int>(x, y); // 타입 명시
        cout << x << endl;
        cout << y << endl;

        swap(x, y); // 명시하지 않아도 타입이 추론된다.(여기서는 int로 추론된다)
    }
    {
        int nums[] = { 1, 2, 3 };
        cout << func<3>(nums) << endl; // 값 명시
        cout << func(nums) << endl;  // 3을 추론한다. 즉 배열의 사이즈를 추론을 통해서 구할 수 있다
    }
    {
        int nums[] = { 1,2,3 };
        cout << getSize(nums) << endl;

        char chars[] = {'a'};
        cout << getSize(chars) << endl;
    }
}

