 #include <iostream>
  #include <vector>


   double average_of(std::vector<int> &vi) {

     double sum = 0;

     for (int p:vi){

        std::cout << "Number is: " << p << std::endl;
        sum = sum + p;
     }

     return (sum/vi.size());
    }

    int main(){

        std::vector <int>vi =  {3,5,7,10,17};
        double val;

        val = average_of(vi);

        std::cout << "average is: " << val << std::endl;
        return 0;
    }
