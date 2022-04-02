#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include "ElementoListaDoble.h"
#include <functional>

template <typename T>
class LinkedList{
public:
    LinkedList(){}

    void push_back(const T &lib)
    {
        if(_front == nullptr){
            _front = make_shared<ElementoListaDoble<T>>(ElementoListaDoble<T>{lib});
        }
        else{
            auto iterator = _front;
            while(iterator->next != nullptr){
                iterator = iterator->next;
            }
            auto elem = make_shared<ElementoListaDoble<T>>(ElementoListaDoble<T>{lib});
            iterator->next = elem;
            elem->prev = iterator;
        }

    }

    void for_each(function<void (const T &)> &action) const
    {
        auto iterator = _front;
        while(iterator != nullptr){
            action(iterator->dato);
            iterator = iterator->next;
        }
    }
private:
    shared_ptr<ElementoListaDoble<T>> _front = nullptr;
};

#endif // LINKEDLIST_H
