#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//directives
using namespace std ; //group different code to prevent naming conflicts

void play_game();

int main(){

    srand(time(NULL));
    
    /*variables*/
    int choice;
    do{
        cout << "0. Quit " << endl << "1. Play Game " << endl;
        cin >> choice;

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

}