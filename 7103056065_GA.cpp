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
#define AmountOfPopulation 4 //子代數量
#define LengthOfChromosome 8 //染色體長度 (how many bits to encoded)


/* directives */
using namespace std ; //group different code to prevent naming conflicts

/* function prototypes */
void showPopulation(int [][LengthOfChromosome+1]);
void initial_population(int [][LengthOfChromosome+1]);
void fitness_function(int [][LengthOfChromosome+1]);
void selection();
void crossover();
void mutation();


int main(){

    /*variables declaration*/
    int cut_index = 0;
    int str[AmountOfPopulation][LengthOfChromosome+1];
    
    //string *pstr = &str;
    initial_population(str);
    showPopulation(str);
    fitness_function(str);
    showPopulation(str);
    return 0;
}

/* function implementation */
void showPopulation(int str[][LengthOfChromosome+1]){
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i < LengthOfChromosome+1 ; i++){
            cout << str[j][i];
        }
        cout << endl;
    }
}

void initial_population(int str[][LengthOfChromosome+1]){
    cout << "...Initial Population..." << endl;
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i < LengthOfChromosome+1 ; i++){
            str[j][i] = rand()%2;
        }
    }
}

void fitness_function(int str[][LengthOfChromosome+1]){
    
    
}
void selection(){}
void crossover(){}
void mutation(){}