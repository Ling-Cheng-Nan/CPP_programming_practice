#include <iostream>
#include "header.h"

namespace sam{
    void printk(){
        printf("execute the function inthe customize namespace sam.\n");
    }
}

using namespace sam;

int main(){
    Rectangle rec = {1.2, 4.5};
    std::cout << "Area of rec : " << utilz::area(rec.length, rec.width) << std::endl;
    Rectangle squ = {1.2, 1.2};
    std::cout << "Area of squ : " << utilz::area(squ.length) << std::endl;
    Rectangle poly = {1.3, 7};
    std::cout << "Area of poly : " << utilz::area(poly) << std::endl;
    
    std::cout << utilz::pow(2,9) << std::endl;
    printk();

    return 0;
}

