#include <iostream>

int n;

int main() {

std::cout <<"Podaj liczbę:";
std::cin >> n;
std::cout << n <<std::endl;

if(n/3)
{
std::cout << "Fizz" <<std::endl;
}

else if(n/5)
{
std::cout <<"Buzz" <<std::endl;
}
return 0;
}
