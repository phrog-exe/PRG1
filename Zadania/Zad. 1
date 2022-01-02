#include <iostream>
#include <sstream>
#include <string>

int main() {
  int granica, dzielna=1, dzielnik;
  std::cout<<"granica: ";
  std::cin>>granica;
  while(dzielna<=granica) {
    for(dzielnik=2; dzielnik<=dzielna; dzielnik++) {
      if(dzielna%dzielnik==0) {
        if (dzielna==dzielnik)
            std::cout<<" | "<<dzielna<<" | "<<dzielna;
            else break;
      }
    }
    dzielna++;
  }
  return 0;
}
