#pragma once
#pragma warning(disable: 4996)
#include <iostream>


class GoodPerson
{
private:
    float _weight;
    float _height;
    char* _name;
public:
    //생성자
    GoodPerson() {}
    GoodPerson(float weight, float height, const char* name)
        :_weight(weight), _height(height), _name(new char[strlen(name)+1])
    {
        strcpy(_name, name); // 복사, 대입 default
    }

    //복사 contents 전체, 깊은 복사 -> 
    GoodPerson(const GoodPerson& person)
        : _weight(person._weight), _height(person._height), _name(new char[strlen(person._name)+1])
    {
        strcpy(_name, person._name);
    }



    ~GoodPerson()
    {
        delete[] _name; // 복사된 객체들이 중복 삭제
    }

    
    GoodPerson& operator=(const GoodPerson& person)
    {
        _weight = person._weight;
        _height = person._height;
        //delete[] _name;

        _name = new char[strlen(person._name) + 1];
        strcpy(_name, person._name);
        return *this;
    }


    void print() const
    {
        using namespace std;
        cout << _name << endl;
        cout << _weight << endl;
        cout << _height << endl;
    }

};