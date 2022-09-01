
#include <iostream>
#include <cstring>
#include <array>

using namespace std;

enum Color
{
    // 값을 지정해주지 않으면 첫 번째는 0이 되고 이후로 1씩 증가
    Red, Green, Blue, SIZE
};

struct ColorStruct
{
    int red;
    int green;
    int blue;
};

enum TextAttribute
{
    Bold = 1,
    Underline = 2,
    Italic = 4,
    Strikethrough = 8
};

enum CircleAttribute
{
    //Bold = 1 // Unscoped Enum 의 경우 TextAttribute::Bold 와 이름이 겹쳐서 사용할 수 없다.
};

enum struct ScopedTextAttribute
{
    Bold = 1,
    Underline = 2,
    Italic = 4,
    Strikethrough = 8
};

enum class ScopedCircleAttribute
{
    Bold = 1 // ScopedEnum은 이름이 겹쳐도 가능
};

enum Overflow
{
    Value0 = 100000000000
};

enum NotOverflow : uint64_t
{
    Value1 = 100000000000
};




int main()
{
    //구조체, union, enum, arraay
    struct Person
    {
        float height;
        float weight;
        char name[10];
        short grade;
    };

    Person person{ .height = 174.2f, .weight= 67.8f, .name= "David", .grade=1 };
    cout << person.height << endl;
    cout << person.weight << endl;
    cout << person.grade << endl;
    cout << person.name << endl;

    {
        // struct 를 멤버 변수로 가지기
        struct EyeSight
        {
            float left;
            float right;
        };
        struct Person
        {
            float height;
            float weight;
            char name[10];
            short grade;
            EyeSight eyeSight;
        };

        Person person{ 174.2f, 67.3f, "David", 1, {1.1f, 1.0f} };

        cout << person.height << endl;
        cout << person.weight << endl;
        cout << person.grade << endl;
        cout << person.name << endl;
        cout << person.eyeSight.left << endl;
        cout << person.eyeSight.right << endl;

        // 배열이 내부에 있어도 복사가 됨
        Person person1 = person;

        // 비교는 안 됨
        //person == person1;
    }
    {
        Person persons[5];
        persons[0].grade = 1;

        cout << persons[0].grade << endl; // 1

        Person person1 = persons[1]; // person0 은 persons[1]이 아니라 복사한 것이다.
        person1.grade = 5; // 복사본의 grade가 변경

        cout << person1.grade << endl;    // 5
        cout << persons[1].grade << endl; // 정의 되지 않은 행동

        Person &person2 = persons[2]; // 복사본이 아닌 레퍼런스(추후 배움)
        person2.grade = 5; 

        cout << person2.grade << endl;    // 5
        cout << persons[2].grade << endl; // 5
    }
    {
        // strcut 의 사이즈
        struct Person0
        {
            float height;   // 4
            float weight;   // 4
            char name[10];  // 10
            short grade;    // 2
        };
        cout << sizeof(Person0) << endl;
        // height, weight, name, grade
        //   4   ,   4   ,  10 ,   2

        struct Person1
        {
            float height;   // 4
            short grade;    // 2
            float weight;   // 4
            char name[10];  // 10
        };
        cout << sizeof(Person1) << endl;
        // height, grade, weight, name
        //    4  ,  2(2),    4  ,  10  (2)  = 24
        
        struct alignas(16) Person2
        {
            float height;   // 4
            short grade;    // 2
            float weight;   // 4
            char name[10];
        };
        cout << alignof(Person0) << endl;
        cout << alignof(Person1) << endl;
        cout << alignof(Person2) << endl;
    }


        // 공용체를 사용하지 않는 경우.
        // idInteger, idChars 의 메모리 낭비
    {
        struct Product
        {
            int idType;
            int idInteger;
            char idChars[10];
        };

        Product product = { 0, 12 };
        if (product.idType == 0)
            cout << product.idInteger << endl;
        else
            cout << product.idChars << endl;

        cout << "size : " << sizeof(Product) << endl;
    }
    {
        // 공용체를 사용하는 경우
        union ID
        {
            // integer와 chars가 메모리를 공유한다.
            int integer;
            char chars[10];
        };
        struct Product
        {
            int idType;
            ID id;
        };

        Product product0 = { 0, {12} };
        Product product1 = { 1, {.chars = "abc"} }; // C++ 2x 이상
        if (product0.idType == 0)
            cout << product0.id.integer << endl;
        else
            cout << product0.id.chars << endl;

        if (product1.idType == 0)
            cout << product1.id.integer << endl;
        else
            cout << product1.id.chars << endl;

        cout << "size : " << sizeof(Product) << endl;
        cout << "size : " << sizeof(ID) << endl;
    }
    
    //enum
    {
        int colors[SIZE] = { 255, 128, 64 };
        // Unscoped enum 을 이용하여 RGB 값의 평균
        int total = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            total += colors[i];
        }

        int avg0 = total / SIZE;
        cout << avg0 << endl;

        // Struct를 이용하여 RGB 값의 평균
        ColorStruct cs = { 255, 128, 64 };
        int avg1 = (cs.red + cs.green + cs.blue);
        cout << avg1 << endl;
    }
    {
        // BitFlag 사용
        int textAttrs = 0;
        textAttrs |= Bold;
        textAttrs |= Underline;

        cout << textAttrs << endl;
        if (textAttrs & Underline)
            cout << "Underline" << endl;
    }
    {
        Bold;
        TextAttribute::Bold; // 범위 지정해서 사용 가능
        ScopedTextAttribute::Bold; // 범위 지정을 반드시 해야 한다.

        cout << Bold << endl;
        cout << TextAttribute::Bold << endl;
        cout << (int)ScopedTextAttribute::Bold << endl; // 강타입, 암시적으로 정수형으로 변환되지 않는다
        // Unscoped enumeration 보다 Scoped enumeration 사용이 권장 된다
    }
    {
        cout << Overflow::Value0 << endl;
        cout << NotOverflow::Value1 << endl;
    }
    {
        Color color = Color::Red; // 변수로 사용
        if (color == Color::Red) // 비교문
        {
            cout << "Red" << endl;
        }
    }
    {
        Color color = (Color)0; // 정수를 enum으로 변환
        if (color == Color::Red) 
        {
            cout << "Red" << endl;
        }
    }

    {
        // int가 5개 있는 C++ 스타일 배열 선언
        // 내부적으로 정적 배열을 가지고 있다
        // 초기화가 안 되어 있으면 쓰레기 값
        array<int, 5> arr0;

        // 기본값으로 초기화(int의 경우 기본값은 0)
        array<int, 5> arr1{};

        // arr2[0], arr2[1]의 값만 세팅 되고 나머지 값들은 기본값으로 초기화(int의 경우 기본값은 0)
        array<int, 5> arr2{ 0, 1 };
    }
    {
        array<int, 5> arr{ 1, 2, 3 };
        cout << arr[0] << endl;
        //cout << arr[-1] << endl; // release 빌드 시 예외 발생 안 할 수 있음(정의 되지 않은 행동)
        //cout << arr.at(-1) << endl; // 범위 벗어날  예외 보장 (std::out_of_range)
    }
    {
        // 배열 사이즈 구하기
        int arr0[] = { 1, 2, 3 };
        cout << sizeof(arr0) / sizeof(int) << endl;
        cout << sizeof(arr0) / sizeof(arr0[0]) << endl;

        array<int, 3> arr1 = { 1, 2, 3 };
        cout << arr1.size() << endl;
    }
    {
        // 배열의 가장 앞, 가장 뒤 원소 구하기
        array<int, 3> arr{ 1, 2, 3 };
        cout << arr[0] << endl;
        cout << arr.front() << endl;

        cout << arr[arr.size() - 1] << endl;
        cout << arr.back() << endl;
    }
    {
        array<int, 5> arr0{ 1, 2, 3, 4, 5 };
        array<int, 5> arr1{ 5, 4, 3, 2, 1 };

        // 교환
        arr0.swap(arr1);

        // 대입 가능
        arr0 = arr1;

        // 비교 연산들 가능
        if (arr0 == arr1)
        {

        }
        if (arr0 > arr1)
        {

        }
        if (arr0 < arr1)
        {

        }
    }
    {
        array<int, 5> arr{ 1, 2, 3, 4, 5 };
        cout << arr.data()[0] << endl; // 내부 정적 배열에 접근
    }

    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // 순회하면서 변경
        for (int i = 0; i < 2; ++i)
        {
            persons[i].weight = 0.f;
        }

        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // 순회하면서 변경
        for (Person person : persons)
        {
            person.weight = 0.f;
        }

        // 변경 되지 않음
        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // 순회하면서 변경, 참조(레퍼런스)
        for (Person& person : persons)
        {
            person.weight = 0.f;
        }

        // 변경 됨
        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        for (int i = 0; i < 2; ++i)
        {
            cout << &persons[i] << endl;
        }

        cout << endl;
        for (Person person : persons)
        {
            cout << &person << endl; // 주소 값이 다르다
        }

        cout << endl;
        for (Person& person : persons)
        {
            cout << &person << endl;
        }
    }
    {
        int nums[3] = { 1, 2, 3 };
        for (int num : nums)
        {
            num = 0; // 안 바뀜
        }
        for (int num : nums)
        {
            cout << num << endl;
        }

        for (int& num : nums) // 참조(레퍼런스)
        {
            num = 0; // 바뀜
        }
        for (int num : nums)
        {
            cout << num << endl;
        }
    }
}