
#include <iostream>
#include <string>

auto main(int, char* argv[]) -> int
{
    auto const console_param = std::string{argv[1]};
    auto const entry_number  = std::stoi(console_param);

    if (entry_number >= 0) {
        for (int i = entry_number; i >= 0; --i) {
            std::cout << i << std::endl;
        }
    } else {
        for (int j = entry_number; j <= 0; ++j) {
            std::cout << j << std::endl;
        }
    }
    return 0;
}
