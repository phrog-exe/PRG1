#include "../include/s42/Time.h"
#include <iostream>
#include <string>


auto s42::Time::next_hour() -> void
{
    if (hour == 23) {
        hour = 0;
    }

    else {
        hour++;
    }
}

auto s42::Time::next_minute() -> void
{
    if (min == 59) {
        min = 0;
        hour++;
    } else {
        min++;
    }
}
auto s42::Time::next_second() -> void
{
    if (sec == 59) {
        sec = 0;
        min++;
    }

    else {
        sec++;
    }
}

s42::Time::Time(int h, int m, int s) : hour{h}, min{m}, sec{s}
{}

auto s42::Time::to_string() const -> std::string
{
    auto out = std::ostringstream{};

    std::string space1;
    std::string space2;
    std::string space3;
    if (hour > 10) {
        space1 = "";
    } else {
        space1 = "0";
    }
    if (min > 10) {
        space2 = "";
    } else {
        space2 = "0";
    }

    if (sec > 10) {
        space3 = "";
    } else {
        space3 = "0";
    }
    out << "Time: " << space1 << hour << ":" << space2 << min << ":" << space3
        << sec;
    return out.str();
}


auto s42::Time::to_string(s42::Time::Time_of_day const t) -> std::string
{
    switch (t) {
    case s42::Time::Time_of_day::Morning:
        return "Morning";
    case s42::Time::Time_of_day::Afternoon:
        return "Afternoon";
    case s42::Time::Time_of_day::Evening:
        return "Evening";
    case s42::Time::Time_of_day::Night:
        return "Night";
    default:
        return "What_time_of_day";
    }
}


auto s42::Time::time_of_day() const -> s42::Time::Time_of_day

{
    if (hour >= 5 && hour < 12)
        return s42::Time::Time_of_day::Morning;

    else if (hour >= 12 && hour < 18)
        return s42::Time::Time_of_day::Afternoon;

    else if (hour >= 18 && hour < 20)
        return s42::Time::Time_of_day::Evening;

    else
        return s42::Time::Time_of_day::Night;
}


auto s42::Time::operator+(s42::Time const& op) const -> s42::Time
{
    int h = hour;
    int m = min;
    int s = sec;
    h += op.hour;
    m += op.min;
    s += op.sec;
    if (h > 24) {
        h -= 24;
    }
    if (m > 59) {
        m -= 60;
        h++;
    }
    if (s > 59) {
        s -= 60;
        m++;
    }
    return s42::Time(h, m, s);
}

auto s42::Time::operator-(s42::Time const& op) const -> s42::Time
{
    int h = hour;
    int m = min;
    int s = sec;
    h -= op.hour;
    m -= op.min;
    s -= op.sec;
    if (h < 0) {
        h += 24;
    }
    if (m < 0) {
        m += 60;
        h--;
    }
    if (s < 0) {
        s += 60;
        m--;
    }


    return s42::Time(h, m, s);
}

auto s42::Time::operator<(s42::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h < op.hour)
        return true;
    else if (m < op.min)
        return true;
    else if (s < op.sec)
        return true;
    else
        return false;
}

auto s42::Time::operator>(s42::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h > op.hour)
        return true;
    else if (m > op.min)
        return true;
    else if (s > op.sec)
        return true;
    else
        return false;
}

auto s42::Time::operator==(s42::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h == op.hour)
        return true;
    else if (m == op.min)
        return true;
    else if (s == op.sec)
        return true;
    else
        return false;
}

auto s42::Time::operator!=(s42::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h != op.hour)
        return true;
    else if (m != op.min)
        return true;
    else if (s != op.sec)
        return true;
    else
        return false;
}
auto s42::Time::count_seconds() const -> uint64_t
{
    int h = hour;
    int m = min;
    int s = sec;

    std::uint64_t c_sec = h * 3600 + m * 60 + s;
    return c_sec;
}


auto s42::Time::count_minutes() const -> uint64_t
{
    int h = hour;
    int m = min;

    std::uint64_t c_min = h * 60 + m;
    return c_min;
}
auto s42::Time::time_to_midnight() const -> s42::Time
{
    s42::Time tim_mid(0, 0, 0);
    tim_mid.sec  = 60 - sec;
    tim_mid.min  = 59 - min;
    tim_mid.hour = 23 - hour;

    return tim_mid;
}

auto main() -> int
{
    auto time = s42::Time(13, 59, 58);
    std::cout << time.to_string() << "\n";
    time.next_minute();
    time.next_hour();
    time.next_second();
    std::cout << time.to_string() << "\n";
    std::cout << time.count_seconds() << "\n";
    std::cout << time.count_minutes() << "\n";
    std::cout << time.time_to_midnight().hour << ":"
              << time.time_to_midnight().min << ":"
              << time.time_to_midnight().sec << "\n";
    std::cout << time.to_string(time.time_of_day()) << "\n";
    auto time_2 = time + s42::Time(4, 0, 2);
    auto time_3 = time_2 - s42::Time(5, 0, 59);
    std::cout << time_2.to_string() << "\n";
    std::cout << time_3.to_string() << "\n";
    auto time_4 = time > s42::Time(5, 3, 5);
    std::cout << time.to_string() << " > " << s42::Time(5, 3, 5).to_string()
              << "\n";
    if (time_4 == 1) {
        std::cout << "is true \n";
    } else {
        std::cout << "is false \n";
    }

    return 0;
}
