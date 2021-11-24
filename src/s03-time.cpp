#include "../include/s03-time.h"

#include <iostream>
#include <sstream>
#include <string>


s24404::Time::Time(int Hours, int Minutes, int Seconds)
        : Hours{Hours}, Minutes{Minutes}, Seconds{Seconds}
{}


auto s24404::Time::next_hour() -> void
{
    if (Hours < 23) {
        Hours++;
    } else {
        Hours = 0;
    }
}


auto s24404::Time::next_minute() -> void
{
    if (Minutes < 59) {
        Minutes++;
    } else {
        Minutes = 0;
        next_hour();
    }
}


auto s24404::Time::next_second() -> void
{
    if (Seconds < 59) {
        Seconds++;
    } else {
        Seconds = 0;
        next_minute();
    }
}


auto s24404::Time::to_string() const -> std::string
{
    auto output = std::ostringstream{};

    if (Hours < 10) {
        output << "0" << Hours << ":";
    } else {
        output << Hours << ":";
    }

    if (Minutes < 10) {
        output << "0" << Minutes << ":";
    } else {
        output << Minutes << ":";
    }

    if (Seconds < 10) {
        output << "0" << Seconds;
    } else {
        output << Seconds;
    }

    return output.str();
}


auto s24404::Time::to_string(Part_of_day Daytime) const -> std::string
{
    switch (Daytime) {
    case Morning:
        return "Morning";
    case Afternoon:
        return "Afternoon";
    case Evening:
        return "Evening";
    case Night:
        return "Night";
    }
}

auto s24404::Time::part_of_day() const -> Part_of_day
{
    if (Hours >= 6 && Hours <= 11) {
        return Time::Morning;
    } else if (Hours >= 12 && Hours <= 17) {
        return Time::Afternoon;
    } else if (Hours >= 18 && Hours <= 22) {
        return Time::Evening;
    } else {
        return Time::Night;
    }
}
