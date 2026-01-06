
#ifndef SHAPE_H
#define SHAPE_H

#include <ostream>
#include "Point2D.h"

class Shape {
protected:
    Point2D center;

public:
    Shape();
    Shape(const Point2D& c);
    virtual ~Shape();

    Point2D get_center() const;
    void set_center(const Point2D& c);
    void move(double dx, double dy);

    virtual double area() const = 0;
    virtual void draw(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& s);
};

#endif
