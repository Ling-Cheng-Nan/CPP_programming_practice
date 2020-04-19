#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
    
}

/*template functions with overloading*/
template <typename T>
void swap(T a[], T b[], int size){
    for(int i=0 ; i<size ; i++){
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
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
    
    int nines[] = {9,9,9,9,9,9,9,9};
    int ones[] = {1,1,1,1,1,1,1,1}; 
    int const SIZE = sizeof(nines)/sizeof(int);

    swap(nines, ones, SIZE);
    
    for(int i=0 ; i<SIZE ; i++){
        std::cout << "nines[" << i << "] = " << nines[i] << " \n";
    }
    

    for(int i=0 ; i<SIZE ; i++){
        std::cout << " ones[" << i << "] = " << ones[i] << " \n";
    }
    

    return 0;
}