#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D {
private:
    double x;
    double y;

public:
    Point2D();
    Point2D(double x, double y);

    double get_x() const;
    double get_y() const;

    void set_x(double x);
    void set_y(double y);

    void translate(double dx, double dy);
    double distance_to(const Point2D& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Point2D& p);
};

#endif
