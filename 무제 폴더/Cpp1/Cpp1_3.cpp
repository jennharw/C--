#pragma warning(disable: 4996)

#include <cstdio>
#include <iostream>
#include <cfloat>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

//https://github.com/gitcmhan98/ExamCPlus/tree/master/FastCampus_C%2B%2B
//https://github.com/zsaladin/CppExamples/blob/master/Project/Cpp2_3_4/main.cpp#L163

int main()
{
    std::cout << "Hello World!\n";

    // main() 함수의 반환값. Exit code
    // 해당 프로그램이 종료 될 때 이 프로그램을 실행한 부모 프로그램에게 알려주는 값
    // 0으로 종료 코드를 넘겨주게 되면 정상 종료라고 알려줌
    // return 0;

    //ch02. 데이터
    int x = 1, y = 2, z = 3;
    
    cout << x << endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    
    int num0 = 1;
    int num1 = num0 * 1.5;
    cout << "num0 " << num0 << endl;
    cout << "num1 " << num1 << endl;

    //return 0;

    // int a;
    // std::cin >> a;

    int num10 = 11;
    int num8 = 011;
    int num2 = 0b11;
    int num16 = 0x11;

    cout << "num10 " << num10 << endl;
    cout << "num8 " << num8 << endl;
    cout << "num2 " << num2 << endl;
    cout << "num16 " << num16 << endl;

    // int 32bits

    int intNum = 0;
    long longNum = 0;
    int* intPointer = &intNum;

    cout << sizeof(intNum) << endl;
    cout << sizeof(longNum) << endl;
    cout << sizeof(intPointer) << endl;

    int8_t intNum8 = 0;
    int16_t intNum16 = 0;
    int32_t intNum32 = 0;
    // 어느 환경에서도 고정된 길이를 보장한다.

    cout << sizeof(intNum8) << endl;
    cout << sizeof(intNum16) << endl;
    cout << sizeof(intNum32) << endl;

    // 리터럴 접미사를 이용하여 정수형의 세부 타입을 표현
    int intNum_ = 11;
    unsigned int uintNum = 11u;
    cout << sizeof(intNum) << endl;
    long int longNum_ = 0L;
    long long longLongNum = 0LL;
    unsigned long long ulongLongNum = 0uLL;

    // unsigned의 최대값
    // char 형이기 때문에 cout이 숫자로 출력을 하지 않아 (int)로 형변환
    cout << (int)numeric_limits<uint8_t>::max() << endl;
    cout << numeric_limits<uint16_t>::max() << endl;
    cout << numeric_limits<uint32_t>::max() << endl;
        cout << numeric_limits<uint64_t>::max() << endl;
  
    // signed의 최대값
    cout << (int)numeric_limits<int8_t>::max() << endl;
    cout << numeric_limits<int16_t>::max() << endl;
    cout << numeric_limits<int32_t>::max() << endl;
    cout << numeric_limits<int64_t>::max() << endl;

    // signed의 최소값
    cout << (int)numeric_limits<int8_t>::min() << endl;
    cout << numeric_limits<int16_t>::min() << endl;
    cout << numeric_limits<int32_t>::min() << endl;
    cout << numeric_limits<int64_t>::min() << endl;

    // unsigned overflow
    uint32_t unum32 = numeric_limits<uint32_t>::max();
    uint32_t unum32_ = unum32 + 1; // Overflow

    cout << unum32 << endl;  // 4294967295
    cout << unum32_ << endl; // 0, Overflow

    // signed overflow
    int32_t num32 = numeric_limits<int32_t>::max();
    int32_t num32_ = num32 + 1; // Overflow

    cout << num32 << endl;  // 2147483647
    cout << num32_ << endl; // -2147483648, Overflow

    // unsigned underflow
    uint32_t min_unum32 = numeric_limits<uint32_t>::min();
    uint32_t uf_unum32_ = unum32 - 1; // Underflow

    cout << min_unum32 << endl;  // 0
    cout << uf_unum32_ << endl; // 4294967295, Underflow 

    // signed underflow
    int32_t min_num32 = numeric_limits<int32_t>::min();
    int32_t uf_num32_ = num32 - 1; // Underflow

    // cout << min_num32 << endl;  // -2147483648
    // cout << uf_num32_ << endl; // 2147483647, Underflow

    //부동 소수점
    float fnum = 1.0;
    double dnum = 1.0;
    long double ldnum = 1.0;

    // float은 4바이트, double은 8바이트(대부분)
    // 환경에 따라 사이즈가 다를 수 있음(특히 long double)
    cout << "float : " << sizeof(fnum) << endl;  // 4
    cout << "double : " << sizeof(dnum) << endl;  // 8
    cout << "long double : " << sizeof(ldnum) << endl; // 8

    // 리터럴에 어떤 접미사를 붙이는 가에 따라 세부 자료형을 정할 수 있다 
    cout << "sizeof(1.0f) : " << sizeof(1.0f) << endl; // float
    cout << "sizeof(1.0) : " << sizeof(1.0) << endl;  // double
    cout << "sizeof(1.0L) : " << sizeof(1.0L) << endl; // long double

    // 정밀도 변경
    cout.precision(64);
    unsigned int num0_layout;
    float num1f = -118.625;
    memcpy(&num0, &num1, sizeof(num1));
    cout << num0_layout << endl;
    cout << num1f << endl; //memory layout
    
    float fnumf = 0.231689453125f;
    memcpy(&uintNum, &fnum, sizeof(fnum));

    cout << uintNum << endl; // 0011,1110,0110,1101,0100,0000,0000,0000 = 1047347200
    cout << fnumf << endl;  

    {
        //부동소수점 비교 연산시 문제점
        float num0 = 0.1f;
        float num1 = 0.02 * 5.0f;

        if (num0 == num1)
            cout << "Equal 1" << endl; // 실행이 안 된다.
        if (num0 == 0.1f)
            cout << "Equal 2" << endl; // 실행이 된다.
        if (num0 == 0.1)
            cout << "Equal 3" << endl; // 실행이 안 된다.
        if (num0 == 0.1L)
            cout << "Equal 4" << endl; // 실행이 안 된다.
        
        cout << num0 << endl; // 실제로 0.1 이 아니다.
        cout << num1 << endl; // 실제로 0.1 이 아니다.

        cout << "0.1f : " << 0.1f << endl;
        cout << "0.1  : " << 0.1 << endl;
        cout << "0.1L : " << 0.1L << endl;

        num0 = 1.0f;
        num1 = 0.0f;
        for (int i = 0; i < 1000; i++)
            num1 = num1 + 0.001;
        if (num0 == num1)
            cout << "Equal 0" << endl;  // 안 됨
        // if (fabsf(num0 - num1) <= FLT_EPSILON)
        //     cout << "Equal 1" << endl;  // 안 됨


        num0 = 1.0f;
        num1 = 0.0f;
        for (int i = 0; i < 10; i++)
            num1 = num1 + 0.1;
        if (num0 == num1)
            cout << "Equal 2" << endl;  // 안 됨
        // // if (fabsf(num0 - num1) <= FLT_EPSILON)
        // //     cout << "Equal 3" << endl;  // 됨

        // //Epsilon 유도
        unsigned int intNum0 = 0b00111111100000000000000000000000;
        float fNum0;
        memcpy(&fNum0, &intNum0, sizeof(intNum0));
        cout << fNum0 << endl;

        unsigned int intNum1 = 0b00111111100000000000000000000001;
        float fNum1;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));
        cout << fNum1 << endl; // 1.00000011920928955078125f, float이 표현할 수 있는 1보다 큰, 가장 작은 수

        float epsilon = fNum1 - fNum0;
        cout << epsilon << endl;
        cout << FLT_EPSILON << endl;

    }

    {   
        cout << "------------------" << endl;
   

        // 1.0f에서 더할 수 있는 가장 작은 수 구하기
        float fNum0 = 1.0f; //memory layout 0011,1111,1000,0000,0000,0000,0000,0000 = 1.0(2)
        //0011,0100,0000,0000,0000,0000,0000,0000) 127-23=104, 1.0(2) * 10^-23(2) 1.0f 에서 더할 수 있는 가장 작은수
        float fNum1;
        unsigned int intNum1 = 0b00110100000000000000000000000000; //Epsilon
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); 

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나옴

        // 1.0f 에서 더할 수 있는 가장 작은수보다 더 작은 수를 더할때
        unsigned int intNum2 = 0b00110011100000000000000000000000; // 1.0(2) * 10^-24(2)
        memcpy(&fNum1, &intNum2, sizeof(intNum2)); 
        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나오지 않음

        // 1.0f를 더했을 때 문제가 없이 더해지는 수
        unsigned int intNum3 = 0b01001011000000000000000000000000;
        memcpy(&fNum1, &intNum3, sizeof(intNum3)); // 1.0(2) * 10^23(2), 127+23=150
        //0100 1011 0000 00000000000000000000

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나옴

        // 1.0f를 더했을 때 더해지지 않는 수
        unsigned int intNum4 = 0b01001011100000000000000000000000;
        memcpy(&fNum1, &intNum4, sizeof(intNum4)); // 1.0(2) * 10^24(2)
        //0100 1011 1000 00000000000000000000

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나오지 않음
        //정밀한 연산을 위해서는 고정소수점사용, library나 정수형, 부정소수점 보다는

    }

    {
        // 최대값 구하기
        // NaN 구하기
        float fnum;
        unsigned int uintNum = 0b01111111111111111111111111111111; //지수부 bit가 모두 켜져있는 경우
        memcpy(&fnum, &uintNum, sizeof(uintNum));
        // 무한대 구하기
        unsigned int inf_uintNum = 0b01111111100000000000000000000000;
        memcpy(&fnum, &inf_uintNum, sizeof(inf_uintNum));

        unsigned int max_uintNum = 0b01111111011111111111111111111111; //254 10**1
        memcpy(&fnum, &max_uintNum, sizeof(max_uintNum));

        cout << FLT_MAX << endl;
        cout << fnum << endl;

        // MIN, -FLT_MAX
        float min_fnum;
        //0000 0000 1000 0000 0000 0000 0000 0000
        unsigned int min_uintNum = 0b00000000100000000000000000000000; // 0 10^-126 
        memcpy(&min_fnum, &min_uintNum, sizeof(min_uintNum));

        cout << FLT_MIN << endl;
        cout << min_fnum << endl;

        // TRUE_MIN  가장 작은 절대값
        //0000 0000 0000 0000 0000 0000 0000 0001 10^-127이 아니라 10^-126(2) 
        // 가수부 1.0 이 아니라 0.000 0000 0000 0000 0000 0001(2)
        // 10^-126(2) * 10^-23(2) = 10^-149(2)
        float true_fnum;
        unsigned int true_uintNum = 0b00000000000000000000000000000001;
        memcpy(&true_fnum, &true_uintNum, sizeof(true_uintNum));

        cout << FLT_TRUE_MIN << endl;
        cout << true_fnum << endl;
    }

   
    
    cout << "------------------" << endl;
    {
        printf("%d + %d = %i\n", 2, 3, 2 + 3); // signed int 10진수 출력

        printf("%u + %u = %u\n", 3, 2, 3 + 2); // unsigned int 10진수 출력

        // unsigned int 10진수 출력 형식으로 음수 int 출력
        printf("%u\n", -1);
        // unsigned char 10진수 출력 형식으로 음수 int 출력
        printf("%hhu\n", -1);
        // 부동소수점 출력(%f, %lf 같음)
        printf("%f - %f = %lf\n", 2.0, 3.0f, -1.0f);

        // char 출력
        char ch = 'b';
        printf("%c%c\n", 'a', ch);

        
        // unsigned int 8, 16진수 출력
        printf("%o, %x, %X\n", 10, 10, 10);
        // unsigned char 16진수 출력
        printf("%hhx\n", 255);
        // unsigned char 16진수 출력(overflow)
        printf("%hhx\n", 256);
        // 앞에 0을 채워 총 10글자로 맞추기
        printf("%010d\n", 1);
        printf("%010d\n", -1);
        printf("%010f\n", 1.1);
        printf("%010f\n", -1.1);

        // 소수점 자리수 표현
        printf("%010.1f\n", 1.1);
        printf("%010.1f\n", -1.1);

        // 앞에 여백을 넣기
        printf("%10d\n", 1);
        printf("%10d\n", -1);
        printf("%10f\n", 1.1);
        printf("%10f\n", -1.1);

        // 뒤에 여백을 넣기
        printf("%-10d\n", 1);
        printf("%-10d\n", -1);
        printf("%-10f\n", 1.1);
        printf("%-10f\n", -1.1);

        // % 출력하기
        printf("%%\n");

        // stdout을 output.txt로 연결
        // freopen("output.txt", "w", stdout);
        // printf("Hello World!");

    }

    cout << "------------------" << endl;

    {
        // // 정수 입력
        // int num = 0;
        // scanf("%d", &num); // num 앞에 & 를 넣어줘야 한다.
        // printf("%d\n", num);

        // // 문자 입력
        // int num1;
        // char ch;
        // int n = scanf("%d %c", &num1, &ch); // 성공적으로 입력 받은 변수의 개수를 반환한다.
        // printf("%d\n", n);

        // // num 제대로 입력 받은 경우만 출력을 해준다.
        // int num2;
        // if (scanf("%d", &num2)) // 제대로 입력 받은 경우 1이 반환되고 1은 true 형변환이 된다.
        //     printf("%d\n", num2);

        // int num0, num3, num4;
        // scanf("%d + %d = %d", &num0, &num3, &num4); // 형식에 맞춰서 입력을 해줘야 한다. ex) "1 + 1 = 2"
        // printf("%d + %d = %d\n", num0, num3, num4);

        // 접미사(0x, 0)을 넣어 주면 16진수, 8진수로 입력을 받을 수 있음
        // int num5;
        // scanf("%i", &num5);
        // printf("%i\n", num5);

        // 문자형 입력
        // char ch;
        // scanf("%c", &ch);
        // printf("%c\n", ch);
        // printf("%d\n", ch);

        // // 부동소수점 입력, scanf에서는 %f float, %lf double
        // float f0;
        // double d0, d1;
        // scanf("%lf %lf %f", &d0, &d1, &f0);
        // printf("%lf %lf %f", d0, d1, f0);

        // // 8진수 입력
        // int num;
        // scanf("%o", &num);
        // printf("%d\n", num);

        // // scanf 오류 처리
        // char ch;
        // scanf("%c", &ch);
        // printf("1, %c\n", ch);

        // while (getchar() != '\n');

        // scanf("%c", &ch);
        // printf("2, %c\n", ch);

        // stdin 을 input.txt에 연결
        // int num;
        // freopen("input.txt", "r", stdin);
        // scanf("%d", &num);
    }
    cout << "------------------" << endl; //입출력

    {
        cout << 1 << endl;
        cout.operator<<(1).operator<<(endl); // 위와 동일(연산자 오버로딩, 추후 배움)

        cout << '1' << endl;
        operator<<(cout, '1').operator<<(endl); // 위와 동일(연산자 오버로딩, 추후 배움)
    }
    {
        cout << 'a' << 'b' << endl;
        cout.put('a').put('b').put('\n');
        cout.write("ab\n", 3);
    }
    {
        // 10칸 여백
        cout.width(10);
        cout << 1 << endl;
    }
    {
        // 10칸을 여백
        cout.width(10);
        // 여백에 공백 문자 대신 '#'을 넣어준다.
        cout.fill('#');
        cout << 1 << endl;
        // '#'이 었던 것을 원상 복구
        cout.fill(' ');
    }

    {
        float num = 0.1234567;

        // 정밀도 조절 없이 출력
        cout << num << endl;

        // 정밀도 조절
        cout.precision(2);
        cout << num << endl;

        // 정밀도 조절
        cout.precision(64);
        cout << num << endl;
    }
    {
        // 양수에 + 기호를 표시하게 한다.
        cout.setf(ios_base::showpos);
        cout << 1 << endl;
        cout << 2 << endl;

        // 양수에 + 기호 표시를 하지 않게 한다.
        cout.unsetf(ios_base::showpos);
        cout << 1 << endl;
        cout << 2 << endl;
    }
    {
        // bool 값을 true/false로 출력하게 한다.
        cout.setf(ios_base::boolalpha);
        cout << true << endl;
        cout << false << endl;

        // bool 값을 1/0으로 출력하게 한다.
        cout.unsetf(ios_base::boolalpha);
        cout << true << endl;
        cout << false << endl;
    }
    {
        // 부호와 숫자를 양 끝에 배치한다.
        cout.setf(ios_base::internal, ios_base::adjustfield);
        cout.width(10);
        cout << -10 << 20 << endl;

        // 왼쪽 정렬한다.
        cout.setf(ios_base::left, ios_base::adjustfield);
        cout.width(10);
        cout << -10 << 20 << endl;

        // 오른쪽 정렬한다.
        cout.setf(ios_base::right, ios_base::adjustfield);
        cout.width(10);
        cout << -10 << 20 << endl;
    }
    {
        // 8진수로 출력한다.
        cout.setf(ios_base::oct, ios_base::basefield);
        cout << 16 << endl;

        // 16진수로 출력한다.
        cout.setf(ios_base::hex, ios_base::basefield);
        cout << 16 << endl;

        // 10진수로 출력한다.
        cout.setf(ios_base::dec, ios_base::basefield);
        cout << 16 << endl;
    }
    {
        // 16진수, 8진수, 10진수 출력을 다른 방식으로 표현
        cout << hex << 16 << endl;
        cout << oct << 8 << endl;
        cout << dec << 10 << endl;

        // hex는 함수이다.
        hex(cout);
        cout << 16 << endl;

        // oct는 함수이다.
        oct(cout);
        cout << 8 << endl;

        // dec는 함수이다.
        dec(cout);
        cout << 10 << endl;
    }
    {
        // << 을 이용하여 기존에 사용했던 것들을 표현 
        cout << setw(10) << setfill('#') << setprecision(2) << showpos << 1.1f << endl;
    }
    // {
    //     // stdout를 output.txt 파일로 출력
    //     freopen("output.txt", "w", stdout);
    //     cout << "Hello World" << endl;
    // }


    cout << "------------------" << endl;

    // {
    //     // 정수 입력
    //     int num;
    //     cin >> num;
    //     cout << num << endl;
    // }
    // {
    //     // 입력이 성공했을 때만 출력
    //     // 10 입력 성공
    //     // a  입력 실패
    //     int num;
    //     if (cin >> num)
    //         cout << num << endl;
    // }
    // {
    //     // 입력 실패 처리
    //     int num;
    //     cin >> num;
    //     cout << num << endl;

    //     // 입력이 실패했을 경우 초기화 시켜준다.
    //     if (cin.fail())
    //         cin.clear();

    //     // 버퍼에 남은 문자 한 개를 무시
    //     // cin.ignore();

    //     // 개행 문자가 나올 때까지 무시한다.
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //     cin >> num;
    //     cout << num << endl;
    //     cout << num << endl;
    // }
    // {
    //     // bool 입력을 1/0로 받기
    //     bool b;
    //     cin >> b;
    //     cout << b << endl;

    //     // bool 입력을 true/false로 받기
    //     cin.setf(ios_base::boolalpha);
    //     cin >> b;
    //     cout << b << endl;
    // }
    // {
    //     // 16 진수로 입력 받기
    //     int num;
    //     cin.setf(ios_base::hex, ios_base::basefield);
    //     cin >> num;
    //     cout << num << endl;

    //     cin >> hex >> num;
    //     cout << num << endl;
    // }
    // {
    //     freopen("input.txt", "r", stdin);

    //     int num;
    //     cin >> num;
    //     cout << num << endl;
    // }

    cout << "------------------" << endl;

    // 문자와 정수의 관계
    char ch = 'a';
    cout << ch << endl;

    char ch0 = 'a';
    char ch1 = 97;

    cout << "ch0 : " << ch0 << endl; // a
    cout << "ch1 : " << ch1 << endl; // a

    cout << "ch0 : " << (int)ch0 << endl; // 97
    cout << "ch1 : " << int(ch1) << endl; // 97

    // 같은 값이지만 어떤 타입으로 넘기는 지에 따라 다르게 출력
    cout << (char)97 << endl; // a
    cout << 97 << endl; // 97


    // MultiCharacter Literal - 사용 주의, 표준이 아님
    char ch_m = 'ab';
    int num = 'ab';

    cout << ch_m << endl;
    cout << num << endl;  

    // bool 선언 및 출력
    bool b0 = 0 == 0;
    bool b1 = 0 < 1;
    bool b2 = 0 > 1;

    cout << "b0 : " << b0 << endl;
    cout << "b1 : " << b1 << endl;
    cout << "b2 : " << b2 << endl;

    cout << "------------------" << endl; //연산자
    {
        // 연산자의 우선 순위
        // "/" 연산자가 "-" 연산자보다 우선 순위가 높아 먼저 계산 된다.
        int num = 40 - 32 / 2;
        cout << num << endl;
    }
    {
        // 연산자의 결합성
        // 우선순위가 같은 연산자들끼리는 결합성의 방향에 따라 계산을 한다.
        // 8 / 2 / 2 * 2 -> 나눗셈, 곱셈은 우선순위가 같고 결합성은 왼쪽에서 오른쪽
        // 4 - 6 + 2 + 8 -> 뺄셈, 덧셈은 우선순위가 같고 결합성은 왼쪽에서 오른쪽
        int num = 4 - 6 + 2 + 8 / 2 / 2 * 2;
        cout << num << endl;

        int a, b, c;
        // 할당 연산자는 결합성이 오른쪽에서 왼쪽. 할당 후 할당 된 값을 반환한다.
        a = b = c = 10;

        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
    }
    {
        // 선언문에서 '=' 는 할당 연산자가 아님
        int num = 10;
    }
    {
        // 정수형 리터럴에 '-'를 붙임. 
        // 뺄셈의 '-'는 이항 연산자
        // 수의 부호를 바꿔주는 '-'는 단항 연산자
        cout << -1 << endl;
        cout << +-+-+-1 << endl;
    }
    {
        int num = 0;
        // 전위 증가 연산자. 해당 변수에 1을 더하고 더한 값을 반환
        cout << ++num << endl;
        // 전위 감소 연산자. 해당 변수에 1을 빼고 뺀 값을 반환
        cout << --num << endl;
        // 후위 증가 연산자. 해당 변수에 1을 더하고 더하지 않은 원래 값을 반환
        cout << num++ << endl;
        // 후위 감소 연산자. 해당 변수에 1을 빼고 빼지 않은 원래 값을 반환
        cout << num-- << endl;
    }
    {
        // 복합 할당 연산자
        int num = 10;
        
        // 좌항의 변수에 우항의 값을 더한 결과를 좌항에 할당
        num += 5;
        cout << num << endl;

        // 좌항의 변수에 우항의 값을 뺀 결과를 좌항에 할당
        num -= 5;
        cout << num << endl;

        // 좌항의 변수에 우항의 값을 곱한 결과를 좌항에 할당
        num *= 5;
        cout << num << endl;

        // 좌항의 변수를 우항의 값으로 나눈 결과를 좌항에 할당
        num /= 5;
        cout << num << endl;

        // 좌항의 변수를 우항의 값으로 나누고 남은 나머지를 좌항에 할당
        num %= 5;
        cout << num << endl;
    }
    {
        // 정의되지 않은 행동
        // 시퀀스 포인트 이전에 같은 변수를 변경하는 행동은 주의
        // 세미콜론은 대표적인 시퀀스 포인트
        int num = 10;
        cout << ++num + num++ << endl; // 정의되지 않은 행동
        cout << num << endl;

        printf("%d %d\n", ++num, ++num); // 정의되지 않은 행동
        printf("%d\n", num);
    }

