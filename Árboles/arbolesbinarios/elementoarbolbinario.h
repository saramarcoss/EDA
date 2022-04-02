#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H
#include"TipoDato.h"
#include<memory>

class ElementoArbolBinario
{
public:
    TipoDato dato;
            std::shared_ptr<ElementoArbolBinario> left = nullptr;// dif con respecto a un arbol normal
            std::shared_ptr<ElementoArbolBinario> right = nullptr;
        public:
            // Constructor
            ElementoArbolBinario(const TipoDato& dato_);
    };

#endif // ELEMENTOARBOLBINARIO_H
