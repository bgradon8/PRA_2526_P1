#include "Drawing.h"

Drawing::Drawing(List<Shape*>* listImpl)
    : shapes(listImpl)
{
}

Drawing::~Drawing() {
    if (shapes != nullptr) {
        while (!shapes->empty()) {
            Shape* s = shapes->remove(0);
            delete s;
        }
        delete shapes;
        shapes = nullptr;
    }
}

void Drawing::add_front(Shape* s) {
    shapes->prepend(s);
}

void Drawing::add_back(Shape* s) {
    shapes->append(s);
}

int Drawing::size() const {
    return shapes->size();
}

Shape* Drawing::operator[](int pos) {
    return shapes->get(pos);
}

std::ostream& operator<<(std::ostream& out, const Drawing& d) {
    out << "Drawing (" << d.size() << " shapes):\n";
    for (int i = 0; i < d.size(); ++i) {
        Shape* s = d.shapes->get(i);
        out << "  " << *s << "\n";
    }
    return out;
}
