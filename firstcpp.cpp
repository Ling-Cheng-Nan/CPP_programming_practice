#include <iostream>
#include <string>

//directives
using namespace std ; //group different code to prevent naming conflicts
string blurrTheFuck(string );
int main(){

    /*variables*/
    string greeting ;//= "hello there, the abc is bca";
    getline(cin, greeting);

    cout << blurrTheFuck(greeting) << endl;
    //cout << greeting << endl;




    return 0;
}

string blurrTheFuck(string str){
    return str.replace(str.find("fuck"), 4, "f**k") ;
    //cout << str << endl;

}