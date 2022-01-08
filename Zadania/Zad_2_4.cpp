#include <iostream>
#include <vector>

struct student {

  std::string name;
  std::string surname;
  std::vector<int> marks;

   student(std::string n, std::string s, std::vector<int> m) {
           name = n;
            surname = s;
               marks = m;
   }
  };

 auto average_of(student m) {

                 double sum = 0;

    for (auto i = 0; i <= m.marks.size() - 1; ++i) {
              int  s = m.marks[i];
                     sum += s;

}
return sum / m.marks.size();
}


int main()
{
 auto marks = std::vector<int> {2,4,2,4,2,5};

    auto Paul = student("Paul","Brown",marks);

    std::cout<< average_of(Paul);


    return 0;
}
