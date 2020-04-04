#include <iostream>
#include <string>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    std::cout << "a:" << a << "\nb:"<< b << std::endl;
}

//overloading
void swap(std::string &a, std::string &b){
    std:: string temp = a;
    a = b;
    b = temp;
    std::cout << "A:" << a << "\nB:"<< b << std::endl;

}


int main(){

    int a = 3;
    int b = 7;

    std::string A = "Caleb";
    std::string B = "Labec";

    std::cout << "a:" << a << "\nb:"<< b << std::endl;
    swap(a, b);
    std::cout << "a:" << a << "\nb:"<< b << std::endl;
    
    std::cout << "A:" << A << "\nB:"<< B << std::endl;
    swap(A, B);
    std::cout << "A:" << A << "\nB:"<< B << std::endl;
    
    
    return 0;
}