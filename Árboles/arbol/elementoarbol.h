#ifndef ELEMENTOARBOL_H
#define ELEMENTOARBOL_H
#include<vector>
#include<iostream>
#include<memory>
#include"TipoDato.h"
using namespace std;
class ElementoArbol
{
public:
        // Members
        TipoDato dato;
        vector<shared_ptr<ElementoArbol>> children;
    public:
        // Constructor
        ElementoArbol(const TipoDato& dato_);
};
#endif // ELEMENTOARBOL_H
