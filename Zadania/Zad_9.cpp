#include <iostream>
#include <string>



bool is_palindrome(std::string word)
{
    std::string invert;
    int length = word.length();


    for(int i = 0; i < length; i++)
    {
        invert += word[length - i - 1];
    }


    return word == invert;
}

int main()
{
    std::string word;

    std::cout << "Type your word in: " << std::endl;
    std::cin >> word;

    if (is_palindrome(word) == true)
    {
        std::cout << "This is a palindrome" << std::endl;
    }
    else
    {
        std::cout << "This is not a palindrome" << std::endl;
    }


    return 0;
}
