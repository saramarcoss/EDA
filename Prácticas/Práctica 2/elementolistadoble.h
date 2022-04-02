#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include<memory>
#include"persona.h"

class ElementoListaDoble
{
public:
    Persona dato;
            std::shared_ptr<ElementoListaDoble> next = nullptr;
            std::shared_ptr<ElementoListaDoble> prev = nullptr;
        public:
            // Constructor
            ElementoListaDoble(const Persona& dato_);

};

#endif // ELEMENTOLISTADOBLE_H
