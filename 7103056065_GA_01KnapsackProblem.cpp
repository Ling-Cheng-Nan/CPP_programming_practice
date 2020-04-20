#include <iostream>
#include <string>
#include <ctime>
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
void initialization(double [][ITEM_QTY], int, double [][2]);
void display_dashboard(double [][ITEM_QTY], double [][2], int);
void fitness(double [][ITEM_QTY], double [][2], int);
void selection(double [][ITEM_QTY], double [][2], int);
void crossover(double [][ITEM_QTY], int, double [][2]);
void mutation(double [][ITEM_QTY], int, double [][2]);
int getMostValue(double [][2], int);

int main(){
    
    /* variable declaration */
    srand(time(NULL));

    double bag_size = CAPACITY;
    double item_price[2][ITEM_QTY] = {0};
    double bag_profit[PARTICLE_AMT][2] = {0};
    double candidates[PARTICLE_AMT][ITEM_QTY] = {0};
    int most_i = -1;


    /* program code start */
    determineItemPrice(item_price);
    // showArray(item_price, ITEM_PRICE_ROW);
    initialization(candidates, PARTICLE_AMT, bag_profit);
    display_dashboard(candidates, bag_profit, PARTICLE_AMT);

    for(int g = 0 ; g < GENERATION_ITERATE ; g++){
        cout << "\n==== Generation: " << g+1 << "====";
        
        selection(candidates, bag_profit, PARTICLE_AMT);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);
        
        fitness(candidates, bag_profit, PARTICLE_AMT);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);

        crossover(candidates, PARTICLE_AMT, bag_profit);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);

        mutation(candidates, PARTICLE_AMT, bag_profit);
        display_dashboard(candidates, bag_profit, PARTICLE_AMT);

        most_i = getMostValue(bag_profit, PARTICLE_AMT);

    }   

    cout << "\nThs most valuable item is at index : " << most_i << endl; 
    cout << "Total weight for the item is : " << bag_profit[most_i][0] << endl;
    cout << "Total price  for the item is : " << bag_profit[most_i][1] << endl;

    return 0;
}


/* function definition */
void display_dashboard(double array[][ITEM_QTY], double bagprofit[][2], int particle){
    
    cout << "index |  0  1  2  3  4  5  6  7  8  9|        |        " << endl;
    cout << "weight|  1  2  3  4  5  6  7  8  9 10| weight | profit " << endl;
    cout << "value |  6  7  8  9 10 11 12 13 14 15|  sum   |  sum   " << endl;
    cout << "------|------------------------------|--------|--------" << endl;

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

void initialization(double cand[][ITEM_QTY], int row_size, double bagprofit[][2]){
    
    cout << "\nAfter Initialization" << endl;
    for(int i = 0 ; i < row_size ; i++){
        for(int j = 0 ; j < ITEM_QTY ; j++){
            cand[i][j] = rand()%2;
        }
    }


    int index_sum = 0; //sum of indice
    int value = 0; //count of 1s
    
    for(int i = 0 ; i < row_size ; i++){
        for(int j = 0 ; j < ITEM_QTY ; j++){
            if(cand[i][j]==1){
                index_sum += (j+1);
            }
        }

        //weight at index 0
        bagprofit[i][0] = index_sum;
        index_sum = 0;

    }

    index_sum = 0; //sum of indice
    value = 0; //count of 1s

    for(int k = 0; k < row_size ; k++){
        /*check the weight is larger than max-capacity of the bag*/
        while(bagprofit[k][0] > CAPACITY){
            
            /*re-initialize*/
            for(int j = 0 ; j < ITEM_QTY ; j++){
                cand[k][j] = rand()%2;
                if(cand[k][j]==1){
                    index_sum += (j+1);
                    value += (j+1)+5;
                }
            }
                
            //weight at index 0
            bagprofit[k][0] = index_sum;
            
            //profit at index 1
            bagprofit[k][1] = value;

            // cout << "bagprofit[k][0] = " << bagprofit[k][0] << endl;
            value = 0;
            index_sum = 0;
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
    
    double max = 0;
    double cur_max = -1;
    double temp[particle/2][ITEM_QTY];
    int max_index[particle/2];
    int slct_index;

    cout << "\nAfter Selection" << endl;
    for(int i = 0 ; i < particle/2 ; i++){
        max_index[i] = -1;
    }

    for(int i = 0 ; i < particle/2 ; i++){
        for(int j = 0 ; j < particle ; j++){
            
                if((bagprofit[j][0] >= 0 && bagprofit[j][0] <= CAPACITY) && (bagprofit[j][1] > max)){
                    
                    for(int k = 0 ; k < particle/2 ; k++){
                        if(max_index[k] != j && bagprofit[j][1] != cur_max ){ 
                            max = bagprofit[j][1];
                            max_index[i] = j;
                        }
                    }
                }
            
        }
        /*found another min*/
        cur_max = max;
        max = 0;
    }

    /*copy selected content into temp array*/
    for(int i = 0 ; i < particle/2 ; i++){
        
        slct_index = max_index[i];
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
        bagprofit[i][0] = index_sum;
        
        //profit at index 1
        bagprofit[i][1] = value;

        value = 0;
        index_sum = 0;

    }
}

void crossover(double cand[][ITEM_QTY], int particle,double bagprofit[][2]){
    
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
        bagprofit[i][0] = index_sum;
        
        //profit at index 1
        bagprofit[i][1] = value;

        value = 0;
        index_sum = 0;

    }
    
}

void mutation(double cand[][ITEM_QTY], int particle, double bagprofit[][2]){
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
        bagprofit[i][0] = index_sum;
        
        //profit at index 1
        bagprofit[i][1] = value;

        value = 0;
        index_sum = 0;

    }
}

int getMostValue(double bagprofit[][2], int particle){
    int most_i = -1;
    double max = -1;
    for(int i = 0 ; i < particle ; i++){
        if((bagprofit[i][0]>=0 && bagprofit[i][0] <= CAPACITY) && bagprofit[i][1] > max){    
            max = bagprofit[i][1];
            most_i = i;
        }
    }
    return most_i;
}

