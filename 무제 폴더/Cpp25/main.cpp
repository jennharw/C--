
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

union Union
{
    int i;
    float f;
    double d;
};

int main()
{
    {
        int num = 100;
        int* pointer = &num;

        cout << num << endl; // num 값
        cout << &num << endl; // num의 주소값
        cout << pointer << endl; // num의 주소값을 pointer가 가지고 있다

        cout << *pointer << endl; // 역참조, dereference, num에 접근
        *pointer = 200;

        cout << num << endl;
        cout << *pointer << endl;
    }

    {
        int num = 123;
        int* pNum0 = &num;
        int* pNum1 = &num;
        int* pNum2 = pNum0;

        cout << &num << endl;
        cout << pNum0 << endl;
        cout << pNum1 << endl;
        cout << pNum2 << endl;
        cout << endl;
        
        cout << num << endl;    // 123
        cout << *pNum0 << endl; // 123
        cout << *pNum1 << endl; // 123
        cout << *pNum2 << endl; // 123
        cout << endl;
        
        num = 100;
        cout << num << endl;    // 100
        cout << *pNum0 << endl; // 100
        cout << *pNum1 << endl; // 100
        cout << *pNum2 << endl; // 100
        cout << endl;
    }
    {
        int* pNum = 0;
        cout << pNum << endl;
    }

    {
        Union u;
         int* ip = (int*)&u;
        float* fp = (float*)&u;
        double* dp = (double*)&u;

        u.i = 1;

        cout << u.i << endl;
        cout << *ip << endl; // 메모리를 int로 해석

        cout << u.f << endl;
        cout << *fp << endl; // 메모리를 float로 해석

        cout << u.d << endl;
        cout << *dp << endl; // 메모리를 double로 해석
    }
    
    {
        //포인터 선언시 const가 가장 앞에 위치하는 경우
        int num0 = 10;
        const int* pNum = &num0;

        int num1 = 20;
        pNum = &num1;

        //*pNum = 30; 불가능, 내용 바꿀 수 없음
    }
    {
        //포인터 선언시 const 가 변수명 바로 앞에 위치하는 경우
        int num0 = 10;
        int* const pNum = &num0;
        int num1 = 20;
        //pNum = &num1; // 불가능
        *pNum = 30;
    }
    {
        int num0 = 10;
        const int* const pNum = &num0;

        int num1 = 20;
        //pNum = &num1; // 불가능
        //*pNum = 30; // 불가능
    }

    //
    {
        int nums[] = {1,2,3};
        cout << nums << endl;

        int* pNums = nums;
        cout << sizeof(nums) << endl;
        cout << sizeof(pNums) << endl;

        //다 같은 주소 값
        cout << nums << endl; // int*, decay 되었다.
        cout << &nums << endl; // int (*)[3], 이 녀석만 타입이 다름
        cout << &nums[0] << endl; // int*
        cout << endl; 

        cout << typeid(1).name() << endl;       // int
        cout << typeid(nums).name() << endl;    // int [3], typeid를 사용하면 decay되지 않은 제대로 된 타입이 나옴
        cout << typeid(&nums).name() << endl;   // int (*)[3]
        cout << typeid(&nums[0]).name() << endl;// int*

    }
    {
        int nums[] = {1,2,3};
        int* pNums = nums;

        cout << pNums[0] << endl;   // 1
        cout << pNums[1] << endl;   // 2
        cout << pNums[2] << endl;   // 3

        cout << pNums << endl;      // base address + sizeof(int) * 0
        cout << pNums + 1 << endl;  // base address + sizeof(int) * 1
        cout << pNums + 2 << endl;  // base address + sizeof(int) * 2

        cout << *pNums << endl;
        cout << *(pNums + 1) << endl;
        cout << *(pNums + 2) << endl;
    }
    {
        int nums[] = {1,2,3};
        int* pNums = nums;
        cout << *pNums << endl; // nums[0]
        pNums++;
        cout << *pNums << endl; // nums[1]
    }

    //문자열
    {
        // 문자 배열(문자열)을 포인터로 가리킴
        char str0[] = "abcd";
        char* str1 = str0;
        cout << str0 << endl;
        cout << str1 << endl;

        //문자열 리터럴
        const char* str2 = "hello";
        cout << str2 << endl;
        cout << typeid("hello").name() << endl;

    }
    {
        char str0[] = "abcd";
        char* str1 = str0;
        const char* str2 = "hello";
        cout << strlen(str2) << endl;
        strcpy(str0, str2);
        cout << str0 << endl;

        cout << strcmp(str0, str2) << endl;
    }

    // 자동 지역 변수. {} 지역안에서만 접근 가능. 자동할당 - 지역안에서 할당, 지역벗어나면 해제 int num0 = 0;
    // static int num1 = 0; 정적지역할당, 정적할당 - 프로그램에 시작되면 한 번 할당, 종료될 때 한번 해제 
    // 동적할당
    {
        //자동 지역변수 pNum에 동적할당된 이름 없는 변수 new int를 가리키게 함
        int* pNum = new int;
        //수동으로 해제 필요 
        delete pNum;
        //메모리 누수 Memory leak

        int* pNum0 = new int(123);
        int* pNum1 = pNum0;

        cout << *pNum0 << endl;
        delete pNum0;

        // 이미 해제된 포인터 접근(위험)
        //cout << *pNum0 << endl;
        //cout << *pNum1 << endl;


        // 해제된 포인터 다시 해제
        //delete pNum0;
    }

     {
        int* pNum;
        {
            int n = 10;
            pNum = &n; // n은 자동 지역 변수이기 때문에 지역을 벗어나면 자동으로 해제
        }
        // 이미 해제된 변수를 역참조 하니 위험
        //cout << *pNum << endl; 
    }

    {
        //동적할당을 통해 가변 배열 사용
        int s; 
        cin >> s;
        int* arr = new int[s];
        arr[0] = 1;
        cout << arr[0] << endl;
        delete[] arr;
    }

    {
        struct Person
        {
            float weight;
            float height;
        };

        // Person* person = new Person{ 74.1f, 180.2f };
        // cout << (*person).weight << endl;
        // cout << person->weight << endl;

        // delete person;

        // Person* persons[3] = {
        //     new Person{56.1f, 174.f},
        //     new Person{74.2f, 184.f}
        // };

        // for (Person* person : persons)
        // {
        //     person->weight = 0.0f;
        // }
        
        // for (Person* person : persons)
        // {
        //     cout << person->weight << endl; // 0.0f
        // }
    }

    {
        int* p = nullptr;
        cout << p << endl;
    }
    {
        int* p = new int;
        delete p;
        p = nullptr;
        // 유효한 포인터인지 확인
        if (p != nullptr)
        {
        }
    }
     {
        // nullptr의 타입
        std::nullptr_t n = nullptr;

        // nullptr_t의 값은 어떤 형태의 포인터로도 변환 가능
        int* p = n;
    }

    //void pointer 
    //void p 값의 형태로 선언할 수 없음
    
    {
        int num = 10;
        int* p = &num;

        void* vp = p;
        // 포인터를 어떤 형태로 다루어야 하는지 알 수 없어서 불가능
        //cout << *vp << endl;
        
        // 다른 형으로 변환 가능
        p = (int*)vp;
    }
    {
        int nums[] = {1,2,3};
        void* vp = nums;
        // 안 된다
        //*(vp + 1);
    }
    {
        //malloc 메모리를 매개변수의 크기만큼한 할당한다. 이 경우 sizeof(int) * 3 만큼
        // malloc 함수 안에서는 타입을 알 수 없고 크기만 알기 때문에 void*로 반환 함
        int* p = (int*)malloc(sizeof(int)*3);

        free(p);
    }
    //std-vector

    {
        //가변배열, 기본값(0)으로 초기화
        vector<int> vec(10);
        for (int i = 0;i<vec.size();i++)
        {
            cout << vec[i] << endl;
        }
    }
    {
        vector<int> vec(5,2);
        for (int num:vec)
            cout << num << endl;

        vec.resize(10,20);
        for (int num:vec)
            cout << num << endl;
    }
    {
        vector<int> vec;
        cout << vec.size() << endl;
        vec.push_back(10);
        cout << vec.size() << endl; // 1
        cout << vec[0] << endl; // 10
    }
{
        vector<int> vec;
        for (int i = 0; i < 10; ++i)
        {
            vec.push_back(i);
            cout << vec.size() << endl;
            cout << vec.data() << endl; // 주소가 바뀐다(재할당이 발생)
        }
    }
    {
        vector<int> vec;
        vec = { 1, 2, 3 };
        cout << vec.front() << endl; // 1
        cout << vec.back() << endl; // 2
    }
    {
        vector<int> vec0{ 1, 2, 3 };
        vector<int> vec1{ 3, 2, 1 };
        vec0.swap(vec1);
        // vec0 : 3, 2, 1
        // vec1 : 1, 2, 3
    }
    {
        vector<int> vec0{ 1, 2, 3 };
        vector<int> vec1{ 3, 2, 1 };
        vec0 = vec1;
        // vec0 : 3, 2, 1
        // vec1 : 3, 2, 1
    }
    {
        vector<int> vec0{ 1, 2, 3 };
        vector<int> vec1{ 3, 2, 1 };
        if (vec0 == vec1)
            cout << "==";
        if (vec0 > vec1)
            cout << ">";
        if (vec0 < vec1)
            cout << "<";
    }



}