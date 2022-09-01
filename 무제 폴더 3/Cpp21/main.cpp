//lambda
#include <iostream>
#include <functional>

void foo(std::function<void(void)> func)
{

}
void goo(int)
{

}

struct Func // 사실 람다는 함수객체
{
    int value;
    void operator()() const // mutable 시 함수 객체 삭제 됨
    {

    }
};

int main()
{

    Func func;
    int value = 10;

    func.value = value;
    foo(func); // 람다의 사용은 이것과 비슷



    //기본적인 lambda 형태
    [/*캡쳐*/] (/*파라미터*/) /*반환형*/
    {

    };

    //int value = 10;
    //foo(goo) 넘겨 줄 수 없음    
    foo([value]()
    {
        goo(value);
    });

    //참조로 캡쳐
    foo([&value]() 
    {
        goo(value);
    });

    // 함수객체에서 const를 삭제
    foo([value]() mutable 
    {
        value = 20;
        goo(value);
    });

    int num = 10;
    auto func0 = [num]() mutable
    {
        ++num;
        return num;
    };

    // 일반적으로 함수 호출 시 내부의 값이 변하게 되면 의도하지 않은 상황이 발생할 수 있다. 때문에 기본적으로 mutable이 아님
    std::cout << func0() << std::endl; // 11
    std::cout << func0() << std::endl; // 12

    int num0 = 10;
    int num1 = 20;

    // // 모든 녀석을 값으로 캡쳐 가능
    // [=]() 
    // {
    // };
    // // 모든 변수를 참조로 캡쳐 가능
    // [&]() 
    // {
    // };

    // 캡쳐 없는 람다는 함수 포인터와 호환 됨
    void (*f)(int) = [](int){};
    auto f0 = [](int) {}; //선언시 auto 사용
    std::function<void(int)> f1 = [](int){};

    auto f2 = [](auto value) // Generic 람다
    {
        return value;
    };
    
    // 템플릿 람다, C++20
    // auto f3 = []<typename T>(T value) 
    // {
    //     return value;
    // };

}