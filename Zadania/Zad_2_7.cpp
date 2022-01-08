#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    std::string surname;
    std::vector<float> marks;
};

struct Group
{
    std::string str;
    std::vector<Student> students_group;
};

auto add_student(Group& group, Student const& student) -> void
{
    group.students_group.push_back(student);
}

int main() {

    auto s1 = Student{"John", "Smith", {5,5,3,4}};
    auto s2 = Student{"Alice", "Jhonson", {5,3,2,2}};
    auto s3 = Student{"Paul", "Brown", {5,4,3.5,4}};

    auto group1 = Group{"Best students", {s1,s2,s3}};

    for(auto element : group1.students_group)
    {
        std::cout << element.name << " " << element.surname << std::endl;
    }
    std::cout<< "\n";

    auto s4 = Student{"Weronika", "Weronika",{3,4,4,5}};
    add_student(group1,s4);

    for(auto element : group1.students_group)
    {
        std::cout << element.name << " " << element.surname << std::endl;
    }


    return 0;
}
