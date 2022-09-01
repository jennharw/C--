#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

class NotMoveString
{
private:
    char* _str;
public:
    NotMoveString(const char* str)
        :_str(new char[strlen(str)+1])
    {
        strcpy(_str, str);
        std::cout << "NotMovingString Construct : " << _str << std::endl; 
    }

    NotMoveString(const NotMoveString& other)
        :_str(new char[strlen(other._str) + 1])
    {
        strcpy(_str, other._str);
        std::cout << "Not Moving String copy construc : " << _str << std::endl;
    }

    ~NotMoveString()
    {
        std::cout << "NotMoveString Destruct : " << (_str ? _str : "") << std::endl;
    }

    NotMoveString& operator=(const NotMoveString& other)
    {
        std::cout << "NotMoveString Copy operator : " << _str << " = " << other._str << std::endl;
        delete[] _str;

        _str = new char[strlen(other._str) + 1];
        strcpy(_str, other._str);
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, NotMoveString& str)
    {
        return (os << str._str);
    }

};