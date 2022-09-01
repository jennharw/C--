

#include <iostream>

using std::cout;
using std::endl;

// 소멸자는 기본적으로 noexcept 함수

void func() noexcept // 해당 함수에서는 예외가 나지 않는다고 선언, 컴파일러가 최적화 할 수 있다
{
    //throw 1; // noexcept 선언한 함수에서 throw 된다고 하더라도 try catch로 처리할 수 없다
}

int main()
{
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}