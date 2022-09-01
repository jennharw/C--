#pragma once

#include <iostream>
#include <string>

class Person
{
private: 
    float _weight;
    float _height;
    const std::string _name;

public:
    Person(float weight, float height, const std::string& name);
    void print();
};

//함수 선언
void foo();


