#include <iostream>

//directives
using namespace std ; //group different code to prevent naming conflicts

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
    
    printf("printf print out %d slices \n", slice);
    return 0;
}
