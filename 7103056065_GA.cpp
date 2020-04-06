/*
Author : 凌政楠
Create Date : 2020/03/28
Program : Metaheuristic Algorithms
Assignment : implementation of Genetic Algorithm
Problem Description : 
    
    while(condition)
     |   
     |   1. Initial population
     |   2. Fitness function
     |   3. Selection
     |   4. Crossover
     |   5. Mutation
     |
    repeat step 1 - 5
*/

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

#define AmountOfPopulation 4 //子代數量
#define LengthOfChromosome 8 //染色體長度 (how many bits to encoded)
#define MinimumSelected AmountOfPopulation/2

/* directives */
using namespace std ; //group different code to prevent naming conflicts

/* function prototypes */
void showPopulation(int [][LengthOfChromosome+1]);
void initial_population(int [][LengthOfChromosome+1]);
void fitness_function(int [][LengthOfChromosome+1]);
void selection(int [][LengthOfChromosome+1]);
void crossover(int [][LengthOfChromosome+1], int);
void mutation();


int main(){

    /*variables declaration*/
    srand(time(NULL));
    int cut_index = 0;
    int str[AmountOfPopulation][LengthOfChromosome+1];
    int select[MinimumSelected][LengthOfChromosome+1];

    initial_population(str);
    showPopulation(str);
    fitness_function(str);
    showPopulation(str);
    selection(str);

    return 0;
}

/* function implementation */
void showPopulation(int str[][LengthOfChromosome+1]){
    cout << "  gene  | fitness" << endl;
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i < LengthOfChromosome+1 ; i++){
            if(i==LengthOfChromosome)
                cout << "|    " << str[j][i]  << endl;
            else
                cout << str[j][i];

        }
        // cout << endl;
    }
    cout << endl;

}

void initial_population(int str[][LengthOfChromosome+1]){
    
    cout << "...Initial Population..." << endl;
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i < LengthOfChromosome+1 ; i++){
            if( i == LengthOfChromosome ){
                str[j][i] = 0;
            }
            else{
                str[j][i] = rand()%2;
            }
        }
    }
}

void fitness_function(int str[][LengthOfChromosome+1]){
    
    cout << "...Fitness Fitness..." << endl;
    int fitness[LengthOfChromosome]={0};
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i <= LengthOfChromosome-1 ; i++){
           fitness[j] += (str[j][i])*pow(2, (LengthOfChromosome-1)-i);
        }

        str[j][LengthOfChromosome] = fitness[j];
        // cout << str[j][LengthOfChromosome] << endl;
    }
    
}

void selection(int str[][LengthOfChromosome+1]){
    
    int selected[MinimumSelected][LengthOfChromosome+1] = {0};
    bool usedindex[AmountOfPopulation] = {0};
    int flag = 0;
    int min = pow(2, LengthOfChromosome);
            
    for(int j = 0 ; j < MinimumSelected ; j++){
    
        for(int i = 0 ; i < AmountOfPopulation ; i++){
            //cout << usedindex[i] << endl;
            if(usedindex[i] == false && str[i][LengthOfChromosome] < min){
                min = str[i][LengthOfChromosome];
                flag = i;
            } 
        }

        // cout << "flag: "<< flag << endl;
        // cout << usedindex[flag] <<endl;
        // cout << "min: " << min << endl;

        for(int k = 0 ; k < LengthOfChromosome ; k++){
            selected[j][k] = str[flag][k];
            // cout << selected[j][k];
        }
        // cout << endl;
        
        //reset
        min = pow(2, LengthOfChromosome);
        usedindex[flag] = true;
        flag = 0;

    }

    crossover(selected, 3);
}

void crossover(int str[][LengthOfChromosome+1], int cut){
    int temp[AmountOfPopulation/2][LengthOfChromosome+1] = {0};
    
    for(int j = 0 ; j < AmountOfPopulation/2 ; j++){
        for(int i = 0; i < LengthOfChromosome ; i++){
            if(i <= cut){
                //copy half into temp
                temp[j][i] = str[j][i];
            }
            else if(i > cut){
                //copy another half into temp
                temp[j][i] = str[(j+1)%(AmountOfPopulation/2)][i];
            }
        }
    }

    cout << "temp" << endl;

    for(int i = 0; i < LengthOfChromosome ; i++){
        cout << temp[0][i];
    }

    cout << endl;
    for(int i = 0; i < LengthOfChromosome ; i++){
        cout << temp[1][i];
    }



}

void mutation(int str[][LengthOfChromosome+1]){
    /*generate mutation index*/
    int mutation_num = rand()%AmountOfPopulation+1;
    int mutation_gene = rand()%AmountOfPopulation;
    int mutation_index = rand()%LengthOfChromosome;


}