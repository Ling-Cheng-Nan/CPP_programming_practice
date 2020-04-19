#include <iostream>
#include <string>

void overwriteArray(int *a, int row, int col);
void showArray(int *a, int r, int c);
using namespace std;

int main(){
    int a[3][4] = {{0,0,0,0},{4,5,6,7},{8,9,10,11}};
    int *pA[3] ;
    int b[3][4] = {{101,123,201,333},{154,153,152,151},{18,19,200,21}};
    int *pB[3] ;

    for(int i = 0 ; i < 3 ; i++){
        pA[i] = &a[i][0];
        pB[i] = &b[i][0];
    }

    // cout << **pB << endl;
    // cout << *((*pB)+1) << endl;
    // cout << *((*pB)+1*sizeof(int)) << endl;

    overwriteArray(a[0],3,4);
    showArray(a[0],3,4);

    return 0;
}

void overwriteArray(int *a, int row, int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            *(a+i*row+j) += 20;
        }
        cout <<endl;

    }
}

void showArray(int *a, int r, int c){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << *(a+i*r+j) << " ";
        }
        cout <<endl;

    }
}