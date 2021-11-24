#include <iostream>
#include <string>

auto main(int, char* argv[]) -> int
{
    int input;
    try {
        input = std::stoi(argv[1]);
    } catch (...) {
        std::cout << "Error";
        return 0;
    }

    for (int i = 1; i <= input; i++) {
        std::cout << "n: " + std::to_string(i) << +" ";
        if (i % 3 == 0) {
            std::cout << "Fizz";
            if (i % 5 == 0) {
                std::cout << "Buzz";
            }
            std::cout << std::endl;
        } else if (i % 5 == 0) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << "No Fizz No Buzz" << std::endl;
        }
    }
    return 0;
}
