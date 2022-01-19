#include <iostream>

void money(int sum)
{
    int how_many;

        int tab1[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };

           for (int i = (sizeof(tab1) / sizeof(*tab1)) - 1; i >= 0; --i) {
                        how_many=sum / tab1[i];

    if (how_many>0) {
    std::cout << "Denomination: " << tab1[i] << " x " << how_many << std::endl;
    }
                        sum %= tab1[i]; }
}

int main()
{
int sum;

    std::cout << "Please enter some amount of money: ";
    std::cin >> sum;

    money(sum);
    return 0;
}

