#include <iostream>
#include "Rectangle.h"

int main() {
    Point2D c(1.0, 2.0);
    Rectangle r(c, 3.0, 4.0);   

    std::cout << "Rectángulo r: " << r << std::endl;
    std::cout << "Área de r: " << r.area() << std::endl;

    Shape* s = new Rectangle(Point2D(0.0, 0.0), 5.0, 2.0);
    std::cout << "Figura s (Rectangle como Shape*): " << *s << std::endl;
    std::cout << "Área de s: " << s->area() << std::endl;

    delete s;
    return 0;
}
