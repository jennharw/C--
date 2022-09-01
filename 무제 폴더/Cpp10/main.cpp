#include <iostream>
#include <string>
using namespace std;

void PrintArrString(const char** ptrString)
{
	cout << "PrintArrString" << endl;
	cout << (ptrString[0]) << endl; //ptrArrStr2[0]
	cout << (ptrString[1]) << endl; //ptrArrStr2[1]
	cout << (ptrString[2]) << endl; //ptrArrStr2[2]

	cout << *(ptrString + 0) << endl;
	cout << *(ptrString + 1) << endl;
	cout << *(ptrString + 2) << endl;
}

int main()
{
    cout << "C 스타일에 문자열 처리" << endl;
    char str1[] = "Hello World";
    char copyStr[12];
	char copyStr2[12];

	char* ptrString;

    strcpy(copyStr, str1);
	strncpy(copyStr2, str1, sizeof(str1));

    ptrString = str1;
    cout << ptrString << endl;
    cout << ptrString[0] << ptrString[1] << ptrString[2] << ptrString[3] << ptrString[4] << endl;

    cout << *(ptrString + 6) << *(ptrString + 7) << *(ptrString + 8) << *(ptrString + 9) << *(ptrString + 10) << endl;

    cout << "문자열 & 포인터" << endl;

    const char* arrs[] = { "apple", "banana", "cherry", "pomegrante", "pepper", "onion" };
    cout << arrs[0] << endl;
    const char* p = arrs[0];
    cout << p << endl;
    //cout << p++ << endl;
    cout<< "시작" << endl;

    for( int i = 0;i < 14; i++){
        cout << "- " << p << " " << *p << endl;
        if (*p != '\0') {
			printf("%c", *p);
		}
		else {
			printf("\n");
		}
		p++;
    }


    {
        char arrStr1[][5] = {"aa","bbb","cccc"};
        const char* ptrArrStr2[] = {"aa","bbb","cccc"};

        cout << arrStr1[0] << ", " << arrStr1[1] << ", " << arrStr1[2] << endl;
        cout << "sizeof(arrStr1[0]): " << sizeof(arrStr1[0]) << endl;
        cout << "sizeof(arrStr1[1]): " << sizeof(arrStr1[1]) << endl;
        cout << "sizeof(arrStr1[2]): " << sizeof(arrStr1[2]) << endl;

	    cout << ptrArrStr2[0] << ", " << ptrArrStr2[1] << ", " << ptrArrStr2[2] << endl;
        cout << "sizeof(ptrArrStr2[0]): " << sizeof("aa") << endl;
        cout << "sizeof(ptrArrStr2[1]): " << sizeof("bbb") << endl;
        cout << "sizeof(ptrArrStr2[2]): " << sizeof("cccc") << endl;
    
        cout << ptrArrStr2[0] << endl;
        cout << ptrArrStr2 << endl;
        cout << *(ptrArrStr2) << endl;
        cout << *(ptrArrStr2+1) << endl;

        cout << *(ptrArrStr2+2) << endl;
        PrintArrString(ptrArrStr2);

    }   

    {
        //동적할당

        int* pNum = nullptr;
        pNum = new int[10];

        delete[] pNum; //해제..[]
	    pNum = nullptr;
        if (pNum == nullptr)
        {
            cout << "pNum Clear" << endl;
        }
        else
        {
            //사용 후 삭제하지 않으면 계속 메모리에 남아 있게된다.
            cout << "pNum[" << 0 << "]: " << pNum[0] << endl;
        }
    

        char* ptrName;
        ptrName = new char[12]; //char arrStr[12];

        strcpy(ptrName, "Hello World");

        cout << ptrName << endl;

        delete[] ptrName;
    }

    {
        string str1 = "abcd efgh";
        cout << "str1 길이(length): " << str1.length() << endl;
        cout << "str1 길이(size): " << str1.size() << endl;
        cout << "str1 " << str1[0] << str1[1] << str1[2] << str1[3] << endl;
        
        string str2;
        str2 = str1;
        cout << "\n = 대입연산자" << endl;
        cout << str2 << endl;
        cout << "\n +- 연산자" << endl;
        str2 += " Hello World";
        cout << str2 << endl;

        cout << "\n append()" << endl;
        str2.append("!!!");
        cout << str2 << endl;
        str2.erase();
        str2.append("xyz", 0, 2); //문자열.append(추가할문자열, 시작위치, 개수);
        cout << str2 << endl;
        str2.append(4, '#');
        cout << str2 << endl;

        cout << "find()함수";

        string str3;

        if (str3.find("abc") != string::npos)  //string::npos 찾는 문자열이 없는 경우 리턴..
        {
            cout << "Find abc: " << str3 << endl;
        }
        else
        {
            cout << "Not Find abc: " << str3 << endl;
        }

        cout << "replace()함수";

        string str4 = "Hello World";
        cout << "replace()" << endl;
        cout << str4 << endl;

        int index = str4.find("Hello");

        if (index != string::npos) //string::npos 찾는 문자열이 없는 경우 리턴..
        {
            str4.replace(index, 5, "-");
            cout << str4 << endl;
        }
    
    }

    {
        // * DESC: 이중 포인터 동적 할당
        cout << "이중 포인터 동적 할당" << endl;

        int col, row;
	    std::cin >> row >> col;
	    int** mat;

        //메모리 할당..
        mat = new int* [row];
        for (int i = 0; i < row; i++)
            mat[i] = new int[col];

        //데이터 초기화..
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = i * col + j;
            }
        }

        //저장 데이터 출력..
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }

        //메모리 해제..
        for (int i = 0; i < row; i++)
            delete[] mat[i];

        delete[] mat;

    }
}
