#include "Person.hpp"

#include <cstring>
#include <algorithm>

std::size_t cpp11::move_semantics::Person::maxId = 0;

cpp11::move_semantics::Person::Person(const char* name, std::size_t age) noexcept : id(++Person::maxId), age(age)
{
    std::cout << '[' << this->id << "] default constructor" << std::endl;

    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}

cpp11::move_semantics::Person::Person(const Person& other) noexcept : id(++Person::maxId)
{ 
    std::cout << '[' << this->id << "] copy constructor" << std::endl;

    // this의 이름이 있는 경우, 메모리 해제
    if(this->name != nullptr) delete[] this->name;

    // other 정보로 복사
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);

    this->age = other.age;
}

cpp11::move_semantics::Person::Person(Person&& other) noexcept : id(++Person::maxId)
{
    std::cout << '[' << this->id << "] move constructor" << std::endl;

    // this의 이름이 있는 경우, 메모리 해제
    if(this->name != nullptr) delete[] this->name;

    // other 정보 this로 이동
    this->name = other.name;
    this->age = other.age;

    other.name = nullptr;
    other.age = 0;
}

cpp11::move_semantics::Person::~Person()
{
    std::cout << '[' << this->id << "] destructor" << std::endl;

    if(this->name != nullptr) delete[] this->name;
}

cpp11::move_semantics::Person& cpp11::move_semantics::Person::operator=(const Person& other) noexcept
{
    std::cout << "copy assignment" << std::endl;

    // this의 이름이 있는 경우, 메모리 해제
    if(this->name != nullptr) delete[] this->name;

    // other 정보로 복사
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);

    this->age = other.age;

    return *this;
}

cpp11::move_semantics::Person& cpp11::move_semantics::Person::operator=(Person&& other) noexcept
{
    std::cout << "move assignment" << std::endl;
    
    // this의 이름이 있는 경우, 메모리 해제
    if(this->name != nullptr) delete[] this->name;

    // other 정보 this로 이동
    this->name = other.name;
    this->age = other.age;

    other.name = nullptr;
    other.age = 0;

    return *this;
}

namespace cpp11::move_semantics
{
    std::ostream& operator<<(std::ostream& os, const Person& person)
    {
        os << (person.name != nullptr ? person.name : "nullptr") << " : " << person.age;
        return os;
    }
}
