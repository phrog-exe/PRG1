#include <iostream>
#include <sstream>

auto count_chars(std::string slowo, char litera) -> int
{
    auto num = 0;
    for (int i = 0; i <= slowo.size() -1 ; i++ ){
        if (slowo[i] == litera) {
        num++;
        }
    }
    return num;
}

 auto main() -> int
 {

    std::cout << count_chars("alibaba",'a');
    return 0;
}
