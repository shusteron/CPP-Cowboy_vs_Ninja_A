#ifndef POINT_HPP
#define POINT_HPP

#include <stdio.h>

namespace ariel{}

class Point{
    private:
        double x;
        double y;

    public:
        Point(double x, double y);   
        double distance(Point point);
        void print(); 
        static Point moveTowards(Point from, Point goal, double distance);
        double getX();
        double getY();
};

#endif
