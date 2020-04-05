#include <iostream>
#include "header.h"


int main(){
    Rectangle rec = {1.2, 4.5};
    std::cout << "Area of rec : " << area(rec.length, rec.width) << std::endl;
    Rectangle squ = {1.2, 1.2};
    std::cout << "Area of squ : " << area(squ.length) << std::endl;
    Rectangle poly = {1.3, 7};
    std::cout << "Area of poly : " << area(poly) << std::endl;
    
    std::cout << pow(2,9) << std::endl;


    return 0;
}

