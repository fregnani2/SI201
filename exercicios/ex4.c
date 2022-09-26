/*struct point represents the x and y coordinates of a point in two dimensional space.
The points in the struct rectangle represent the points at the upper left and lower right corners of a rectangle in two dimensional space.
Write a function area() that takes a rectangle struct as its parameter, and returns the area of the rectangle. */

#include <stdio.h>

typedef struct point {
    int x;
    int y;
}point;

typedef struct rectangle {
    point upperLeft;
    point lowerRight;
}rectangle;

int area(rectangle r){
    return (r.lowerRight.x - r.upperLeft.x) * (r.upperLeft.y - r.lowerRight.y);
}
int main(){
    point p;
    p.x = 7;
    p.y = 4;
    
    point p2;
    p2.x = 4;
    p2.y = 7;

    rectangle rec;
    rec.lowerRight = p;
    rec.upperLeft = p2;

    printf("Area = %d", area(rec));
}