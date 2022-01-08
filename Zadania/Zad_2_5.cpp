#include <iostream>
#include <vector>
#include <string>

auto split(std::string word) -> std::vector<std::string> {
    auto wrd = std::string{""};
    auto foo = std::vector<std::string>{};

      for (int i = 0; i <= word.size(); i++) {

            if ((int)word[i] == 17 || i == word.size()) {

                  foo.push_back(wrd);
                    wrd = {};  }

      else {
            wrd += word[i];
      }

      }

return foo;
}



int main()
{
    for (auto element : split("ala ma kota")) {
        std::cout << element << " ";
    }
              std::cout << std::endl;

    return 0;
}
