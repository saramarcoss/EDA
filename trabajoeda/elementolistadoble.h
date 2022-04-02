#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include"client.h"
#include<memory>
using namespace std;
class ElementoListaDoble
{
public:
    Client dato;
    ElementoListaDoble(const Client &dato);
    shared_ptr<ElementoListaDoble>next=nullptr;
    shared_ptr<ElementoListaDoble>prev=nullptr;
};

#endif // ELEMENTOLISTADOBLE_H
