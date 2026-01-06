#include <iostream>
#include "ListLinked.h"

int main() {
    std::cout << std::boolalpha;

    ListLinked<int> l;

    std::cout << l;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << std::endl;

    l.append(-5);
    l.append(0);
    l.append(5);
    l.append(10);

    std::cout << l;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "l.get(0) => " << l.get(0)
              << "; l[0] => " << l[0] << std::endl;
    std::cout << "l.get(3) => " << l.get(3)
              << "; l[3] => " << l[3] << std::endl;
    std::cout << std::endl;

    std::cout << "l.remove(3) => " << l.remove(3) << ": " << std::endl;
    std::cout << "l.remove(1) => " << l.remove(1) << ": " << std::endl;
    std::cout << "l.remove(0) => " << l.remove(0) << ": " << std::endl;
    std::cout << std::endl;

    std::cout << l;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << std::endl;

    l.prepend(33);
    l.append(14);

    std::cout << l;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "l.search(14) => " << l.search(14) << std::endl;
    std::cout << "l.search(55) => " << l.search(55) << std::endl;

    try {
        l.insert(-1, 99);
    } catch (const std::out_of_range& e) {
        std::cout << "l.insert(-1, 99) => std::out_of_range: "
                  << e.what() << std::endl;
    }

    try {
        l.insert(4, 99);
    } catch (const std::out_of_range& e) {
        std::cout << "l.insert(4, 99) => std::out_of_range: "
                  << e.what() << std::endl;
    }

    try {
        l.get(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "l.get(-1) => std::out_of_range: "
                  << e.what() << std::endl;
    }

    try {
        l.get(3);
    } catch (const std::out_of_range& e) {
        std::cout << "l.get(3) => std::out_of_range: "
                  << e.what() << std::endl;
    }

    try {
        l.remove(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "l.remove(-1) => std::out_of_range: "
                  << e.what() << std::endl;
    }

    try {
        l.remove(3);
    } catch (const std::out_of_range& e) {
        std::cout << "l.remove(3) => std::out_of_range: "
                  << e.what() << std::endl;
    }

    return 0;
}
