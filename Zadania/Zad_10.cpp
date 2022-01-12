#include <iostream>
#include <string>

void box_print() {

 std::string word;
 std::string w[5];
 int length[5];
 int width;
 int s_val;
 int dl=0;

  std::cout << "Type in 5 words: " << std::endl;
   for (int i=0; i < 5; i++){
    std::cin >> word;
    s_val = word.size();
    w[i] = word;
      length[i] = s_val;
       if(dl < s_val)
         dl = s_val;
 }

    width = dl + 2;
    for(int i=0; i < width+2; i++) {
            std::cout<<"*";
            
        }
std::cout << std::endl;
 
   for (int j = 0; j < 5; j++)
    {
        std::cout << "* ";
        std::cout << w[j];

        for(int i = 0; i < s_val - length[j] + 1; i++)
        {
            std::cout << " ";
        }
        std::cout << "*";
        std::cout << std::endl;
    }

    for (int i = 0; i < width+2; i++)
        std::cout << "*";

}
int main()
{
    box_print();
    return 0;
}
