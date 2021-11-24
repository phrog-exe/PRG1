#include <sstream>
#include <iostream> 

struct time1 {
  int hour;
  int minute;
  int second;

time1 (int,int,int);

auto to_string() -> std::string;
 auto next_hour() -> void;
 auto next_minute() -> void;
 auto next_second() -> void;
};


