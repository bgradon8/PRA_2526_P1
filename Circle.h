#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle();
    Circle(const Point2D& c, double radius);

    double get_radius() const;
    void set_radius(double r);

    double area() const override;
    void draw(std::ostream& out) const override;
};

#endif
