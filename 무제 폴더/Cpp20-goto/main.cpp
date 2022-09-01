#include <iostream>

using namespace std;

int main()
{
    //go:
    //    cout << 1 << endl;
    //    goto go;

    {
        int num = 4;
        if (num % 3 == 0)
            goto go;
        if (num % 5 == 0)
            goto go;
        cout << "can't divide 3 and 5" << endl;

    go:
        cout << "wow" << endl;
    }

    {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 2) + a(n - 1)

        int num;
        cin >> num;

        if (num <= 1)
            cout << num << endl;
        else
        {
            int prevValue = 0;
            int currValue = 1;

        add:
            int nextValue = prevValue + currValue;
            prevValue = currValue;
            currValue = nextValue;
            if (--num - 1)
                goto add;
            cout << currValue << endl;
        }
    }
}