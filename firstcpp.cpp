#include <iostream>
#include <cmath>

//directives
using namespace std ; //group different code to prevent naming conflicts

int main(){

    /*variables*/
    double base, exponent;

    cout << "Enter the base : " << endl;
    cin >> base;
    cout << "Enter the exponent : " << endl;
    cin >> exponent;
    cout << "the exponential of base " << base << " : " << pow(base, exponent);


    return 0;
}
