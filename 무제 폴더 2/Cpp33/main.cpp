#include <iostream>
#include <memory>


using std::cout;
using std::endl;

class RAII  //Resource Acquisition is initialization, 해제 시 중요
{
public:
    int* i;
    RAII()
    {
        i = new int;
    }
    ~RAII()
    {
        cout << "~RAII" << endl;
        delete i;
    }
};


class Test
{
public:
    ~Test() { cout << "~Test" << endl; }
};


void func()
{
    throw "exception";
}


int main()
{

    // try
    // {
    //     Test* i = new Test; // *i 는 메모리 leak 발생
    //     func();
    // }
    // //catch(const std::exception& e)
    // catch (const char* e)
    // {
    //     cout << e << endl;
    //     //std::cerr << e.what() << '\n';
    // }

    // try
    // {
    //     int* i = new int; // *i 는 메모리 leak 발생
    //     func();
    // }
    // //catch(const std::exception& e)
    // catch (const char* e)
    // {
    //     cout << e << endl;
    //     //std::cerr << e.what() << '\n';
    // }
    
    try
    {
        RAII raii;
        func();
    } // 블럭을 벗어나면서 RAII의 소멸자가 호출되면서 내부에 할당한 동적 객체가 해제된다
    catch (const char* e)
    {
        cout << e << endl;
    }
    //할당, DBconnection 등

    try
    {
        // unique_ptr을 이용해 동적할당에 대한 RAII를 사용할 수 있다
        std::unique_ptr<Test> test(new Test()); // 소멸자 호출
        func();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
    
}