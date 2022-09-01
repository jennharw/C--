#pragma once
#include <iostream>


void autoStatic()
{
    using namespace std;

    for (int i = 0; i < 10; ++i)
    {
        int autoVar = 0; // ¸Å¹ø ÇÒ´ç
        autoVar++;
        cout << "auto : " << autoVar << endl;

        static int staticVar = 0; // ÇÑ ¹ø ÇÒ´ç
        staticVar++;
        cout << "static : " << staticVar << endl;
    }
}