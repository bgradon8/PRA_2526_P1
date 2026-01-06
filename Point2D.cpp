#include "Point2D.h"

Point2D::Point2D()
    : x(0.0), y(0.0)
{
}

Point2D::Point2D(double x, double y)
    : x(x), y(y)
{
}

double Point2D::get_x() const {
    return x;
}

double Point2D::get_y() const {
    return y;
}

void Point2D::set_x(double x) {
    this->x = x;
}

void Point2D::set_y(double y) {
    this->y = y;
}

void Point2D::translate(double dx, double dy) {
    x += dx;
    y += dy;
}

double Point2D::distance_to(const Point2D& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx*dx + dy*dy);
}

std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
