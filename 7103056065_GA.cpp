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
void showPopulation(int [][LengthOfChromosome+1], int);
void initial_population(int [][LengthOfChromosome+1]);
void fitness_function(int [][LengthOfChromosome+1], int);
void selection(int [][LengthOfChromosome+1], int [][LengthOfChromosome+1]);
void crossover(int [][LengthOfChromosome+1], int, int (*)[LengthOfChromosome+1], int AmountOfPopulation);
void mutation();


int main(){

    /*variables declaration*/
    srand(time(NULL));
    int cut_index = 0;
    int candidate_gene[AmountOfPopulation][LengthOfChromosome+1];
    int select[MinimumSelected][LengthOfChromosome+1];
    int temp[MinimumSelected][LengthOfChromosome+1];

    initial_population(candidate_gene);
    
    // while(){
        fitness_function(candidate_gene, AmountOfPopulation);
        showPopulation(candidate_gene, AmountOfPopulation);

        selection(candidate_gene, select);
        crossover(select, MinimumSelected+1);

        fitness_function(select, MinimumSelected);
        //showPopulation(select, MinimumSelected);

        showPopulation(candidate_gene, AmountOfPopulation);
    // };

    return 0;
}

/* function implementation */
void showPopulation(int gen[][LengthOfChromosome+1], int num){
    cout << "  gene  | fitness" << endl;
    for(int j = 0 ; j < num ; j++){
        for(int i = 0 ; i < LengthOfChromosome+1 ; i++){
            if(i==LengthOfChromosome)
                cout << "|    " << gen[j][i]  << endl;
            else
                cout << gen[j][i];

        }
        // cout << endl;
    }
    cout << endl;

}

void initial_population(int gen[][LengthOfChromosome+1]){
    
    cout << "...Initial Population..." << endl;
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i < LengthOfChromosome+1 ; i++){
            if( i == LengthOfChromosome ){
                gen[j][i] = 0;
            }
            else{
                gen[j][i] = rand()%2;
            }
        }
    }
}

void fitness_function(int gen[][LengthOfChromosome+1], int num){
    
    cout << "...Fitness Fitness..." << endl;
    int fitness[LengthOfChromosome]={0};
    for(int j = 0 ; j < num ; j++){
        for(int i = 0 ; i <= LengthOfChromosome-1 ; i++){
           fitness[j] += (gen[j][i])*pow(2, (LengthOfChromosome-1)-i);
        }

        gen[j][LengthOfChromosome] = fitness[j];
        // cout << gen[j][LengthOfChromosome] << endl;
    }
    
}

void selection(int gen[][LengthOfChromosome+1], int selected[][LengthOfChromosome+1]){
    
    //int selected[MinimumSelected][LengthOfChromosome+1] = {0};
    bool usedindex[AmountOfPopulation] = {0};
    int flag = 0;
    int min = pow(2, LengthOfChromosome);
            
    for(int j = 0 ; j < MinimumSelected ; j++){
    
        for(int i = 0 ; i < AmountOfPopulation ; i++){
            //cout << usedindex[i] << endl;
            if(usedindex[i] == false && gen[i][LengthOfChromosome] < min){
                min = gen[i][LengthOfChromosome];
                flag = i;
            } 
        }

        // cout << "flag: "<< flag << endl;
        // cout << usedindex[flag] <<endl;
        // cout << "min: " << min << endl;

        for(int k = 0 ; k < LengthOfChromosome ; k++){
            selected[j][k] = gen[flag][k];
            // cout << selected[j][k];
        }
        // cout << endl;
        
        //reset
        min = pow(2, LengthOfChromosome);
        usedindex[flag] = true;
        flag = 0;

    }

    
}

void crossover(int gen[][LengthOfChromosome+1], int cut, int (*)[LengthOfChromosome+1], int amt){
    
    cout << ".....Cross Over....." << endl;
    int temp[MinimumSelected][LengthOfChromosome+1] = {0};
    int new_candidate[AmountOfPopulation][LengthOfChromosome+1] = {0};

    for(int j = 0 ; j < MinimumSelected ; j++){
        for(int i = 0; i < LengthOfChromosome ; i++){
            if(i <= cut){
                //copy half into temp
                temp[j][i] = gen[j][i];
            }
            else if(i > cut){
                //copy another half into temp
                temp[j][i] = gen[(j+1)%(MinimumSelected)][i];
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
    cout << endl;

    cout << "new candidate"<< endl;
    for(int j = 0 ; j < AmountOfPopulation ; j++){
        for(int i = 0 ; i < LengthOfChromosome ; i++){
            if(j < MinimumSelected) 
                new_candidate[j][i] = gen[j][i];
            else 
                new_candidate[j][i] = temp[j-MinimumSelected][i];

            cout << new_candidate[j][i];
        }

        cout << endl;
    }




}

void mutation(int gen[][LengthOfChromosome+1]){
    /*generate mutation index*/
    int mutation_num = rand()%AmountOfPopulation+1;
    int mutation_gene = rand()%AmountOfPopulation;
    int mutation_index = rand()%LengthOfChromosome;


}