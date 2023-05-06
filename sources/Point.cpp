#include "Point.hpp"
#include <ostream>
#include <iostream>

namespace ariel{}
using namespace std;

Point::Point(){
    this->x=0;
    this->y=0;
}
Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

double Point::distance(Point point){
    return 0.0;
}

void Point::print(){
    cout << "(" + to_string(this->x) + "," + to_string(this->y) + ")"<<endl;
}

Point Point::moveTowards(Point from, Point goal, double distance){
    return Point;
}