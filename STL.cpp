#include <iostream>
#include <vector>
#include <array> //template

int  main(){
    int data[] = {1,4,7};
    std::vector <int> array = {1,2,3};
    std::array <int, 5> STL_array = {1,2,3,4,5};
    
    for(int n : data){
        std::cout << n << " ";
    }

    std::cout << std::endl;

    return 0;
}