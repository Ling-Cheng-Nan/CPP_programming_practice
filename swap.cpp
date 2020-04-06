#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
    
}

//overloading
// void swap(std::string &a, std::string &b){
//     std:: string temp = a;
//     a = b;
//     b = temp;
//     std::cout << "A:" << a << "\nB:"<< b << std::endl;

// }

int main(){

    int a = 3;
    int b = 7;
    std::cout << "a:" << a << "\nb:"<< b << std::endl;
    swap(a, b);
    std::cout << "a:" << a << "\nb:"<< b << std::endl;


    std::string A = "Caleb";
    std::string B = "Labec";
    std::cout << "A:" << A << "\nB:"<< B << std::endl;
    swap(A, B);
    std::cout << "A:" << A << "\nB:"<< B << std::endl;
    
    
    return 0;
}