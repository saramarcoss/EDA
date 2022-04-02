#ifndef STACK_H
#define STACK_H
#include"tipodato.h"
#include"elementolistasimple.h"
class Stack
{
public:
    Stack();
    int size() const;
         bool empty() const;

         void push(const TipoDato& dato);
         void pop();
         const TipoDato &top()const;
     private:
         shared_ptr<ElementoListaSimple> front = nullptr;
 };
#endif // STACK_H
