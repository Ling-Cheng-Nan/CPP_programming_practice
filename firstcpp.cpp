#include <iostream>

//directives
using namespace std ; //group different code to prevent naming conflicts

void test();

int main(){

    /*variables*/
    int slice = 5;
    double aa = 10.3;
    bool flag = false;

    std::cout<<"Hello World!\n";
    test();

    cout << slice ;
    return 0;
}

void test(){
    cout << "Hello World!!! in test function\n";
}