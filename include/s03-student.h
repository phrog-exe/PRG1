#ifndef student_h
#define student_h
#include <string>


namespace s24404 {
class Student {
  public:
    std::string const name;
    std::string const surname;
    std::string const nrindex;
    int semester;
    float gpa;

    Student(std::string, std::string, std::string, int, float);
    auto to_string() const -> std::string;
};
}  // namespace s24404
#endif
