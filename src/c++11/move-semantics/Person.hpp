#pragma once

#include <iostream>
#include <sstream>

namespace cpp11::move_semantics
{
    class Person
    {
    public:
        Person(const char* name, std::size_t age) noexcept ; // 기본 생성자
        Person(const Person& other) noexcept;                // 복사 생성자
        Person(Person&& other)noexcept;                      // 이동 생성자
        ~Person();                                           // 소멸자

        Person& operator=(const Person& other) noexcept; // 복사 대입 연산자
        Person& operator=(Person&& other) noexcept;      // 이동 대입 연산자

        friend std::ostream& operator<<(std::ostream& os, const Person& person);

    private:
        static std::size_t maxId;

        std::size_t id;
        std::size_t age;
        char* name;
    };
}