#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H
#include<iostream>
#include<memory>
#include"TipoDato.h"
using namespace std;

class ElementoListaSimple
{
public:
    ElementoListaSimple();
    TipoDato dato;
    shared_ptr<ElementoListaSimple>next=nullptr;
};

#endif // ELEMENTOLISTASIMPLE_H
