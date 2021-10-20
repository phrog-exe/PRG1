#include <iostream>

int liczba;
auto main() -> int
 {

std::cout << "What number to count down?";
std::cin >> liczba;

for (int i = liczba; i>=0; i--)
{
std::cout << i <<std::endl; }

return 0;
}
