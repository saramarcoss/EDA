#include "stack.h"

Stack::Stack()
{

}

void Stack::push(const TipoDato &dato)
{
    auto elem=make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    while(front!=nullptr){
        elem->next=front->next;
        front=elem;
    }
    front=elem;
}

void Stack::pop() {
    if (front != nullptr) {
        front = front->next;
    }
}

const TipoDato& Stack::top()const {
    return front->dato;
}
