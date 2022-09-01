#include <iostream>

using std::cout;
using std::endl;

class Parent
{
public:
    Parent() {}
    explicit Parent(int i) {}
};

enum class Type
{
    A, B, C
};

//C 스타일 변환
void constCastFunc(int i)
{
    const int& j = i;
    int& k0 = (int&)j; // const_cast

    // C스타일 캐스트보다 의도가 명확하다
    int& k1 = const_cast<int&>(i);
}

int main()
{
    //C 스타일 캐스팅
    int num0 = (int)Type::A;
    //함수형 스타일 캐스팅
    int num1 = int(Type::A);

    int i = 10;
    float& f = (float&)i; // reinterpret_cast


    const int& j = i;
    int& k = (int&)j; // const_cast

    i  = (int)Type::A; //static_cast

    Parent p;

    // 아래는 생성자 호출인가 변환인가?, 둘 다 맞음
    p = Parent(10);
    p = (Parent)10;
}

