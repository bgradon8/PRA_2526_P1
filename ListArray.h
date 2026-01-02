#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size);

public:
    ListArray();
    ~ListArray();

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;

    T operator[](int pos);

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "List => [";
        if (list.n > 0) {
            out << "\n";
            for (int i = 0; i < list.n; ++i) {
                out << "  " << list.arr[i] << "\n";
            }
        }
        out << "]\n";
        return out;
    }
};

#endif
