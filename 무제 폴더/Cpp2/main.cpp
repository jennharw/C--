#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main()
{
	{
        std::cout << "Hello World!";
        //return 0;
    }
    //Data, int, 상수, 변수 
    {
        int nNum = 0;
        nNum = 100;
        std::cout << "Num: " << nNum << std::endl;
    }

    /*
    int 4Byte
    long : -2,147,483,648 ~ 2,147,483,647(signed long, long int)
    unsigned long: 0 ~ 4,294,967,295(unsigned long int, unsigned int)

    └ long long	 __int64 8byte

    short int short int : -32,768 ~ 32,767 (signed short)
    unsigned int: 0 ~ 65,535 (unsigned short)

    float(4Byte)	: 1.17549e-38 ~ 3.40282e+38
		┼
	doule(8Byte)	: 2.22507e-308 ~ 1.79769e+308

    char(1Byte)

    bool 1byte 0, 1

    */
   {
        std::cout << sizeof(int) << std::endl;
        int iMax = std::numeric_limits<int>::max();
        int iMin = std::numeric_limits<int>::min();

        std::cout << "int max : " << iMax << "\t min : " << iMin << std::endl;
        std::cout << "unsigned INT_MAX : " << INT_MAX << "\t INT_MIN : " << INT_MIN << std::endl;

        short int num = 4;
        std::cout << sizeof(short int) << std::endl; // 2byte

        std::cout << "=== 데이터형에 최대 최소값에 따른 오류 ===" << std::endl;

		int min = INT_MIN - 1;
		int max = INT_MAX + 1;

		std::cout << "min: " << min << "  max: " << max << std::endl;

        long long lnum = 100;

		std::cout << "=== long long에 대한 세부 정보 보기 ===" << std::endl;

		std::cout << "long long size: " << sizeof(long long) << std::endl;

		long long longMax = std::numeric_limits<long long>::max();
		long long longMin = std::numeric_limits<long long>::min();
		std::cout << "long long max : " << iMax << "\t min : " << iMin << std::endl;
		std::cout << "long long LLONG_MAX : " << LLONG_MAX << "\t LLONG_MIN : " << LLONG_MIN << std::endl;
		std::cout << std::endl;
        std::cout << "=== 데이터형에 최대 최소값에 따른 오류 ===" << std::endl;

		long long long_min = LLONG_MIN - 1;
		long long long_max = LLONG_MAX + 1;

		std::cout << "min: " << min << "  max: " << max << std::endl;

        float fNum = 0.1f;
        fNum = 100.43f;
        std::cout << "float size: " << sizeof(float) << std::endl;
        float fMax = std::numeric_limits<float>::max();
		float fMin = std::numeric_limits<float>::min();
		std::cout << "float max : " << fMax << "\t min : " << fMin << std::endl;
		std::cout << "float FLT_MAX : " << __FLT_MAX__ << "\t FLT_MIN : " << __FLT_MIN__ << std::endl;
	    
        double kdNumber = 1234.123456789;

        std::cout << kdNumber << std::endl; //디폴트로 6자리

        std::cout.precision(5); // 5자리로 설정
        std::cout << kdNumber << std::endl;

        std::cout << std::fixed; //소수점만 따로 고정
        std::cout.precision(9); //소수점 9자리로
        std::cout << kdNumber << std::endl;

        char ch = 'A';
        std::cout << "char: " << ch << std::endl;
        std::cout << "=== char에 대한 세부 정보 보기 ===" << std::endl;

        std::cout << "char size: " << sizeof(char) << std::endl;
		std::cout << "CHAR_MAX : " << CHAR_MAX << "\t CHAR_MIN : " << CHAR_MIN << std::endl;
		std::cout << std::endl;

        std::cout << "=== 데이터형에 최대 최소값에 따른 오류 ===" << std::endl;

		char char_min = CHAR_MIN - 1;
		char char_max = CHAR_MAX + 1;

		std::cout << "min: " << (int)char_min << "  max: " << (int)char_max << std::endl;
		std::cout << "min: " << char_min << "  max: " << char_max << std::endl;

        char chA = 'A';
        std::cout << chA << std::endl;
        char ch02 = 1000001;
	    std::cout << "ch02(1000001): " << ch02 << std::endl;

        char ch08 = '\101';
        std::cout << "ch08(\'101\'): " << ch08 << std::endl;

        char ch10 = 65;
        std::cout << "ch10(65): " << ch10 << std::endl;

        char ch16 = '\x41';
        std::cout << "ch16(\'x41\'): " << ch16 << std::endl;

        char alert = '\a';
        char newline = '\n';
        char tab = '\t';
        char backspace = '\b';
        char backslash = '\\';
        char nullChar = '\0';
        char singleQuotation = '\'';
        char doubleQuotation = '\"';

	    std::cout << "sizeof(bool): " << sizeof(bool) << std::endl; // 1Byte
        // C++에서는 어떤 값도 bool형으로 묵시적 타입 변환이 가능합니다.
        // bool isTemp05 = 123456; //(0을 제외한 모든 수는 참)
        // 이때 0인 값은 거짓(false)으로, 0이 아닌 값은 참(true)으로 자동 변환됩니다.

   }

   {
        float fNum01(98.7654f);
        float fNum02 = 0.123456f;

        //기본 표기
        cout << "기본 출력 fNum01: " << fNum01 << endl;
        cout << "기본 출력 fNum02: " << fNum02 << endl;

        //고정 소수점 표기
        cout << fixed;
        cout.precision(4);
        cout << "소수점 표기 4자리 fNum01: " << fNum01 << endl;
        cout << "소수점 표기 4자리 fNum02: " << fNum02 << endl;

        //지수 표기
        cout << scientific;
        cout.precision(8);
        cout << "지수 표기 fNum01: " << fNum01 << endl;
        cout << "지수 표기 fNum02: " << fNum02 << endl;

        //기본 표기
        cout << defaultfloat;
        cout.precision(5);
        cout << "기본 출력 fNum01: " << fNum01 << endl;
        cout << "기본 출력 fNum02: " << fNum02 << endl;

        int num = 100;
        cout.width(10);
        cout << num << endl;

        // fmtflags 타입 상수들을 직접 이용하기
        cout.setf(ios_base::hex, ios_base::basefield);
        cout.setf(ios_base::showbase); //setf(인자)          인자 1개
        cout << num << endl;

        // ios_base 를 상속 받은 ios 에서도 이 멤버들에 접근할 수 있다.
        cout.setf(ios::hex, ios::basefield); //fmtfl 서식 플래그 값,  mask 필드 비트마스크
        cout.setf(ios::showbase); //스트림 서식 플래그(format flag)
        cout << num << endl;

        // 역시 이들을 객체의 멤버 상수들로도 접근할 수 있다.
        cout.setf(cout.hex, cout.basefield);
        cout.setf(cout.showbase);
        cout << num << endl;

        cout.unsetf(ios_base::basefield | ios::showbase);
        cout << num << endl;
        
        cout << "(flags, right, hex, showbase)우측 정렬, 진법을 명시, 16진수 num: ";
        cout.width(10);
        cout.flags(ios::right | ios::hex | ios::showbase);
        cout << num << endl;

        cout << "(flags, left, hex, showbase)좌측 정렬, 진법을 명시, 16진수 num: ";
        cout.width(10);
        cout.flags(ios::left | ios::hex | ios::showbase);
        cout << num << endl;

        // fmtflags를 변수 형태로 사용
        ios_base::fmtflags ff;
        ff = cout.flags();      //현재 스트림의 서식 플래그가 어떻게 설정되어 있는지 리턴
        ff &= ~cout.basefield;  // basefield 비트들을 초기화 시켜버린다.
        ff |= cout.hex;         // hex 를 설정
        ff |= cout.showbase;    // showbase 를 설정
        cout.flags(ff);
        cout << "(flags, hex, showbase)진법을 명시, 16진수 num: " << num << endl;

        // 아래는 fmtflags 타입 멤버들을 이용한 것은 아니고
        // 이름이 동일한 조작자 showbase 를 이용한 것이다
        cout << hex << showbase << "(hex, showbase)진법을 명시, 16진수 num: " << num << endl;
        cout.unsetf(ios_base::basefield | ios::showbase);

        double dNum01 = 10;
        double dNum02 = 1.23456789;

        cout << right;
        cout << "폭 10인 d_num1 = " << setw(10) << dNum01 << endl;
        cout << "폭 10인 d_num2 = " << setw(10) << dNum02 << endl << endl;

        cout << "폭 10에 빈공간을 #으로 채움 d_num1 = " << setw(10) << setfill('#') << dNum01 << endl;
        cout << "폭 10에 빈공간을 #으로 채움 d_num2 = " << setw(10) << dNum02 << endl << endl;
        
        cout << "소수점 표기, 소수점 3째까지 출력 " << endl;
        cout << fixed << setprecision(3);
        cout << dNum01 << endl;
        cout << dNum02 << endl;

        cout << "typeid로 자료형이름 출력: " << typeid(num).name();

        /*
        setf(인자)
        boolalpha
        showbase (정수 표기시, 진법 명시 0x)
        showpoint
        showpos
        skipws
        unitbuf
        uppercase

        setf(인자, 인자)
        dec | oct | hex basefield
        scientific | fixed floatfield
        left | right | internal adjustfield

        조정자 함수	 사용 결과
        setfill (char c)	 c 문자로 여백을 채움
        setw (int n)	 n 만큼 필드폭을 지정(사용할 때 마다 지정해야함)
        setprecision(int n)	 소수점 n 자리까지 표시
        */
   }

   {    
        int cin_num = 0;
        char selCh;
        cout << endl;

        cout << "숫자를 입력하세요 : ";
        cin >> cin_num;
        if (cin.fail())
        {
            cout << "입력 오류 다시 입력하세요 " << endl;
            cin.clear(); //cin객체의 "내부 상태 플래그"를 초기화 => cin 관련 기능이 정상
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //입력 버퍼의 최대 크기만큼 무시
			//cin.ignore(INT_MAX, '\n'); //1번째: 무시할 문자 개수, 2번째: 종료할 문자
            //cin.setf(ios_base::hex, ios_base::basefield); //입력을 16진수로 처리

            cin >> cin_num;
        }
        cout << "입력한 값은 : " << cin_num << endl;

        cin.clear();
		cin.ignore();
        cout << "문자를 입력하세요 : ";
        //cin >> selCh;
        selCh = cin.get();	

        cout << "입력한 문자는 : " << selCh << endl;

   }


   //operator 연산자
   {
        int num1 = 200;
		int num2 = 30;

		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;

		cout << "+ 연산자(num1 + num2):  " << num1 + num2 << endl;
		cout << "- 연산자(num1 - num2):  " << num1 - num2 << endl;
		cout << "* 연산자(num1 * num2):  " << num1 * num2 << endl;
		cout << "/ 연산자(num1 / num2):  " << num1 / num2 << endl;
		cout << "% 연산자(num1 % num2):  " << num1 % num2 << endl;

        // int num1 = 10;
        // int num2 = 10;
        int num3 = 10;
        int num4 = 10;
        int num5 = 10;
        
        int output1 = ++num1 + 10;
        int output2 = num2++ + 10; //num2 + 10 = 20
        int output3 = --num3 + 10;
        int output4 = num4-- + 10;
        int output5 = num5-- + 10 + --num5;
        
        // bool output1 = num1 == num2;
        // bool output2 = num1 != num2;
        // bool output3 = num1 > num2;
        // bool output4 = num1 >= num2;
        // bool output5 = num1 < num2;
        // bool output6 = num1 <= num2;
        // bool output1 = (num1 == 10) && (num2 == 20);
        // bool output2 = (num1 != 10) && (num2 == 20);
        // bool output3 = (num1 == 10) && (num2 != 20);
        // bool output4 = (num1 != 10) && (num2 != 20);

        // bool output5 = (num1 == 10) || (num2 == 20);
        // bool output6 = (num1 != 10) || (num2 == 20);
        // bool output7 = (num1 == 10) || (num2 != 20);
        // bool output8 = (num1 != 10) || (num2 != 20);

        //삼항 연산자
        bool isStudent = true;
		bool isOldman = false;

		float discount = 0.0f;

		discount = (isStudent) ? 0.8f : 0.0f;
		cout << "value: " << 100 * discount << endl;

		isStudent = false;
		isOldman = true;
		discount = (isStudent) ? 0.8f : (isOldman) ? 0.6f : 0.0f;
		cout << "value: " << 100 * discount;

        cout << "num1 typeid name: " << typeid(num1).name() << endl;			// name() 은 일반적인 사용을 위한 명칭을 char* 

		cout << "char typeid name: " << typeid(char).name() << endl;			// name() 은 일반적인 사용을 위한 명칭을 char* 
		cout << "int typeid name: " << typeid(int).name() << endl;				// name() 은 일반적인 사용을 위한 명칭을 char* 
		cout << "long typeid name: " << typeid(long).name() << endl;			// name() 은 일반적인 사용을 위한 명칭을 char* 
		cout << "long long typeid name: " << typeid(long long).name() << endl;			// name() 은 일반적인 사용을 위한 명칭을 char* 
		cout << "double typeid name: " << typeid(double).name() << endl;			// name() 은 일반적인 사용을 위한 명칭을 char* 

    }

    {
        cin.clear(); //cin객체의 "내부 상태 플래그"를 초기화 => cin 관련 기능이 정상
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //입력 버퍼의 최대 크기만큼 무시

        int nKor = 0;
        int nEng = 0;
        int nMat = 0;
        int nTotal = 0;
        float fAvg = 0;
        float fNum = 3.0f;

        cout << "국어 점수 입력";
        cin >> nKor;
        cout << "영어 점수 입력";
        cin >> nEng;
        cout << "수학 점수 입력";
        cin >> nMat;

        nTotal = nKor + nEng + nMat;
        fAvg = nTotal / fNum;

        cout << "총점: " << nTotal << endl;
        cout << "평균: " << fAvg << endl;

    }
    {

        //bitwise operator 
        //&, |, ^, ~, <<, >> 
        //bool형 데이터에 사용하는 경우 효율적 - 메모리, 빠른 연산 속도, 네트워크에서 자주 사용 
        unsigned char x = 5; // 0000 0101 1byte
        unsigned char y = 1; // 0000 0001
        cout << "x: " << (int)x << " =>  2진수:" << bitset<8>(x) << endl;
        cout << "y: " << (int)y << " =>  2진수:" << bitset<8>(y) << endl;

        unsigned int result = 0;
        
        result = x >> 1;
        cout << " x >> 1 " << (int)result << bitset<8>(result) << endl;

        result = x << 1;
        cout << " x << 1 " << (int)result << bitset<8>(result) << endl;

        result = x & y;
        cout << "x & y = 10진수: " << (int)result << " =>  2진수:" << bitset<8>(result) << endl;

        result = x | y;
        cout << "x | y = 10진수: " << (int)result << " =>  2진수:" << bitset<8>(result) << endl;

        result = x ^ y;
        cout << "x ^ y = 10진수: " << (int)result << " =>  2진수:" << bitset<8>(result) << endl;

        result = ~x;
        cout << "~x = 10진수: " << (int)result << " =>  2진수:" << bitset<8>(result) << endl;

        result = ~y;
        cout << "~y = 10진수: " << (int)result << " =>  2진수:" << bitset<8>(result) << endl;

    }
    {
        int num = 102;
        if (num > 100)
            {
                cout << "num은 100보다 크다." << endl;
            }
            else if(num == 100)
            {
                cout << "num은 100이다." << endl;
            }
            else
            {
                cout << "num은 100보다 작다." << endl;
            }

            cout << "num: " << num << endl;
    }
    {
        int total = 30;
        int grade = total / 10;

        switch (grade)
        {
        case 9:
        case 8:
            cout << "A" << endl;
            break;

        case 7:
        case 6:
            cout << "B" << endl;
            break;

        case 5:
        case 4:
            cout << "C" << endl;
            break;

        default:
            cout << "F" << endl;
            break;
        }
    }
    {   
        int num = 0;
        do
        {
            cout << "num: " << num << endl;
            ++num;
        } while (num <= 5);
    
    //구구단
    for (int i = 2; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                cout << " " << i << "X" << j << "= " << (i * j);
            }
            cout << endl;
        }
    }

    {
        
        int correctNum = 38;
        int inputNum = -1;
        int nCount = 0;

        while(true)
        {
            cout << "== 숫자를 맞추어 보세요(1 ~ 100): 나가기는 0번 ==";
            cin >> inputNum;

            if(inputNum == 0 || nCount >= 10) break;

            if(correctNum == inputNum)
            {
                cout << "정답 입니다!!";
                break;
            }
            else if(correctNum > inputNum)
            {
                cout << "입력값이 작아요!!";
            }
            else
            {
                cout << "입력값이 커요!!";
            }

            cout << endl;
            nCount++;
            cout << "Count:" << nCount << endl;

        } //while

        cout << "\n프로그램 종료";
    }

    //Array 배열
    {
        const int ARRAY_NUM = 5;
        int arrayNums[ARRAY_NUM]; // 선언만 하고 초기화 하지 않으면, 모든 배열 요소에 디폴트값으로 초기화
        arrayNums[0] = 0;
        arrayNums[1] = 1;
        arrayNums[2] = 2;
        arrayNums[3] = 3;
        arrayNums[4] = 4; 

        //arrayNums[5] = 5; //에러없음!! 단, 런타임에 에러 발생!! 주의!!
        //배열에 값을 넣기(for문 이용)

        for (int i = 0; i < ARRAY_NUM; i++)
        {
            arrayNums[i] = i * 10;
        }
        
        
        //출력하기
        for (int i = 0; i < ARRAY_NUM; i++)
        {
            cout << "[" << i << "]: " << arrayNums[i] << endl;
        }

        int arrayNums1[5];
        int arrayNums2[4] = { 0, 1, 2, 3 };
        int arrayNums3[10] = { 100, }; //0번만 100으로 초기화, 나머지는 0으로..
        int arrayNums4[20] = { }; //모두다 0으로 초기화..
        int arrayNums5[] = {0, 1, 2, 3, 4 }; //arrayNums5[5]

        int length1 = sizeof(arrayNums1) / sizeof(int); //sizeof(arrayNums2[0]) 
        cout << "length1:  " << length1 << endl;
        //int size1 = std::size(arrayNums1);
        int length2 = sizeof(arrayNums2) / sizeof(arrayNums2[0]); //sizeof(int)

        // 데이터 복사
        int arrayOri[5] = { 0, 11, 22, 33, 44 };
        int arrayDest1[5];
        int arrayDest2[5];
        int arrayDest3[5];

        int length = sizeof(arrayOri) / sizeof(arrayOri[0]); //5
        for (int i = 0; i < length; i++)
        {
            arrayDest1[i] = arrayOri[i];
        }

        //int length2 = sizeof(arrayOri) / sizeof(arrayOri[0]);

        memcpy(arrayDest2, arrayOri, sizeof(arrayOri));

        int length3 = sizeof(arrayOri) / sizeof(arrayOri[0]);
        copy(arrayOri, arrayOri + length3, arrayDest3);

        //2차원 배열
        int ex_array[4];
        int mArrayNums1[2][4];
        int mrarayNums2[][3] = { {0, 11, 22}, {33, 44, 55}, {66, 77, 88} };


        cout << "1 차원 배열 " << sizeof(ex_array) << endl; // 16byte
        cout << "int 크기" << sizeof(int) << endl; //4byte

        cout << "다 차원 배열 " << sizeof(mArrayNums1) << endl; //32  8*4
        cout << sizeof(mArrayNums1[0]) << endl; //16  4*4
        cout << sizeof(mArrayNums1[0][0]) << endl; //4byte 
        int size_col = sizeof(mArrayNums1[0]) / sizeof(mArrayNums1[0][0]); // 16/4 = 4
        int size_row = (sizeof(mArrayNums1) / size_col) / sizeof(mArrayNums1[0][0]);   // (32/4) = 8 / 4 = 2
      
        cout << "sizeof(arrayNums1[0][0]): " << sizeof(mArrayNums1[0][0]) << endl; //4
        cout << "(sizeof(arrayNums1) / size_col): " << (sizeof(mArrayNums1) / size_col) << endl; //8

        int value = 0;

        cout << "size_row: " << size_row << "size_col: " << size_col << endl; // 2 4
        /*
        메모리 주소
                                            int arrNum[3][5]
                                        Address│   메모리
                                       ────────┼────────────────────
        arrNum[0]→→ arrNum[0][0] →→→    0x00  │
                                        0x01  │
                                        0x02  │      5
                                        0x03  │
                                        ────────┼────────────────────
                    arrNum[0][1] →→→    0x04  │
                                        0x05  │
                                        0x06  │      4
                                        0x07  │
                                        ────────┼────────────────────
                    arrNum[0][2] →→→    0x08  │
                                        0x09  │
                                        0x0A  │      3
                                        0x0B  │
                                        ────────┼────────────────────
                    arrNum[0][3] →→→    0x0C  │
                                        0x0D  │
                                        0x0E  │      2
                                        0x0F  │
                                        ────────┼────────────────────
                    arrNum[0][4] →→→    0x10  │
                                        0x11  │
                                        0x12  │      1
                                        0x13  │
                                        ────────┼────────────────────
        arrNum[1] →→ arrNum[1][0] →→→    0x14  │
                                        0x15  │
                                        0x16  │      6
                                        0x17  │
                                        ────────┼────────────────────
        */
    }
}