{
        // Equal 연산자
        int num0 = 10, num1(10);
        if (num0 == num1)
            cout << "num0 == num1" << endl;
        
        // 아래의 실수들에 유의 한다.
        num0 = 10, num1 = 11;
        // if 문 내부가 11로 평가되고 11은 true로 평가되기 때문에 num0과 num1이 달라도 무조건 실행이 된다.
        if (num0 = num1)
            cout << "num0(10) = num1(11)" << endl;

        num0 = 0, num1 = 0;
        // if 문 내부가 0으로 평가되고 0은 false로 평가되기 때문에 num0과 num1이 같아도 실행이 안 된다.
        if (num0 = num1)
            cout << "num0(0) = num1(0)" << endl;
    }
    {
        // Not Equal 연산자
        int num0 = 0, num1(0);
        if (num0 != num1)
            cout << "num0(0) != num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 != num1)
            cout << "num0(0) != num1(1)" << endl;
    }
    {
        // > 연산자
        int num0 = 0, num1(0);
        if (num0 > num1)
            cout << "num0(0) > num1(0)" << endl;

        num0 = 1, num1 = 0;
        if (num0 > num1)
            cout << "num0(1) > num1(0)" << endl;
    }
    {
        // >= 연산자
        int num0 = 0, num1(0);
        if (num0 >= num1)
            cout << "num0(0) >= num1(0)" << endl;

        num0 = 1, num1 = 0;
        if (num0 >= num1)
            cout << "num0(1) >= num1(0)" << endl;
    }
    {
        // < 연산자
        int num0 = 0, num1(0);
        if (num0 < num1)
            cout << "num0(0) < num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 < num1)
            cout << "num0(0) < num1(1)" << endl;
    }
    {
        // <= 연산자
        int num0 = 0, num1(0);
        if (num0 <= num1)
            cout << "num0(0) <= num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 <= num1)
            cout << "num0(1) <= num1(0)" << endl;
    }
    {
        // SpaceShip 연산자
        // C++2x 에서 지원. 프로젝트 속성에서 C++ 언어 표준 변경
        cout.setf(ios_base::boolalpha);

        // <=> 의 결과를 0과 비교할 수 있다.
        // 0과 비교해서 0과 같으면 <=>의 좌항, 우항이 같다.
        // 0과 비교해서 0보다 크면 좌항이 우항보다 크다.
        // 0과 비교해서 0보다 작으면 좌항이 우항보다 작다.
        // cout << ((1 <=> 1) == 0) << endl;
        // cout << ((2 <=> 1) > 0) << endl;
        // cout << ((1 <=> 2) < 0) << endl;

        // cout << is_eq(1 <=> 1) << endl;
        // cout << is_gt(2 <=> 1) << endl;
        // cout << is_lt(1 <=> 2) << endl;
        // cout << is_gteq(2 <=> 1) << endl;
        // cout << is_lteq(1 <=> 2) << endl;

        // cout << typeid(1 <=> 1).name() << endl;
        // cout << typeid(1 <=> 1.0).name() << endl;
    }

    // 연산자 우선순위 Operators in C++
