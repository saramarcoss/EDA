#ifndef QUEUE_H
#define QUEUE_H
#include"elementolistadoble.h"
#include<functional>

class Queue
{
public:
    Queue();
    int size() const;
    bool empty() const;

    TipoDato& front() const;
    TipoDato& back() const;

    void push(const TipoDato& dato);
    void pop();
    void foreach(function<void(TipoDato&)>action);
private:
    shared_ptr<ElementoListaDoble> _front = nullptr;
    shared_ptr<ElementoListaDoble> _back = nullptr;

};

#endif // QUEUE_H
