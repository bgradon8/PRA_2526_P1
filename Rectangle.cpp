#include "Rectangle.h"

Rectangle::Rectangle()
    : Shape(Point2D(0.0, 0.0)), width(1.0), height(1.0)
{
}

Rectangle::Rectangle(const Point2D& c, double width, double height)
    : Shape(c), width(width), height(height)
{
}

double Rectangle::get_width() const {
    return width;
}

double Rectangle::get_height() const {
    return height;
}

void Rectangle::set_width(double w) {
    width = w;
}

void Rectangle::set_height(double h) {
    height = h;
}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::draw(std::ostream& out) const {
    out << "Rectangle(center=" << center
        << ", width=" << width
        << ", height=" << height
        << ", area=" << area()
        << ")";
}
