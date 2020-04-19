#include <iostream>
#include <string>

/* Knapsack-Problem parameters definition */
#define CAPACITY 27.5
#define ITEM_QTY 10
#define ITEM_PRICE_ROW sizeof(item_price)/sizeof(item_price[0])

/* Genetic Algorithm parameters definition */
#define GENERATION_ITERATE 10
#define PARTICLE_AMT 4

/* namespace used */
using namespace std;

/* function prototype */
void showArray(double [][ITEM_QTY], int);
void determineItemPrice(double [][ITEM_QTY]);
void initialization(double [][ITEM_QTY], int);
void display_dashboard(double [][ITEM_QTY], double [][2], int);
void fitness(double [][ITEM_QTY], double [][2], int);
void selection(double [][ITEM_QTY], double [][2], int);
void crossover(double [][ITEM_QTY], int);
void mutation(double [][ITEM_QTY], int);

int main(){
    
    /* variable declaration */
    srand(time(NULL));

    double bag_size = CAPACITY;
    double item_price[2][ITEM_QTY] = {0};
    double bag_profit[PARTICLE_AMT][2] = {0};
    double candidates[PARTICLE_AMT][ITEM_QTY] = {0};



    /* program code start */
    determineItemPrice(item_price);
    // showArray(item_price, ITEM_PRICE_ROW);
    initialization(candidates, PARTICLE_AMT);
    // display_dashboard(candidates, bag_profit, PARTICLE_AMT);

    // for(int g = 0 ; g < GENERATION_ITERATE ; g++){
    //     cout << "==== Generation: " << g+1 << "====" << endl;
        fitness(candidates, bag_profit, PARTICLE_AMT);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);
        
        selection(candidates, bag_profit, PARTICLE_AMT);
        fitness(candidates, bag_profit, PARTICLE_AMT);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);
        
        crossover(candidates, PARTICLE_AMT);
        fitness(candidates, bag_profit, PARTICLE_AMT);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);

        mutation(candidates, PARTICLE_AMT);
        fitness(candidates, bag_profit, PARTICLE_AMT);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);

    // }   

    return 0;
}


/* function definition */
void display_dashboard(double array[][ITEM_QTY], double bagprofit[][2], int particle){
    
    cout << "index |==0==1==2==3==4==5==6==7==8==9|========|========" << endl;
    cout << "weight|==1==2==3==4==5==6==7==8==9=10|=weight=|=profit=" << endl;
    cout << "value |==6==7==8==9=10=11=12=13=14=15|========|========" << endl;
    for(int i = 0 ; i < particle ; i++){
        
        cout << "item " << i << "|" ;
        for(int j = 0 ; j < ITEM_QTY ; j++){
            cout << "  " << array[i][j] ;
        }

        for(int j = 0 ; j < 2 ; j++){
            cout << "|      " << bagprofit[i][j] ;
        }

        cout << endl;
    }
}

