#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include <memory>
#include <iostream>
#include "ropa.h"
using namespace std;

template <typename T>
class ElementoListaDoble {
public:
    ElementoListaDoble(const T &_dato): dato{_dato}{}
    T dato;
    shared_ptr<ElementoListaDoble<T>> next = nullptr;
    shared_ptr<ElementoListaDoble<T>> prev = nullptr;
};
#endif // ELEMENTOLISTADOBLE_H
