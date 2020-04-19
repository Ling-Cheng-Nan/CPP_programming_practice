#include <iostream>

class Position{

    public:
        int x = 10;
        int y = 20;
    
        Position operator + (Position pos){
           
            Position new_pos; 
            new_pos.x = x + pos.x;
            new_pos.y = y + pos.y;

            return new_pos;
        }

        bool operator == (Position pos){
           
            // Position new_pos; 
            //bool same;
            if(x ==  pos.x && y ==  pos.y){
                return true;
            }
            else 
                return false;

        }        

};

int main(){
    
    Position pos1, pos2;
    pos1.x = -17;
    pos1.y = 14;

    pos2.x = 20;
    pos2.y = 15;

    Position pos3 = pos1 + pos2;

    std::cout << "position of pos3 : (" << pos3.x << ", "<< pos3.y << ")" << std::endl;
    
    pos2.x = -17;
    pos2.y = 14;
    if(pos1 == pos2){
        std::cout << "pos1 and pos2 are the same."<< std::endl;
    }
    else{
        std::cout << "pos1 and pos2 are NOT the same."<< std::endl;
    }



    return 0;
}