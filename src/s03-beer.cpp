#include <iostream>
#include <string>
auto main(int, char* argv[]) -> int
{
    auto x = std::stoi(argv[1]);
    for (int i = x; i >= 0; i--) {
        if (i > 1) {
            std::cout << i << " bottles of beer on the wall," << i
                      << " bottles of beer.\n"
                      << "Take one down, pass it around, " << i - 1
                      << " bottles of beer on the wall..\n";
        } else if (i == 1) {
            std::cout << i << " bottle of beer on the wall," << i
                      << " bottle of beer.\n"
                      << "Take one down, pass it around, " << i - 1
                      << " bottles of beer on the wall..\n";
        } else {
            std::cout << "No more bottles of beer on the wall, no more bottles "
                         "of beer.\nGo to the store and buy some more,"
                      << x << " bottles of beer on the wall...\n";
        }
    }

    return 0;
}
