#include "Distance.hpp"

user_defined_literals::mm distance_literals::operator""_mm(user_defined_literals::BasicRep value)
{
    return user_defined_literals::mm(value);
}

user_defined_literals::cm distance_literals::operator""_cm(user_defined_literals::BasicRep value)
{
    return user_defined_literals::cm(value);
}

user_defined_literals::m distance_literals::operator""_m(user_defined_literals::BasicRep value)
{
    return user_defined_literals::m(value);
}

user_defined_literals::km distance_literals::operator""_km(user_defined_literals::BasicRep value)
{
    return user_defined_literals::km(value);
}
