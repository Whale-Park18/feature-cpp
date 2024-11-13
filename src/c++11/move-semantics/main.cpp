#include "Person.hpp"

#include <iostream>

using namespace cpp11::move_semantics;

Person MakePerson()
{
    return Person("Kim", 10);
}

int main()
{
    Person person1("Park18", 30);
    Person person2("Hyunnn", 20);
    Person person3("Woo", 10);

    std::cout << "person1 | " << person1 << '\n';
    std::cout << "person2 | " << person2 << '\n';
    std::cout << "person3 | " << person3 << '\n';

    std::cout << '\n' << "[copy assignment]" << '\n';
    person1 = person2;
    std::cout << "person1 | " << person1 << '\n';
    std::cout << "person2 | " << person2 << '\n';

    std::cout << '\n' << "[move assignment]" << '\n';
    person1 = std::move(person3);
    std::cout << "person1 | " << person1 << '\n';
    std::cout << "person3 | " << person3 << '\n';
}