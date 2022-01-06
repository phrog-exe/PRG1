#include <iostream>
#include <string>

int main()
{
    std::string a;
        int cn, male = 0, female = 0;
    std::cout << "Wprowadz 5 imion: \n";
    for (int i = 0; i < 5; i++)
    {
        cn = 0;
        std::cin >> a;
        cn = a.size();
        if (a[cn - 1] == 'a')
            female++;
        else male++;
    }
    std::cout << "Imion meskich jest: " << male << "\n";
    std::cout << "Imion damskich jest: " << female <<"\n";
    return 0;
}
