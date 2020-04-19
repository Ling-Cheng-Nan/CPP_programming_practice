#include "header.h"
namespace utilz{

    double area(double len, double wid){
        return len * wid;
    }

    double area(double length){
        return length*length;
    }

    double area(Rectangle re){
        return re.length*re.width;
    }

    double pow(double base, double exp = 2){
        double total = 1;
        for(int i = 0 ; i < exp ; i++){
            total *= base;
        }
        return total;
    }

}
