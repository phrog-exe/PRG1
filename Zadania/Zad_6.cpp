#include <iostream>
#include <sstream>

bool is_divisible(int dzielna, int dzielnik) {
if (dzielna%dzielnik==0)
 return true;
 else
 return false;

}

bool is_even(int x)
{
    if (is_divisible(x, 2)==true)
  return true;
  else
  return false;
}


int main()
{
    int liczba1, liczba2;

    std::cout << "wprowadz liczbe 1: " << std::endl;
    std::cin >> liczba1;
    std::cout << "Wprowadz liczbe 2: "<<"\n";
    std::cin >> liczba2;

if(is_divisible(liczba1, liczba2)==true) {

std::cout <<"Prawda"; }
   else {
std::cout <<"Falsz";
}

    return 0;
}
