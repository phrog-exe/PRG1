#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::string surname;
    std::vector<float> marks;
};

auto average_of(Student student)
{
    auto sum = float{0};
    for (auto element : student.marks)
    {
        sum += element;
    }


 return sum / (student.marks.size());
}

auto get_best_student(std::vector<Student> foo)
{
    auto best = float{0};
    auto the_best_student = Student{};

      for (auto s : foo) {

        if( average_of(s) > best) {
          best = average_of(s);
            the_best_student = s;
        }
    }

    return the_best_student;
}

auto main() -> int
{
    auto s1 = Student{"John", "Smith", {5,5,3,4}};
    auto s2 = Student{"Alice", "Jhonson", {5,3,2,2}};
    auto s3 = Student{"Paul", "Brown", {5,4,3.5,4}};

    auto students = std::vector<Student> {s1,s2,s3};
      std::cout <<"Best student is: " << get_best_student(students).name << " " << get_best_student(students).surname << "\n";


    return 0;
}
