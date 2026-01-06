#include <iostream>
#include "Point2D.h"

int main() {
    Point2D p1;
    Point2D p2(3.0, 4.0);

    std::cout << "Punto p1 (por defecto): " << p1 << std::endl;
    std::cout << "Punto p2 (3,4):        " << p2 << std::endl;

    p1.set_x(1.0);
    p1.set_y(2.0);
    std::cout << "p1 después de set_x/set_y (1,2): " << p1 << std::endl;

    std::cout << "p1.get_x(): " << p1.get_x() << std::endl;
    std::cout << "p1.get_y(): " << p1.get_y() << std::endl;

    p1.translate(2.0, -1.0);
    std::cout << "p1 después de translate(+2,-1): " << p1 << std::endl;

    double dist = p1.distance_to(p2);
    std::cout << "Distancia de p1 a p2: " << dist << std::endl;

    return 0;
}
