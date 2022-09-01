//type trait
#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;



template<typename T>
struct is_pointer
{
    static const bool value = false;
};

//템플릿 특수화
template<typename T>
struct is_pointer<T*>
{
    static const bool value = true;
};
template<typename T>
void foo(T t)
{
    cout << is_pointer<T>::value << endl;
}

//--------------------------------
template<typename T>
struct remove_pointer
{
    using type = T;
};

template<typename T>
struct remove_pointer<T*>
{
    using type = T;
};

template<typename T>
struct add_pointer
{
    using type = T*;
};

template<typename T>
struct add_pointer<T&>
{
    using type = T*;
};




enum Unscoped
{
    A, B
};


enum class Scoped : long long
{
    A, B = 10000000000
};


template<typename T>
struct is_scoped_enum
{
    // enum 인데 int로 변환이 되지 않으면 Scoped
    static const bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
    //unscoped는 int로 변환가능 
};

//T Scoped
// SFINAE(Substitution failure is not an erro) 이용
template<typename T, typename std::enable_if<is_scoped_enum<T>::value, int>::type = 0>
std::ostream& operator<<(std::ostream& os, const T& value)
{
    //static_assert(std::is_enum<T>::value, "T is not enum");//SCOPED, UNSCOPED ENUM
    //static_assert(std::is_scoped_enum<T>::value, "T is not enum");//SCOPED, UNSCOPED ENUM

    // underlying_type  을 통해 타입을 알아냄

    cout << "operator<<" << endl;
    using t = typename std::underlying_type<T>::type;
    cout << static_cast<t>(value);
    return os;
}


template<typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
void foo3()
{
    cout << "is integral" << endl;
}
template<typename T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
void foo4()
{
    cout << "is floating" << endl;
}


int main()
{
    cout << std::boolalpha;
    {
        // 컴파일 타임의 타입에 관련된 기능을 제공
        cout << std::is_pointer<int*>::value << endl;
        cout << std::is_pointer<int>::value << endl;

        cout << is_pointer<int*>::value << endl;
        cout << is_pointer<int>::value << endl; // 템플릿 특수화로 인해 true


        int num = 0;
        int* pNum = &num;

        foo(num);
        foo(pNum);
    }
    {
        int num = 0;
        std::add_pointer<int>::type pNum = &num;
        foo(pNum); // true 

        std::remove_pointer<int*>::type n = *pNum;
        foo(n); // false

       //cout << is_pointer<remove_pointer<int*>>::value << endl; // false


    }
    {
        remove_pointer<int>::type num0;
        cout << typeid(num0).name() << endl;

        remove_pointer<int*>::type num1;
        cout << typeid(num1).name() << endl;

        remove_pointer<int**>::type num2; // 특수화
        cout << typeid(num2).name() << endl;
    }
    {
        add_pointer<int>::type num0;
        cout << typeid(num0).name() << endl;

        add_pointer<int*>::type num1;
        cout << typeid(num1).name() << endl;

        add_pointer<int&>::type num2; // 특수화
        cout << typeid(num2).name() << endl;
    }


    {
        cout << A << endl;
        cout << static_cast<std::underlying_type<Scoped>::type>(Scoped::B) << endl; // overflow
        //cout << static_cast<int>(Scoped::B) << endl; // overflow
        cout << Scoped::A << endl;
        cout << Unscoped::B << endl; //unscoped는 


        cout << is_scoped_enum<Unscoped>::value << endl;
        cout << is_scoped_enum<Scoped>::value << endl;
        //std::enable_if<true, int>::type num;

    }
    {
        foo3<int>();
        foo4<float>();
    }

    
}