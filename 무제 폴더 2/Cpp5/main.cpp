#include <iostream>
#include "function.h"
#include "Village.h"
#include "person.h"

using namespace std;


void foo1(); // util1.cpp

int main()
{
    func();
    //foo1();

    Village v;
    v.add(new Person(10, 10, "david"));

}