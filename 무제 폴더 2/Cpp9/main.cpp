#include <iostream>
#include <functional>

using namespace std;


class Person
{
public:
    void print(int i)
    {
        cout << i << endl;
    }

    static void staticPrint(int i)
    {
        cout << i << endl;
    }
};


//클래스 함수 포인터

int main()
{
    void (Person:: *fn)(int) = &Person::print; //클래스 함수 포인터

    Person person;
    (person.*fn)(1); //this 넘겨줘야

    typedef void (Person::* Func0)(int); 
    Func0 fn0 = &Person::print;
    (perons.*fn0)(2);

    using Func1 = void (Person::*)(int);
    Func1 fn1 = &Person::print;
    (person.*fn1)(3);

    function<void(Person*, int)> fn2 = &Person::print;
    fn2(&person, 4);


    // static은 일반 함수와 동일
    void (*fn3)(int) = &Person::staticPrint;
    fn3(5);
}