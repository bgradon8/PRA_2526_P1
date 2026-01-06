#include <iostream>
#include "Circle.h"

int main() {
    Point2D c1(0.0, 0.0);
    Circle c(c1, 2.0);   

    std::cout << "Círculo c: " << c << std::endl;
    std::cout << "Área de c: " << c.area() << std::endl;

  
    Shape* s = new Circle(Point2D(1.0, 1.0), 3.0);
    std::cout << "Figura s (Circle como Shape*): " << *s << std::endl;
    std::cout << "Área de s: " << s->area() << std::endl;

    delete s;
    return 0;
}
