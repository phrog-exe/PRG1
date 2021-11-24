#include <iostream>
#include <string>
#include <sstream>
#include "../include/s42/s03-Time.h"

auto time1::next_hour() -> void
{
 if (hour==23)
          {hour = 0;}
 else
       ++hour;
}

auto time1::next_minute() -> void
{
 if (minute==59)
      {minute = 0;}
 else
       ++minute;
}

auto time1::next_second() -> void
{
 if (second==59)
      {second = 0;}
 else
       ++second;
}

auto time1::to_string() const -> std::string
{
   auto out = std::ostringstream{};

        std::string x;
        std::string y;
        std::string z;

 if (hour<10)
       {hour = "0";}

   else {x = "";}

 if (minute<10)
        {minute = 0;}

    else {y = "";}

 if (second<10)
       {second = 0;}

    else {z = "";}


out << x << this->hour << ":" << y << this->minute << ":" << z << this->second << "\n";

   return out.str();
}


time1::time1(int hour, int minute, int second)
{
      this->hour = hour;

      this->minute = minute;

      this->second = second;
}

  auto main() -> int
{
    auto s = time1{1, 2, 3};
    std::cout << s.to_string();
    std::cout << s.to_string();
    std::cout << s.next_hour();
    std::cout << s.to_string();

}




