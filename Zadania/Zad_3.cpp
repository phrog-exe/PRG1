#include <iostream>
#include <string>

std::string  Imie1;
std::string  Imie2;

int main()
{
    std::cout << "Podaj imie 1: " << std::endl;
    std::cin >> Imie1;
    std::cout << "Podaj imie 2: " << std::endl;
    std::cin >> Imie2;

if (Imie1 > Imie2)
    std::cout << "Imie 1 posiada wiecej liczer niz Imie 2!";
else if (Imie2 > Imie1)
    std::cout << "Imie 2 posiada wiecej liter niz Imie 1...";
else if (Imie1==Imie2)
    std::cout << "Imie 1 posiada tyle samo liter co Imie 2.";
    return 0;
}
