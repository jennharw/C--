#include <iostream>

using namespace std;


class Person
{
private:
    const string _name = "david"; // const 멤버 변수는 인라인으로 초기화 가능
    float _weight;
    float _height;

public:
    Person(const string& name, float weight, float height)
        : _name(name), _weight(weight), _height(height) // const 멤버 변수는 멤버 초기화 리스트에서 초기화 가능
    {

    }

    float getWeight(/* const Person* this */) const
    {

        // const가 붙은 멤버 함수에서의 this 포인터의 타입
        // const Person*
        //변경 불가능
        return _weight;
    }

    float getHeight(/* Person* this */)
    {
        // this 포인터의 타입
        // Person*
        return _height;
    }
};

int main()
{
    const Person person("David", 75.f, 181.f);
    cout << person.getWeight() << endl; // getWeight에 const Person*가 넘어간다.
    //cout << person.getHeight() << endl; // getHeight에 const Person*을 넘길 수 없다.

    // const Person person0("Daniel", 75.f, 181.f);
    // Person person1 = person0; // 값 복사 const 상관X

    Person *person0 = new Person("Daniel", 75.f, 181.f);
    const Person* person1 = person0; //일반 -> const O, const -> 일반 X
    //Person* person2 = person1;
}