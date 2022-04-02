#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include<memory>
#include"elementolistadoble.h"
#include<functional>
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    void push_back(const TipoDato & dato);
    void push_front(const TipoDato & dato);
    void foreach(function<void(TipoDato & dato)>action);
    void for_each_reverse(function<void (TipoDato&)> action) const;
    void enumerate(function<void(int,TipoDato & dato)>action);
    int size()const;
    bool empty()const;
private:
    shared_ptr<ElementoListaDoble>back=nullptr;
    shared_ptr<ElementoListaDoble>front=nullptr;
};

#endif // LISTADOBLE_H
