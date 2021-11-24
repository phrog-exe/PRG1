#include <time.h>

#include <cstdlib>
#include <iostream>

int liczba, strzal;

int main()
{
    std::cout << "Witaj! Pomyślałem sobie liczbę od 1 do 100"
              << "\n";
    srand(time(NULL));
    liczba = rand() % 100 + 1;

    while (strzal != liczba) {
        std::cout << "Zgadnij jaką:";
        std::cin >> strzal;

        if (strzal == liczba)
            std::cout << "Udało się! Wygrywasz";

        else if (strzal < liczba)
            std::cout << "To za  mało" << std::endl;

        else if (strzal > liczba)
            std::cout << "To za dużo" << std::endl;
    }

    getchar();
    getchar();

    return 0;
}
