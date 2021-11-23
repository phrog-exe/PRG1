#include <string>
#ifndef time_h
#define time_h

namespace s24404 {
	class Time {
	public:
		int Hours;
		int Minutes;
		int Seconds;

	enum Part_of_day {
		Morning,
		Afternoon,
		Evening,
		Night,
	};

	Time() = default;
	Time(int, int, int);

	auto next_hour() -> void;
	auto next_minute() -> void;
	auto next_second() -> void;

	auto part_of_day() const -> Part_of_day;
	auto count_minutes() const -> std::uint64_t;
	auto count_seconds() const -> std::uint64_t;
	auto to_string(Part_of_day) const -> std::string;
	auto to_string() const -> std::string;
	auto time_to_midnight() const -> Time;


};

#endif
