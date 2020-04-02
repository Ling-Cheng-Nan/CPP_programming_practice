#include <iostream>
#include <string>

using namespace std;

int main(){

    char alphabet;
    bool pass = false;
    string grade = "";
    // enum PASS {failed, passed};
    
    cin >> alphabet;
    switch(alphabet){
        case 'A':
            grade = "grade 99 ~ 90,";
            pass = true;
            break;
        case 'B':
            grade = "grade 89 ~ 80,";
            pass = true;
            break;
        case 'C':
            grade = "grade 79 ~ 70,";
            pass = true;
            break;
        case 'D':
            grade = "grade 69 ~ 60,";
            pass = true;
            break;
        case 'F':
            grade = "grade < 60,";
            pass = false;
            break;
        default:
            grade = "grade undefined,";
            pass = false;
            break;        
    }

    cout << "you got " << alphabet << " which range of " 
    << grade  << endl;
    
    return 0;
}