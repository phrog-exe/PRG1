#include <iostream>

dot_product() {
float vectorA[2], vectorB[2], scalar=0.0;

 std::cout << "Type in coordinates of vector A: " << std::endl;
   for(int i=0;i<2;i++) {
     std::cin >> vectorA[i];
     }
     
 std::cout << "Type in coordinates of vector B: " << std::endl;
   for(int i=0;i<2;i++) {
     std::cin >> vectorB[i];
    }

   for(int i=0;i<2;i++) {
     scalar = scalar + (vectorA[i] * vectorB[i]);
}


std::cout << "Dot product: " << scalar << std::endl;



}

int main()
{
dot_product();
return 0;
}
