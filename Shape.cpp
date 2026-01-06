#include "Shape.h"

Shape::Shape()
    : center(Point2D(0.0, 0.0))
{
}

Shape::Shape(const Point2D& c)
    : center(c)
{
}

Shape::~Shape() {
}

Point2D Shape::get_center() const {
    return center;
}

void Shape::set_center(const Point2D& c) {
    center = c;
}

void Shape::move(double dx, double dy) {
    center.translate(dx, dy);
}

std::ostream& operator<<(std::ostream& out, const Shape& s) {
    s.draw(out);
    return out;
}
