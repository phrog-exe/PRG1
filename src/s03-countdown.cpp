#include <iostream>

int main(int argc, char* argv[]) -> int {

auto a = std::stoi(argv[1]);

do
{
std::cout << a << "...\n";

a = a-1;
}

while (a>=0);

return 0;
}
