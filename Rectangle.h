#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(const Point2D& c, double width, double height);

    double get_width() const;
    double get_height() const;

    void set_width(double w);
    void set_height(double h);

    double area() const override;
    void draw(std::ostream& out) const override;
};

#endif
