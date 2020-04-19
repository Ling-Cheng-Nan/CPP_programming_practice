#include <iostream>

using namespace std;
void print_array(int [], int);

void print_array(int array[], int size){
    int k = sizeof(array); //bytes of pointer of first array elements
    cout << sizeof(array) << endl;
    cout << size << endl;

}

int main(){
    int guess[] = {10, 20, 5, 41, 12, 3, 7, 2, 8, 1, 19, 37};
    int size = sizeof(guess)/sizeof(int);
    
    cout << sizeof(guess) << endl;
    cout << size << endl;
    
    // int num_elements = 5;
    // int size = sizeof(guess)/sizeof(int);

    
    // cout << size << endl;

    // for(int i = 0 ; i < num_elements ; i++){}
    // {
    //     cout << guess[i] << endl;
    // }

    print_array(guess, size);

    return 0;
}