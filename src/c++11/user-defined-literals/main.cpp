#include "Distance.hpp"

#include <iostream>
#include <chrono>

using namespace user_defined_literals;
using namespace distance_literals;

using namespace std::chrono_literals;

int main()
{
    auto distance1 = 10_mm;
    auto distance2 = 100_cm;
    auto distance3 = 1000_m;
    auto distance4 = 10000_km;

    std::cout << distance1.Count() << "mm"<< '\n';
    std::cout << distance2.Count() << "cm"<< '\n';
    std::cout << distance3.Count() << "m"<< '\n';
    std::cout << distance4.Count() << "km"<< '\n';

    std::cout << distance_cast<Distance<long double, std::kilo>>(distance2).Count() << '\n';
}