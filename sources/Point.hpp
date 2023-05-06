#ifndef POINT_HPP
#define POINT_HPP

#include <stdio.h>

namespace ariel{}
using namespace std;

class Point{
    private:
        double x;
        double y;

    public:
        Point(double x, double y);   
        double distance(Point point);
        void print(); 
        Point moveTowards(Point from, Point goal, double distance);
};

#endif
