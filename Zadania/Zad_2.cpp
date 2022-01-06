#include <iostream>
#include <string>

class human {
  public:
    std::string name;
    double weight;
    int height;
    human(std::string x, double y, int z) {
      weight = y;
      height = z;
    }
};

int main() {

  auto humanObj1 = human("Brian", 77.7, 180);


  std::cout << "Name: " << humanObj1.name << "\n" << "Weight: " << humanObj1.weight <<" kg" << "\n" <<"Height: " << humanObj1.height <<" cm" << "\n";

  return 0;
}
