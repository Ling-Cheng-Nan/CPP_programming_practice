#include <iostream>
void passByRef(int &y){
    y = 9;
}

void passByRef2(int* y){
    *y = 8;
}


int main(){
    
    int x = 1;
    int z[3] = {3,2,1};
    int* px = &x;

    std::cout << x << std::endl;
    std::cout << z[1] << std::endl;

    passByRef(x);
    passByRef(z[1]);

    std::cout << x << std::endl;
    std::cout << z[1] << std::endl;


    std::cout << x << std::endl;
    passByRef2(px);
    std::cout << x << std::endl;

    return 0;
}