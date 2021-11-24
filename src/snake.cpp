#include <iostream>
#include <ncurses.h>

int szerokosc, wysokosc, szybkosc;

int intPut;

int upomnij(int& x)
{
   std::cout << "Podano błędną liczbę, została 1 próba"
         << "\n";
    std::cout << "Proszę wybrać liczbę z przedziału 5 - 35"
         << "\n";
    std::cin >> x;
    if (x < 5 || x > 35)
        x = 15;

    return 1;
}


int main()
{
    std::cout << "WITAJ W SNAKE GAME!"
         << "\n";
    std::cout << "Podaj szerokość planszy (5 - 35): "
         << "\n";
    std::cin >> szerokosc;
    if (szerokosc < 5 || szerokosc > 35)
        upomnij(szerokosc);


    std::cout << "Podaj wysokość planszy (5 - 35): "
         << "\n";
    std::cin >> wysokosc;
    if (wysokosc < 5 || wysokosc > 35)
        upomnij(wysokosc);

    std::cout << "Podaj szybkość (1 - 10): "
         << "\n";
    std::cin >> szybkosc;
    if (szybkosc < 1)
        szybkosc = 1;
    if (szybkosc > 10)
        szybkosc = 10;


    std::cout << "Wymiary planszy: " << szerokosc << "x" << wysokosc << "\n";
    std::cout << "Szybkość: " << szybkosc << "\n";


    std::cout << "Naciśnij klawisz, aby przypisać go do odpowiedniej mechaniki gry: "
         << "\n";
    std::cout << "GÓRA: "
         << "\n";
    std::cin >> intPut >>"\n";

while(intPut != 'q')
{
    intPut = getch();
    if (intPut == KEY_LEFT) std::cout << "You pressed left.\n"; 

    else if(intPut == KEY_RIGHT) std::cout << "You pressed right.\n";

    else if(intPut == KEY_UP) std::cout << "You pressed up.\n";

    else if (intPut == KEY_DOWN) std::cout 










    return 0;
}
