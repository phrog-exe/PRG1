#include <iostream>
#include "../include/s03-student.h"
#include <sstream>

s24404::Student::Student(std::string name, std::string surname, std::string nrindex, int semester, float gpa)

 : name{name}, surname{surname}, nrindex{nrindex}, semester{semester}, gpa{gpa} {}

auto s24404::Student::to_string() const ->std::string {
     auto output =std::ostringstream{};
     output << "Name: " << name <<"\n" << "Surname: " << surname <<"\n" << "Index number: " << nrindex <<"\n"
            << "Semester: " << semester <<"\n" << "Grade point average: " << gpa;

  return output.str();
}


auto main() -> int {
    auto student = s24404::Student{"Weronika", "Głódkowska", "s24404", 1, 4.9};
    std::cout <<student.to_string() <<"\n";

return 0;
}
