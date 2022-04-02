#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H
#include<memory>
#include"TipoDato.h"

class ElementoListaSimple
{
public:
    ElementoListaSimple(const TipoDato & _dato);
    const TipoDato & dato;
    shared_ptr<ElementoListaSimple>next=nullptr;
};

#endif // ELEMENTOLISTASIMPLE_H
