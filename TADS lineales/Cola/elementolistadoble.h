#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include"TipoDato.h"
#include<memory>
class ElementoListaDoble
{
public:
    TipoDato dato;
    ElementoListaDoble(const TipoDato &dato);
    shared_ptr<ElementoListaDoble>next=nullptr;
    shared_ptr<ElementoListaDoble>prev=nullptr;
};


#endif // ELEMENTOLISTADOBLE_H
