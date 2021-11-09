#include <iostream>
#include <sstream>
#include <s03-time.h>
#include <string>


s24802::Time::Time(int hours, int minutes, int seconds)
        : hours{hours}, minutes{minutes}, seconds{seconds} {}

auto s24802::Time::next_hour() -> void
	{
    	if (hours < 23) {
	 ++hours;
   	 } else {
        hours = 0;
    	}
}

auto s24802::Time::next_minute() -> void
{
    if (minutes < 59) {
        ++minutes;
    } else {
        minutes = 0;
        next_hour();
    }
}

auto s24802::Time::next_second() -> void
{
    if (seconds < 59) {
        ++seconds;
    } else {
        seconds = 0;
        next_minute();
    }
}

auto s24802::Time::to_string() const -> std::string
{
    auto output = std::ostringstream{};

    if (hours < 10) {
        output << "0" << hours << ":";
    } else {
        output << hours << ":";
    }

    if (minutes < 10) {
        output << "0" << minutes << ":";
    } else {
        output << minutes << ":";
    }

    if (seconds < 10) {
        output << "0" << seconds;
    } else {
        output << seconds;
    }

    return output.str();
}

auto s24802::Time::to_string(Time_of_day daytime) const -> std::string {
    switch (daytime) {
        case morning:
            return "morning";
        case afternoon:
            return "afternoon";
        case evening:
            return "evening";
        case night:
            return "night";
	    }
}

auto s24802::Time::time_of_day() const -> Time_of_day {
    if (hours >= 6 && hours <= 11) {
        return Time::morning;
    } else if (hours >= 12 && hours <= 17) {
        return Time::afternoon;
    } else if (hours >= 18 && hours <= 22) {
        return Time::evening;
    } else {
        return Time::night;
    }
}

auto s24802::Time::count_seconds() const -> std::uint64_t {
    auto s_count = hours * 3600 + minutes * 60 + seconds;
    return s_count;
}

auto s24802::Time::count_minutes() const -> std::uint64_t {
    auto m_count = hours * 60 + minutes;
    return m_count;
}

auto s24802::Time::time_to_midnight() const -> Time {
    Time t;
    t.seconds = 60 - seconds;

    if (t.seconds > 0) {
        t.minutes = 59 - minutes;
    } else {
        t.minutes = 60 - minutes;
    }
    if (t.minutes > 0) {
        t.hours = 23 - hours;
    } else {
        t.hours = 24 - hours;
    }
    return t;
}

auto s24802::Time::operator+(const Time &n) const -> Time {
    int h = hours, m = minutes, s = seconds;
    s = s + n.seconds;
    m = m + n.minutes;
    h = h + n.hours;
    if (s > 59) {
        s = s - 60;
        m++;
    }
    if (m > 59) {
        m = m - 60;
        h++;
    }
    if (h > 23) {
        h = h - 24;
    }
    return Time(h, m, s);
}

auto s24802::Time::operator-(const Time &n) const -> Time {
    int h = hours, m = minutes, s = seconds;
    s = s - n.seconds;
    m = m - n.minutes;
    h = h - n.hours;
    if (s < 0) {
        s = s + 60;
        m--;
    }
    if (m < 0) {
        m = m + 60;
        h--;
    }
    if (h < 0) {
        h = h + 24;
    }
    return Time(h, m, s);
}

auto s24802::Time::operator!=(const Time &n) const -> bool {
    return !(hours == n.hours && minutes == n.minutes && seconds == n.seconds);
}

auto s24802::Time::operator==(const Time &n) const -> bool {
    return (hours == n.hours && minutes == n.minutes && seconds == n.seconds);
}

auto s24802::Time::operator<(const Time &n) const -> bool {
    if (hours < n.hours) return true;
    else if (hours == n.hours && minutes < n.minutes) return true;
    else if (hours == n.hours && minutes == n.minutes && seconds < n.seconds) return true;
    else return false;
}

auto s24802::Time::operator>(const Time &n) const -> bool {
    if (hours > n.hours) return true;
    else if (hours == n.hours && minutes > n.minutes) return true;
    else if (hours == n.hours && minutes && n.minutes && seconds > n.seconds) return true;
    else return false;
}

auto main() -> int {
    auto time = s24802::Time{23, 59, 59};
    // to string
    std::cout << "output z to_string()" << "\n" << time.to_string() << "\n\n";
    // next hour
    time.next_hour();
    std::cout << "output z next_hour()" << "\n" << time.to_string() << "\n\n";
    // next minute
    time.next_minute();
    std::cout << "output z next_minute()" << "\n" << time.to_string() << "\n\n";
    // next second
    time.next_second();
    std::cout << "output z next_second()" << "\n" << time.to_string() << "\n\n";
    // time of day
    std::cout << "output z time_of_day()" << "\n" << time.to_string(time.time_of_day()) << "\n\n";
    // count minutes after midnight
    std::cout << "output z count_minutes()" << "\n" << time.count_minutes() << " minutes after midnight" << "\n\n";
    // count seconds after midnight
    std::cout << "output z count_seconds()" << "\n" << time.count_seconds() << " seconds after midnight" << "\n\n";
    //  operator +
    std::cout << "output z operatora +" << std::endl;
    auto a = s24802::Time{23, 59, 59};
    auto b = s24802::Time{0, 0, 1};
    std::cout << (a + b).to_string() << "\n\n";
    //  operator -
    std::cout << "output z operatora -" << std::endl;
    auto a1 = s24802::Time{3, 59, 59};
    auto b1 = s24802::Time{4, 0, 0};
    std::cout << (a1 - b1).to_string() << "\n\n";
    // operator <
    std::cout << "output z operatora <" << std::endl;
    auto a2 = s24802::Time{22, 59, 59};
    auto b2 = s24802::Time{23, 0, 1};
    if (a2 < b2) {
        std::cout << a2.to_string() << " < " << b2.to_string() << "\n\n";
    } else {
        std::cout << a2.to_string() << " ? " << b2.to_string() << "\n\n";
    }
    // operator >
    std::cout << "output z operatora >" << std::endl;
    auto a3 = s24802::Time{23, 59, 59};
    auto b3 = s24802::Time{23, 0, 1};
    if (a3 > b3) {
        std::cout << a3.to_string() << " > " << b3.to_string() << "\n\n";
    } else {
        std::cout << a3.to_string() << " ? " << b3.to_string() << "\n\n";
    }
    // operator ==
    std::cout << "output z operatora ==" << std::endl;
    auto a4 = s24802::Time{23, 59, 59};
    auto b4 = s24802::Time{0, 0, 1};
    if (a4 == b4) {
        std::cout << a4.to_string() << " == " << b4.to_string() << "\n\n";
    } else {
        std::cout << a4.to_string() << " != " << b4.to_string() << "\n\n";
    }
    // operator !=
    std::cout << "output z operatora !=" << std::endl;
    auto a5 = s24802::Time{23, 59, 59};
    auto b5 = s24802::Time{0, 0, 1};
    if (a5 != b5) {
        std::cout << a5.to_string() << " != " << b5.to_string() << "\n\n";
    } else {
        std::cout << a5.to_string() << " == " << b5.to_string() << "\n\n";
    }
    return 0;
}
