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
void evaluate_weight(double cand[][ITEM_QTY], double bag_profit[][2], int particle);

int main(){
    
    /* variable declaration */
    srand(time(NULL));
    double bag_size = CAPACITY;
    double item_price[2][ITEM_QTY] = {0};
    double bag_profit[PARTICLE_AMT][2] = {0};
    double candidates[PARTICLE_AMT][ITEM_QTY] = {0};
    int cut_index = -1;



    /* program code start */
    determineItemPrice(item_price);
    // showArray(item_price, ITEM_PRICE_ROW);
    initialization(candidates, PARTICLE_AMT);
    // display_dashboard(candidates, bag_profit, PARTICLE_AMT);

    // while(){
        evaluate_weight(candidates, bag_profit, PARTICLE_AMT);
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

void evaluate_weight(double cand[][ITEM_QTY], double bag_profit[][2], int particle){
    
    int index_sum = 0; //sum of indice
    int value = 0; //count of 1s

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
    
    int min_index[particle/2];
    
    for(int i = 0 ; i < particle ; i++){

    }
}



