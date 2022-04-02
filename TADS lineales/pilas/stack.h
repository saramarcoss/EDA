#ifndef STACK_H
#define STACK_H
#include<functional>
#include"TipoDato.h"
#include"elementolistasimple.h"

class Stack
{
public:
    Stack();
         int size() const;
         bool empty() const;
         void forEach(function<void (const TipoDato & dato)> action);
         void push(const TipoDato& dato);
         void pop();
         const TipoDato &top()const;
     private:
         shared_ptr<ElementoListaSimple> front = nullptr;
 };

#endif // STACK_H
