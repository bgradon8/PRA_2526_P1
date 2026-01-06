#include <iostream>
#include "Drawing.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
    
    List<Shape*>* listImpl = new ListArray<Shape*>();

    
    Drawing d(listImpl);

   
    d.add_back(new Rectangle(Point2D(0.0, 0.0), 3.0, 4.0));      
    d.add_back(new Circle(Point2D(1.0, 1.0), 2.0));              
    d.add_front(new Rectangle(Point2D(-1.0, -1.0), 1.0, 2.0));   

    std::cout << d << std::endl;

  
    std::cout << "Figura en posición 0: " << *d[0] << std::endl;
    std::cout << "Figura en posición 1: " << *d[1] << std::endl;
    std::cout << "Figura en posición 2: " << *d[2] << std::endl;

    return 0;
}
