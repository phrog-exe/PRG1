#include <iostream>
#include <string>

std::string type_word() {
std::string word;
 std::cout << "Type your word in: "<< std::endl;
 std::cin >> word;
     return word;
}

bool is_palindrome() {
    std::string word;
    char first;
    char last;

 word = type_word();
 int dl;
 int i;

    for (i=1; i<=word.size(); i++){
            dl = word.size();
        first = word[dl - word.size() + i - 1];
        last = word[word.size() - i];
            if (first == last)
                 continue;
              else
                 return 0;
    }
return 1;
}

int main()
{
    if (is_palindrome() == 1)
        std::cout << "This is a Palindrome." << std::endl;
        
   else if (is_palindrome() == 0)
        std::cout << "That is not a Palindrome." << std::endl;
 
        else
            std::cout << "An error occurred...";
    return 0;
}
