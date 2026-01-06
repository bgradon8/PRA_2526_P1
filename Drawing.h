#ifndef DRAWING_H
#define DRAWING_H

#include <ostream>
#include "List.h"
#include "ListArray.h"
#include "ListLinked.h"
#include "Shape.h"

class Drawing {
private:
    List<Shape*>* shapes;

public:
    Drawing(List<Shape*>* listImpl);
    ~Drawing();

    void add_front(Shape* s);
    void add_back(Shape* s);
    int size() const;
    Shape* operator[](int pos);

    friend std::ostream& operator<<(std::ostream& out, const Drawing& d);
};

#endif
