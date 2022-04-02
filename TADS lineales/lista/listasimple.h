#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include<memory>
#include"elementolistasimple.h"
#include<functional>
class ListaSimple
{
public:
    ListaSimple();
    void forEach(function<void(const TipoDato & dato)>action);
    void enumerate(function<void(int, const TipoDato & dato)>action);
    int size()const;
    bool isempty()const;
    TipoDato _front()const;
    TipoDato _back()const;
    TipoDato _at(int pos)const;
    void push_back(const TipoDato & dato);
    void push_front(const TipoDato & dato);
    void insert(const TipoDato & dato, int pos);
    void pop_back();
    void pop_front();
    void clear();
    void erase(int pos);
    int find(const TipoDato & dato);
    bool equal(const TipoDato&, const TipoDato&);
private:
    shared_ptr<ElementoListaSimple>front=nullptr;
    shared_ptr<ElementoListaSimple>back=nullptr;
};

#endif // LISTASIMPLE_H

