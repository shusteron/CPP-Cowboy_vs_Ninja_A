#include "Point.hpp"
#include <ostream>
#include <iostream>

namespace ariel{}
using namespace std;


Point::Point(double x, double y){
    this->_x_ = x;
    this->_y_ = y;
}

double Point::distance(Point point){
    return -1;
}

void Point::print(){
    cout << "(" + to_string(this->_x_) + "," + to_string(this->_y_) + ")"<<endl;
}

Point Point::moveTowards(Point from, Point goal, double distance){
    return Point(0,0);
}

double Point::getX(){
    return this->_x_;
}

double Point::getY(){
    return this->_y_;
}