#include <iostream>

//directives
using namespace std ; //group different code to prevent naming conflicts

int multiply(int , int);


int main(){

    /*variables*/
    int slice ;
    double aa = 10.3;
    bool flag  = false;
    string str = ""; 

    std::cout<<"Hello World!\n"; 
    cout << "Enter the number of pizza you want to eat: " << endl;
    cin  >> slice;
    cout << "You have " << slice << " slices of pizza." << endl ;
    cout << multiply(30, 5) << endl ;
    
    return 0;
}

int multiply(int x, int y){
    return x*y;
}