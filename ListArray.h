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

template <typename T>
ListArray<T>::ListArray() {
    max = MINSIZE;
    n = 0;
    arr = new T[max];
}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}

template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}

template <typename T>
int ListArray<T>::size() {
    return n;
}

template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición inválida!");
    }
    return arr[pos];
}

template <typename T>
void ListArray<T>::resize(int new_size) {
    if (new_size < MINSIZE) {
        new_size = MINSIZE;
    }

    T* new_arr = new T[new_size];

    int limit = (n < new_size) ? n : new_size;
    for (int i = 0; i < limit; ++i) {
        new_arr[i] = arr[i];
    }

    delete[] arr;

    arr = new_arr;
    max = new_size;

    if (n > max) {
        n = max;
    }
}

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Posición inválida!");
    }

    if (n == max) {
        resize(max * 2);
    }

    for (int i = n - 1; i >= pos; --i) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = e;
    n++;
}

template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición inválida!");
    }

    T value = arr[pos];

    for (int i = pos + 1; i < n; ++i) {
        arr[i - 1] = arr[i];
    }

    n--;

    if (n <= max / 4 && max > MINSIZE) {
        resize(max / 2);
    }

    return value;
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T ListArray<T>::operator[](int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición inválida!");
    }
    return arr[pos];
}

#endif
