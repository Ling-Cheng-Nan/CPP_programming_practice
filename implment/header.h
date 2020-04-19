#ifndef MATH
#define MATH

typedef struct rectangle{
    double length;
    double width;

} Rectangle;

namespace utilz {
    double area(double, double);
    double area(double);
    double area(Rectangle);
    double pow(double , double);
}

#endif