//     //할당연산자 right-to-left;
//     int a(10);
//     ++a;
//     int num = 0;
//     cout << --num;
//     // 할당이 아니라 초기화
//     단항연산자 이항연산자 
//     -+-1 righttoleft 
//     ;
//     ++1; // 변수 앞에 , literal 앞에 안돼
//     //전이 , 후이  
//     ++a;

//     한 식에서 변수를 두번이상 변경할 때 주의해야 함
//     undefined behavior 
//     sequence pointer(;) 가 다름 ; 안에서

// //     비교연산자 
// //      = ; 는 true 유의해야 할당연산자 11 -> 0이 아니면 true 
// //       // SpaceShip 연산자
// //         // C++2x 에서 지원. 프로젝트 속성에서 C++ 언어 표준 변경
// //     cout.setf(ios_base::boolalpha);

    // <=> 의 결과를 0과 비교할 수 있다.
    // 0과 비교해서 0과 같으면 <=>의 좌항, 우항이 같다.
    // 0과 비교해서 0보다 크면 좌항이 우항보다 크다.
    // 0과 비교해서 0보다 작으면 좌항이 우항보다 작다.
    
    // cout << ((1 <=> 1) == 0) << endl;
    // cout << ((2 <=> 1) > 0) << endl;
    // cout << ((1 <=> 2) < 0) << endl;

    // cout << is_eq(1 <=> 1) << endl;
    // cout << is_gt(2 <=> 1) << endl;
    // cout << is_lt(1 <=> 2) << endl; // less than
    // cout << is_gteq(2 <=> 1) << endl; // 작냐 
    // cout << is_lteq(1 <=> 2) << endl;

    // cout << typeid(1 <=> 1).name() << endl; // strong_ordeinrg equal
    // cout << typeid(1 <=> 1.0).name() << endl;// partial ordering equivalent 


