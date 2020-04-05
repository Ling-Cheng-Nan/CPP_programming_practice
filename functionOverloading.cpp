#include <iostream>

typedef struct rectangle{
    double length;
    double width;

} Rectangle;

double area(double, double);
double area(double);
double area(Rectangle);
double pow(double , double);


int main(){
    Rectangle rec = {1.2, 4.5};
    std::cout << "Area of rec : " << area(rec.length, rec.width) << std::endl;
    Rectangle squ = {1.2, 1.2};
    std::cout << "Area of squ : " << area(squ.length) << std::endl;
    Rectangle poly = {1.3, 7};
    std::cout << "Area of poly : " << area(poly) << std::endl;
    
    std::cout << pow(2,9) << std::endl;


    return 0;
}

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