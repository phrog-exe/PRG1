#include <iostream>

int main() {

char letter[2];
    std::cout << "Type in your letters: " << std::endl;
    std::cout << "Like this -> x x" << std::endl;

    std::cin >> letter[0] >> letter[1];
                 if (letter[0] == letter[1]) {
    std::cout << letter[0];
 }  else {
        for (char i = letter[0]; i <= letter[1]; i++)
             std::cout << i << " ";
        for (char i = letter[1]; i <= letter[0]; i++)
             std::cout << i << " ";
    }
}
