#include <iostream>

using namespace std;

int szerokosc, wysokosc, szybkosc;

int upomnij(int& x)
{
    cout << "Podano błędną liczbę, została 1 próba"
         << "\n";
    cout << "Proszę wybrać liczbę z przedziału 5 - 35"
         << "\n";
    cin >> x;
    if (x < 5 || x > 35)
        x = 15;

    return 1;
}


int main()
{
    cout << "WITAJ W SNAKE GAME!"
         << "\n";
    cout << "Podaj szerokość planszy (5 - 35): "
         << "\n";
    cin >> szerokosc;
    if (szerokosc < 5 || szerokosc > 35)
        upomnij(szerokosc);


    cout << "Podaj wysokość planszy (5 - 35): "
         << "\n";
    cin >> wysokosc;
    if (wysokosc < 5 || wysokosc > 35)
        upomnij(wysokosc);

    cout << "Podaj szybkość (1 - 10): "
         << "\n";
    cin >> szybkosc;
    if (szybkosc < 1)
        szybkosc = 1;
    if (szybkosc > 10)
        szybkosc = 10;


    cout << "Wymiary planszy: " << szerokosc << "x" << wysokosc << "\n";
    cout << "Szybkość: " << szybkosc << "\n";


    cout << "Naciśnij klawisz, aby przypisać go do odpowiedniej mechaniki gry: "
         << "\n";
    cout << "GÓRA: "
         << "\n";


    return 0;
}