//     논리 연산자
        // AND 연산자(&&)
        // true && true == true
        // true && false == false
        // false && true == false
        // false && false == false
        // OR 연산자(||)
        // true && true == true
        // true && false == true
        // false && true == true
        // false && false == false
        // &&, || 연산자는 시퀀스 포인트
    {
        int num0 = 10, num1(10);
        int num2 = 20, num3(30);
        if (num0 == num1 && num2 != num3) // == 연산자가 &&보다 우선 순위가 높다
            cout << "!!!!" << endl;
        if (num0 == num1 && num2 == num3)
            cout << "@@@@" << endl;
    }
    {
        int num0 = 10, num1(10);
        int num2 = 20, num3(30);
        if (num0 == num1 && num2 == num3)
            cout << "AND" << endl;
        if (num0 == num1 || num2 == num3) //앞에 true 나오면 뒤에 연산 하지 않음 
            cout << "OR" << endl;

        bool result =  (printf("") && printf("ABC")); // && 앞에 false 나오면 뒤에 연산하지 않음
        bool result1 =  (printf("1") && printf("ABC")); //sequence point || && 이항연산자 2개 받음
    }
    {
        // && 연산자가 || 연산자보다 우선순위가 높다.
        if (true || false && false) //s
            cout << "OK" << endl;
    }

    {
        // short-circuit evaluation
        int num0 = 10, num1(20);
        int num2 = 20, num3(20);
        
        // num0 == num1 이 false이기 때문에 num2 == num3은 평가할 필요가 없어서 평가되지 않는다.
        if (num0 == num1 && num2 == num3)
            cout << "AND" << endl;
        
        // num0 != num1 이 true이기 때문에 num2 == num3은 평가할 필요가 없어서 평가되지 않는다.
        if (num0 != num1 || num2 == num3)
            cout << "OR" << endl;

        // printf("") 의 반환값이 0이기 때문에 false로 평가돼서 우항의 printf("ABC")는 실행되지 않는다.
        printf("") && printf("ABC");
        cout << endl;

        // printf("a") 의 반환값이 1이기 때문에 true로 평가돼서 우항의 printf("ABC")는 실행된다.
        printf("a") && printf("ABC");
        cout << endl;

        // printf("a") 의 반환값이 1이기 때문에 true로 평가돼서 우항의 printf("ABC")는 실행되지 않는다.
        printf("a") || printf("ABC");
        cout << endl;

        // printf("") 의 반환값이 0이기 때문에 false로 평가돼서 우항의 printf("ABC")는 실행된다.
        printf("") || printf("ABC");
        cout << endl;
    }

    {
        // Not 연산자(!)
        bool r = true;
        r = !r;
        cout << r << endl;
    }
    {
        // 같은 의미의 if 문
        int num0 = 10, num1 = 20;
        if (num0 != num1)
        {
            cout << "num0 != num1" << endl;
        }
        if (!(num0 == num1))
        {
            cout << "!(num0 == num1)" << endl;
        }
    }
    {
        cout.setf(ios_base::boolalpha);
        
        // 10이 bool로 평가 될  true 평가 되어서 false 출력
        cout << !10 << endl;

        // 좌항과 우항의 정수가 둘 다 0이 아니기 때문에 둘 다 true로 평가되어 true && true 가 된다.
        cout << (1 && 2) << endl;
    }

