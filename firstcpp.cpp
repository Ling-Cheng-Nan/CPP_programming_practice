#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//directives
using namespace std ; //group different code to prevent naming conflicts
<<<<<<< HEAD

void play_game();

=======
string blurrTheFuck(string );
>>>>>>> 0f997a3d41e1ed008240315276c686e61682cbac
int main(){

    srand(time(NULL));
    
    /*variables*/
<<<<<<< HEAD
    int choice;
    do{
        cout << "0. Quit " << endl << "1. Play Game " << endl;
        cin >> choice;
=======
    string greeting ;//= "hello there, the abc is bca";
    getline(cin, greeting);

    cout << blurrTheFuck(greeting) << endl;
    //cout << greeting << endl;



>>>>>>> 0f997a3d41e1ed008240315276c686e61682cbac

        switch(choice){
            case 0 :
                cout << "You are going to leave this game." << endl;
                break;
            case 1 : 
                cout << "You are going to enter the new game." << endl;
                play_game();
                break;
            default : 
                cout << "Invalid input, try again!!" << endl;
                break;
        }
    }
    while(choice != 0);
    
    
    
    return 0;
}

<<<<<<< HEAD
void play_game(){
    cout << "Game is been played!\n";
    int random = rand() % 251;
    int guess;
    string message = "";
    cout << random << endl;
    cout << "Guess a number." << endl;

    
    while(true){
        cin >> guess;
        guess == random? message = "You win the game.": message = "Sorry, you lose the game.";
        
        if(guess > random){
            message = "You guess too high.";
        }
        else if(guess < random){
            message = "You guess too low.";
        }
        else {
            message = "Invalid guess, try again.";
        }

        cout << message << endl;


    }
=======
string blurrTheFuck(string str){
    return str.replace(str.find("fuck"), 4, "f**k") ;
    //cout << str << endl;
>>>>>>> 0f997a3d41e1ed008240315276c686e61682cbac

}