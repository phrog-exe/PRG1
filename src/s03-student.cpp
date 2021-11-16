#include <iostream>
#include <s03-student.h>
#include <sstream>

s24404::Student::Student(std::string name, std::string surname, std::string index, int semester double gpa)

 : name{name}, surname{surname}, index{index}, semester{semester}, gpa{gpa} {}

auto s24404::Student::to_string() const ->std::string {
     auto output =std::ostringstream{};
     output << "Name: " << name <<"\n" << "Surname: " << surname <<"\n" << "Index number: " << index <<"\n"
            << "Semester: " << semester <<"\n" << "Grade point average: " << gpa;

  return output.str();
}


auto main() -> int {
    auto student = s24404::Student{"Weronika", "Głódkowska", "s24404", 1, 3.9};
    std::cout <<student.to_string() <<"\n";

return 0;
}