//         // Not 연산자(~)
//         // 0 -> 1
//         // 1 -> 0

    {
        // 0000,0000,0000,0000,0000,0000,0000,0000 (0) 32bit
        int num = 0;

        // 1111,1111,1111,1111,1111,1111,1111,1111 (-1) 
        //2의 보수 000...00001
        cout << ~num << endl;
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0000 (0)
        unsigned int num = 0;

        // 1111,1111,1111,1111,1111,1111,1111,1111 (2^32 - 1)
        cout << ~num << endl;
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0001 (1)
        unsigned int num = 1;

        // 1111,1111,1111,1111,1111,1111,1111,1110 (2^32 - 2)
        cout << ~num << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0001 (1)
        cout << ~~num << endl; // right to left
    }

        // AND 연산자(&)
        // 1 & 1 == 1
        // 1 & 0 == 0
        // 0 & 1 == 0
        // 0 & 0 == 0
    {
        int num0 = 5;
        int num1 = 10;

        int result = num0 & num1;
        cout << result << endl;

        // 0000,0101 == 5 == 4 + 1 == 2^2 + 2^0
        // 0000,1010 == 10 == 8 + 2 == 2^3 + 2^1
        // 0000,0000 == 0
    }
    {
        int num0 = 5;
        int num1 = 11;

        int result = num0 & num1;
        cout << result << endl;

        // 0000,0101 == 5 == 4 + 1 == 2^2 + 2^0
        // 0000,1011 == 10 == 8 + 2 == 2^3 + 2^1 + 2^0
        // 0000,0001 == 1
    }

    cout << "---------AttendanceBook---------" << endl; //

    {
        //bool isPresent[31]  1byte(8bit) * 31 = 255, 메모리 
         
        // AND 연산자를 이용하여 flag가 존재하는지 체크
        // 상태로 compact 하게 나타낼 수 있음
        uint32_t attendanceBook = 5u; //4byte 32bit
        // 00000000 00000000 00000000 00000101 출석

        //(attendanceBook & 4 == 4) 
        //pow double 형 -> int 
        if (attendanceBook & (int)pow(2, 0)) 
            cout << "1st" << endl;

        if (attendanceBook & (int)pow(2, 1))
            cout << "2nd" << endl;

        if (attendanceBook & (int)pow(2, 2))
            cout << "3th" << endl;

        if (attendanceBook & ((int)pow(2, 0) + (int)pow(2, 1)))
            cout << "1 or 2" << endl;

        int flag = (int)pow(2, 0) + (int)pow(2, 2);
        
        if ((attendanceBook & flag) == flag) 
            cout << "1 and 3" << endl;

        //두개 다 나와야

        // 0000,0000,0000,0000,0000,0000,0000,0101 = 5

        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 AND // 1일 체크
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 // 1일 출석

        // 0000,0000,0000,0000,0000,0000,0000,0010 = 1 AND // 2일 체크
        // 0000,0000,0000,0000,0000,0000,0000,0000 = 0 // 2일 결석

        // //결석처리하기
        // uint32_t attendanceBook = 7u;
        // attendanceBook &= 0;
    }
        // OR 연산자(|)
        // 1 | 1 == 1
        // 1 | 0 == 1
        // 0 | 1 == 1
        // 0 | 0 == 0
    {
        // OR 연산자를 이용하여 flag를 추가
        uint32_t attendanceBook = 0u;

        // 첫째 날 출석 처리 ; 첫째날 출석이 아닐 때 + 1
        if (!(attendanceBook & (int)pow(2,0)))
            attendanceBook += (int)pow(2,0);
        //그런데 1, 3 날 출석처리?... 

        attendanceBook |= (int)pow(2, 0);
        cout << attendanceBook << endl;

        // 중복해서 같은 날에 출석을 해도 문제가 없다.
        attendanceBook |= ((int)pow(2, 0) + (int)pow(2,2));
        cout << attendanceBook << endl; 

        // 0000,0000,0000,0000,0000,0000,0000,0000 = 0
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 OR // 1일 출석
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1
    }
    {
        uint32_t attendanceBook = 5u;

        // 셋째 날 결석 처리 + , - 안 됨
        attendanceBook &= ~((int)pow(2, 2));

        // 0000,0000,0000,0000,0000,0000,0000,0101 = 5
        // 1111,1111,1111,1111,1111,1111,1111,1011 AND
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1

        attendanceBook &= ~((int)pow(2, 2) | (int)pow(2,0));

    }
        // XOR 같으면 false 0, 다르면 true 1
        // 1 ^ 1 == 0
        // 1 ^ 0 == 1
        // 0 ^ 1 == 1
        // 0 ^ 0 == 0
    {
        int num0 = 5;
        int num1 = 10;

        cout << (num0 ^ num1) << endl;

        // 0000,0101 = 5
        // 0000,1010 = 10
        // 0000,1111 = 15
    }
    {
        // XOR 를 이용하여 출석/결석 토글
        uint32_t attendanceBook = 0u;

        attendanceBook ^= (int)pow(2, 0); // 0001
        cout << attendanceBook << endl;

        attendanceBook ^= (int)pow(2, 0); // 0001 ^ 0001 == 0000
        cout << attendanceBook << endl;

        attendanceBook ^= (int)pow(2, 0); // 0000 ^ 0001 == 0001
        cout << attendanceBook << endl;
    }
    {
        // 홀수번 있는 단 한개의 수를 구하기
        int a = 1, b = 3, c = 2, d = 1, e = 2;
        cout << (a ^ b ^ c ^ d ^ e) << endl;
        cout << (a ^ d ^ c ^ e ^ b) << endl; // 교환 법칙
    }
    {
        // << 연산자
        // 0000,0001
        // 0000,1000
        cout << (1 << 3) << endl;
        // << 한 번 할 때 마다 2배
        cout << (1 << 0) << endl;
        cout << (1 << 1) << endl;
        cout << (1 << 2) << endl;
        cout << (1 << 3) << endl;

        // 값의 잘림(오버 플로우)
        int num = 2200000000;
        num <<= 2;

        cout << num << endl;

        // pow 연산을 사용하지 않고 출석 처리
        int attendanceBook = 0u;
        attendanceBook |= (1 << 2);
        cout << attendanceBook << endl;
    }
    {
        // >> 연산자
        // 값의 잘림(언더 플로우)
        cout << (1 >> 1) << endl;

        
        // >> 한 번 할 때 마다 절반
        cout << (16 >> 1) << endl;
        cout << (8 >> 1) << endl;
        cout << (4 >> 1) << endl;
        cout << (2 >> 1) << endl;
        cout << (1 >> 1) << endl;


        cout << (14 >> 1) << endl; // 7
        cout << (15 >> 1) << endl; // 7 잘려서 나머지 없어짐

        cout << (14 >> 2) << endl; // 3 잘려서 나머지 없어짐
        cout << (15 >> 2) << endl;
        
    }

    {
        // 삼항 연산자
        // (A) ? (B) : (C)
        // A가 true면 B 실행 후 리턴
        // A가 false면 C 실행 후 리턴

        // 절대값 구하기
        int num = -10;
        int abs = num < 0 ? -num : num;


        num = 0;
        (num == 0 ? (cout << "num == 0") : (cout << "num != 0")) << endl;
        cout << (num == 0 ? "num == 0" : "num != 0") << endl;

        // 1과 "num != 0"이 호환이 안 되는 타입이라 삼항 연산자를 사용할 수 없음
        // num == 0 ? 1 : "num != 0";
    }
    {
        // sizeof 연산자
        int num = 0;
        cout << sizeof(num) << endl;
        cout << sizeof num << endl;
        cout << sizeof(int) << endl;
    }
    {
        // 범위 지정 연산자 (::)
        std::cout << 1 << std::endl;
        std::ios_base::floatfield;
    }
    {
        // 암시적 형변환
        unsigned int uintNum = 1;
        int intNum = 1u;
        float fNum = 1.1f;

        uintNum = intNum;
        intNum = uintNum;
        fNum = intNum;

        short sNum = numeric_limits<int>::max();
        cout << sNum << endl; // 암시적 형변환의 위험, 오버 플로우

        // 형변환 연산자
        cout << 'a' << endl;
        cout << (int)'a' << endl; // C스타일 형변환
        cout << int('a') << endl; // C++ 스타일 형변환

        // C++ 스타일의 형변환 연산자들 (추후 배울 예정)
        // static_cast
        // const_cast
        // dynamic_cast
        // reinterpret_cast

    }


}