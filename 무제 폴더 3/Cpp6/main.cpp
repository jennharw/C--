//템플릿 메타 프로그래밍
//템플릿(함수, 클래스), complile타임에 계산


#include <iostream>

using std::cout;
using std::endl;

template<int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};

// 특수화를 통해 재귀 탈출
template<>
struct Factorial<1>
{
    static const int value = 1;
};


template<long long N>
struct Fib
{
    static const long long value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template<>
struct Fib<1>
{
    static const long long value = 1;
};

template<>
struct Fib<0>
{
    static const long long value = 0;
};

int main()
{
    //cout << factorial(5) << endl;
    cout << Factorial<5>::value << endl; // 120이 컴파일 타임에 계산이 된다, 변수를 입력값으로 넣어줄 수 없다

    //cout << fib(6) << endl;
    cout << Fib<6>::value << endl;

    //cout << fib(50) << endl; // 느리다
    cout << Fib<50>::value << endl;
}
