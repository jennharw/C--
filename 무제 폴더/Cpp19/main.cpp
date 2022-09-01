#pragma warning(disable: 4996)
#include <iostream>

using namespace std;

int main()
{

    {
        // 드모르간의 법칙
        int score0 = 90;
        int score1 = 80;

        if (score0 >= 90 && score1 >= 90)
            ;
        else
            cout << "fail0" << endl;

        if (!(score0 >= 90 && score1 >= 90))
            cout << "fail1" << endl;
        if (!(score0 >= 90) || !(score1 >= 90))
            cout << "fail2" << endl;
        if (score0 < 90 || score1 < 90)
            cout << "fail3" << endl;
    }

    // {
    //     // if 문 안에서 변수 선언
    //     int num0, num1;
    //     if (int count = scanf("%d %d", &num0, &num1))
    //         printf("count : %d\n", count);
    //     else
    //         printf("fail count : %d\n", count);

    //     // count 에 접근 할 수 없다
    //     // count += 1;

    //     // num0, num1 선언도 안에 넣을 수 있다(C++17 이상)
    //     if (int num0, num1; int count = scanf("%d %d", &num0, &num1))
    //         printf("count : %d\n", count);
    //     else
    //         printf("fail count : %d\n", count);
    // }

    // {
    //     // switch 안에서 변수 선언
    //     int num0, num1;
    //     switch (int count = scanf("%d %d", &num0, &num1))
    //     {
    //     case 1:
    //         cout << num0 << endl;
    //         break;
    //     case 2:
    //         cout << num0 << endl;
    //         cout << num1 << endl;
    //         break;
    //     }
    // }
    // {
    //     // switch 안에서 변수 선언 2
    //     // C++17 이상
    //     switch (int num0, num1;int count = scanf("%d %d", &num0, &num1))
    //     {
    //     case 1:
    //         cout << num0 << endl;
    //         break;
    //     case 2:
    //         cout << num0 << endl;
    //         cout << num1 << endl;
    //         break;
    //     }
    // }



    cout << " ================= " << endl;
    {
        // 두 개 이상의 변수 사용 가능
        for (int i = 0, j = 0; i < 10 && j < 10; i += 1, j += 2)
        {
            cout << i << endl;
            cout << j << endl;
        }
    }
    cout << " ================= " << endl;
    {
        // break의 사용
        for (int i = 0; i < 10; ++i)
        {
            if (i % 3 == 0)
                break;
            if (i % 5 == 0)
                break;

            cout << i << endl;
        }
    }
    cout << " ================= " << endl;
    {
        // continue의 사용
        for (int i = 0; i < 10; ++i)
        {
            if (i % 3 == 0)
                continue;

            cout << i << endl;
        }
    }
    cout << " ================= " << endl;
    {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 1) + a(n - 2)
        
        int num;
        cin >> num;

        if (num < 2)
        {
            cout << num << endl;
        }
        else
        {
            int prevValue = 0;
            int currValue = 1;
            for (int i = 0; i < num - 1; ++i)
            {

                //cout << " -- " << currValue << endl;

                int nextValue = prevValue + currValue;
                prevValue = currValue;
                currValue = nextValue;
            }
            cout << currValue << endl;
        }
    }

     {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 2) + a(n - 1)

        int num;
        cin >> num;
        
        if (0 == num)
            cout << 0 << endl;
        else
        {
            int prevValue = 0;
            int currValue = 1;
            while (--num)
            {
                int nextValue = prevValue + currValue;
                prevValue = currValue;
                currValue = nextValue;
            }
            cout << currValue << endl;
        }
    }


    //do while 
    {
        // Jump 를 위한 do while
        int num;
        cin >> num;
        do
        {
            if (num % 3 == 0)
                break;
            if (num % 5 == 0)
                break;

            cout << "wow" << endl;
        } while (false);

        cout << "abcd" << endl;
    }

    {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 2) + a(n - 1)
        int num;
        cin >> num;
        if (num <= 1)
        {
            cout << num << endl;
        }
        else
        {
            int prevValue = 0;
            int currValue = 1;
            do {
                int nextValue = prevValue + currValue;
                prevValue = currValue;
                currValue = nextValue;
            } while (--num - 1);

            cout << currValue << endl;
        }
    }

    //goto

}