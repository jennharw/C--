/*-----------------------------------------------------------------------------
 * Name: [Bonus]_Template02
 * DESC:  template(형, 틀)
 * 일반화 프로그램 - 재사용성과 편의성
 * C++에 STL을 구현하는 대표적 문법 요소
 * 분리 컴파일 불가!! - .h, .cpp로 분리 불가..
 * 함수 탬플릿, 클래스 탬플릿
-----------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

class MyException
{
public:
    int data;
    const char* text;

    MyException(const char* _text, int _data) 
        : text(_text), 
          data(_data) 
    {
        std::cout << "Error Data First!!: " << data << std::endl;
    }
};

template<typename T>
class MyStack
{
public:
    MyStack(unsigned int _size = 100);
    ~MyStack();

    void Push(T _data);
    T Pop();

    bool isFirst() const;
    bool isMax() const;

    int GetSize() { return size; }

private:
    T* data;
    unsigned int size;
    int top;
};

template<typename T>
MyStack<T>::MyStack(unsigned int _size)
{
    size = _size;
    top = 0;
    data = new T[size];
}

template<typename T>
MyStack<T>::~MyStack()
{
    delete[] data;
}

template<typename T>
void MyStack<T>::Push(T _data)
{
    if (isMax())
    {
        std::cout << "Error Data Max!!" << std::endl;
        //throw std::out_of_range("Error Data Max!!"); 
    }
    data[top] = _data;
    top++;
}

template<typename T>
T MyStack<T>::Pop()
{
    if (isFirst())
    {
        throw MyException("Error Data First!!", top);
    }

    T popData = data[--top];

    return popData;
}

template<typename T>
bool MyStack<T>::isMax() const
{
    bool isFull = top == size;
    return isFull;
}

template<typename T>
bool MyStack<T>::isFirst() const
{
    bool isStart = top <= 0;
    return isStart;
}

int main()
{
    MyStack<int> myStack(3);

    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    //myStack.Push(4);

    cout << myStack.Pop() << endl;
    cout << myStack.Pop() << endl;
    cout << myStack.Pop() << endl;
    //cout << myStack.Pop() << endl;

    MyStack<float> myStack2;

    for (int i = 0; i < myStack2.GetSize(); i++)
    {
        myStack2.Push(i * 0.1f);
    }

    for (int i = 0; (false == myStack2.isFirst()); i++)
    {
        cout << myStack2.Pop() << ", ";
        if (i % 10 == 0) cout << endl;
    }

    return 0;
}