#include <iostream>
#include <ratio>
#include <concepts>

namespace user_defined_literals
{
    /// @brief 
    /// @tparam Rep 표현 단위 (예: n KM일 때, n의 표현 단위 -> 10000 : 양의 정수)
    /// @tparam Ratio 미터를 기준으로 했을 때, 비율 (예: cm는 m의 1/100 따라서 std::ratio<1, 100>)
    template<class Rep, class Ratio = std::ratio<1>>
    class Distance
    {
    public:
        // Rep, Ratio를 외부(DistanceCast)에서 확인할 수 있도록 별칭 사용

        using rep = Rep;
        using ratio = Ratio;

        Distance(Rep value) : value(value) {};
        Distance(const Distance<Rep, Ratio>& other);
        Distance(Distance<Rep, Ratio>& other);
        ~Distance() = default;

        Distance& operator=(const Distance<Rep, Ratio>& other);
        Distance& operator=(Distance<Rep, Ratio>& other);
        Distance& operator+(const Distance& other);
        Distance& operator-(const Distance& other);

        Rep Count() const { return value; }

    private:
        Rep value;
    };

    using BasicRep = unsigned long long;
    using mm = Distance<BasicRep, std::milli>;
    using cm = Distance<BasicRep, std::centi>;
    using m  = Distance<BasicRep>;
    using km = Distance<BasicRep, std::kilo>;

    template <class ToDistance, class FromDistance>
    ToDistance distance_cast(const FromDistance& from)
    {
        // 변환할 Rep
        using ConvertRep = ToDistance::rep;

        // 변환 비율 계산 (FromDistance의 비율 / ToDistance의 비율)
        const intmax_t convertNum = FromDistance::ratio::num * ToDistance::ratio::den;
        const intmax_t convertDen = FromDistance::ratio::den * ToDistance::ratio::num;

        ConvertRep convertValue = from.Count() * (static_cast<ConvertRep>(convertNum) / convertDen);

        // 변환된 값 계산
        return ToDistance(convertValue);
    }
} // namespace user_defined_literals

namespace distance_literals
{
    user_defined_literals::mm operator ""_mm(user_defined_literals::BasicRep value);
    user_defined_literals::cm operator ""_cm(user_defined_literals::BasicRep value);
    user_defined_literals::m  operator ""_m(user_defined_literals::BasicRep value);
    user_defined_literals::km operator ""_km(user_defined_literals::BasicRep value);
}
