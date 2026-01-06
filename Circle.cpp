#include "Circle.h"
#include <cmath>

Circle::Circle()
    : Shape(Point2D(0.0, 0.0)), radius(1.0)
{
}

Circle::Circle(const Point2D& c, double radius)
    : Shape(c), radius(radius)
{
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

void Circle::draw(std::ostream& out) const {
    out << "Circle(center=" << center
        << ", radius=" << radius
        << ", area=" << area()
        << ")";
}
