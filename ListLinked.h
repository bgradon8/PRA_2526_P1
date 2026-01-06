#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

    Node<T>* node_at(int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return aux;
    }

public:
    ListLinked()
        : first(nullptr), n(0) {}

    ~ListLinked()  {
        Node<T>* aux = first;
        while (aux != nullptr) {
            Node<T>* next = aux->next;
            delete aux;
            aux = next;
        }
        first = nullptr;
        n = 0;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T get(int pos) override {
        Node<T>* p = node_at(pos);
        return p->data;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = node_at(pos - 1);
            Node<T>* nuevo = new Node<T>(e, prev->next);
            prev->next = nuevo;
        }

        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }

        T value;
        Node<T>* to_del;

        if (pos == 0) {
            to_del = first;
            value = to_del->data;
            first = first->next;
        } else {
            Node<T>* prev = node_at(pos - 1);
            to_del = prev->next;
            value = to_del->data;
            prev->next = to_del->next;
        }

        delete to_del;
        n--;
        return value;
    }

    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return pos;
            }
            aux = aux->next;
            pos++;
        }
        return -1;
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "List => [";
        if (list.n > 0) {
            out << "\n";
            Node<T>* aux = list.first;
            while (aux != nullptr) {
                out << "  " << aux->data << "\n";
                aux = aux->next;
            }
        }
        out << "]\n";
        return out;
    }
};

#endif
