#include "Point.hpp"
#include <ostream>
#include <iostream>

namespace ariel{}
using namespace std;


Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

double Point::distance(Point point){
    return -1;
}

void Point::print(){
    cout << "(" + to_string(this->x) + "," + to_string(this->y) + ")"<<endl;
}

Point Point::moveTowards(Point from, Point goal, double distance){
    return Point(0,0);
}

double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}