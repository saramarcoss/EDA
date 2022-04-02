#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H
#include<iostream>
#include<memory>
#include"TipoDato.h"

class ElementoArbolBinario
{
public:
        // Members
        TipoDato dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor
        ElementoArbolBinario(const TipoDato& dato_);
};

#endif // ELEMENTOARBOLBINARIO_H
