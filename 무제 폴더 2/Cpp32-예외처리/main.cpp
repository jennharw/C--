
#pragma warning(disable: 4996)
#include <iostream>

using std::cout;
using std::endl;

using namespace std;

class Test
{
public:
    ~Test() { cout << "test" << endl; }
};


double divide(double d, double v)
{
    if (v == 0)
    {
        throw "Dirived by zero"; // 처리 되지 않으면 std::terminate
    }
    return d / v;
}
void terminateFunc()
{
    cout << "terminate" << endl;
}


class Parent {};
class Child : public Parent {};


void func1()
{
    Test t;
    divide(10, 0);
}

void func0()
{
    Test t;
    func1();
}


int main()
{
    //std::set_terminate();
    // terminate 시 실행할 함수 지정 가능
    std::set_terminate(terminateFunc);


    try
    {
        cout << divide(10, 0) << endl;
    }
    catch (const char* e)
    {   
        cout << e << endl;
    }
    catch (...)
    {
        cout << "..." << endl;
    }

    try{
        throw Child();
    }
    catch (Parent&) // 부모 타입으로 받을 수 있다
    {
        cout << "Parent" << endl;
    }
    catch (Child&) // catch 순서대로 체크를하기 때문에 위쪽 catch에 호환이 되기 때문에 위쪽 catch로 가게 된다
    {
        cout << "Child" << endl;
    }

    cout << "----" << endl;
    try
    {
       func0(); // divide에서 예외가 발생했지만 예외를 처리할 수 있는 곳까지 함수 스택을 되돌린다
    }
    catch(const char& e)
    {
        cout << e << endl;
        //throw; // 받은 예외를 rethrow 할 수 있다
    }
    
    // std::exception을 상속해서 예외 객체를 만들자
    // 표준 라이브러리의 예외들도 std::exception을 상속했음
    //std::runtime_error; // 표준 라이브러리의 예외 중 하나
}