void showArray(double array[][ITEM_QTY],int size){
    
    for(int i = 0 ; i < size ; i++){
        for(int j = 0; j < ITEM_QTY ; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void determineItemPrice(double item[][ITEM_QTY]){
    for(int j = 0 ; j < ITEM_QTY ; j++){
        item[0][j] = (j+1);
        item[1][j] = (item[0][j]+5);
    }    
}

void initialization(double cand[][ITEM_QTY], int row_size){
    
    cout << "\nAfter Initialization" << endl;
    for(int i = 0 ; i < row_size ; i++){
        for(int j = 0 ; j < ITEM_QTY ; j++){
            cand[i][j] = rand()%2;
        }
    }

    for(int i = 0; i < row_size ; i++){
        for(int i = 0 ; i < ITEM_QTY ; i++){
            
        }
    }
}

void fitness(double cand[][ITEM_QTY], double bag_profit[][2], int particle){
    
    int index_sum = 0; //sum of indice
    int value = 0; //count of 1s

    // cout << "\nAfter Fitness" << endl;
    for(int i = 0 ; i < particle ; i++){
        for(int j = 0 ; j < ITEM_QTY ; j++){
            if(cand[i][j]==1){
                index_sum += (j+1);
                value += (j+1)+5;
            }
        }

        //weight at index 0
        bag_profit[i][0] = index_sum;
        
        //profit at index 1
        bag_profit[i][1] = value;

        value = 0;
        index_sum = 0;

    }
}

void selection(double cand[][ITEM_QTY], double bagprofit[][2], int particle){
    
    double min = 2048;
    double cur_min = 2049;
    double temp[particle/2][ITEM_QTY];
    int min_index[particle/2];
    int slct_index;

    cout << "\nAfter Selection" << endl;
    for(int i = 0 ; i < particle/2 ; i++){
        min_index[i] = -1;
    }

    for(int i = 0 ; i < particle/2 ; i++){
        for(int j = 0 ; j < particle ; j++){
            
                if((bagprofit[j][1] < min)){
                    
                    for(int k = 0 ; k < particle/2 ; k++){
                        if(min_index[k] != j && bagprofit[j][1] != cur_min){ 
                            min = bagprofit[j][1];
                            min_index[i] = j;
                        }
                    }
                }
            
        }
        /*found another min*/
        cur_min = min;
        min = 2048;
    }

    /*copy selected content into temp array*/
    for(int i = 0 ; i < particle/2 ; i++){
        
        slct_index = min_index[i];
        for(int k = 0 ; k < ITEM_QTY ; k++){
            temp[i][k] = cand[slct_index][k];
        }
    }
    
    // //check out content of min_index
    // for(int h = 0 ; h < particle/2 ; h++){
    //     cout << min_index[h] << " ";
    // }
    // cout << endl;

    // showArray(temp, particle/2);

    /*move half least to prior half*/
    for(int i = 0 ; i < particle ; i++){
        for(int j=0 ; j < ITEM_QTY ; j++){
            if(i < particle/2)
                cand[i][j] = temp[i][j];
            else
                cand[i][j] = 0;
        }
    }
}


void crossover(double cand[][ITEM_QTY], int particle){
    
    int temp [particle/2][ITEM_QTY];
    int cut_index = ITEM_QTY/2;
    int half_flag = particle/2;

    cout << "\nAfter Crossover" << endl;
    for(int i = 0 ; i < particle/2 ; i++){
        for(int j = 0 ; j < ITEM_QTY ; j++){
            if(j < cut_index)
                temp[i][j] = cand[i][j];
            if(j >= cut_index)
                temp[i][j] = cand[half_flag-i-1][j];
        }
    }

    // /*check out the content of temp array after crossover*/
    // for(int i = 0 ; i < particle/2 ; i++){
    //     for(int j = 0 ; j < ITEM_QTY ; j++){
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    /*copy temp into another half candidate */
    for(int i = particle/2 ; i < particle ; i++){
        for(int j = 0 ; j < ITEM_QTY ; j++){
            cand[i][j] = temp[i-half_flag][j];
        }
    }
    
}

void mutation(double cand[][ITEM_QTY], int particle){
    /* unsure mutate from children destination */
    srand(time(NULL));
    int half = PARTICLE_AMT/2;
    int mut_index, chance; 
    
    cout << "\nAfter Mutation" << endl;
    for(int i = 0 ; i < particle ; i++){
        
        chance = rand()%2;
        // cout << "chance : " << chance << endl;
        
        for(int j = 0 ; j < ITEM_QTY ; j++){

            
            if(i >= half && chance){

                mut_index = rand()%ITEM_QTY;

                // cout << "mutate on particle " << i << endl;
                // cout << "mutate on index " << mut_index << endl;
                if(cand[i][mut_index] == 1)
                    cand[i][mut_index] = 0;
                else 
                    cand[i][mut_index] = 1;
                
                break;
            }
        }
    }
}


