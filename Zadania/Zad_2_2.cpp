#include <iostream>
#include <string>
#include <vector>

auto filter_palindromes(std::vector<std::string> vec) -> std::vector<std::string>;
auto is_palindrome(std::string word) -> bool;

int main() {
    auto vec = std::vector<std::string>{"racecar", "mid", "anna", "cat"};

    for (auto element : filter_palindromes(vec)) {
        std::cout << element << " ";
    }
          std::cout << std::endl;
 return 0;
}

auto filter_palindromes(std::vector<std::string> vec) -> std::vector<std::string>
{
    auto palindrome = false;
    auto only_palindromes = std::vector<std::string>{};
          for(auto element : vec) {
        palindrome = is_palindrome(element);
                 if(palindrome == true) {
            only_palindromes.push_back(element);
        }
    }
 return only_palindromes;
}

auto is_palindrome(std::string word) -> bool
{
    int not_palindrome = 0;

      for(int i = 0; i < word.size() / 2; i++) {
                if(word[i] == word[word.size() - 1 - i])
                   continue;
        else {
            not_palindrome++;
            break;
        }
    }

       if(not_palindrome == 0)
          return true;
     else
           return false;
}
