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

    Client & front() const;
    Client& back() const;

    void push(const Client& dato);
    void pop();
    void foreach(function<void(Client&)>action);
private:
    shared_ptr<ElementoListaDoble> _front = nullptr;
    shared_ptr<ElementoListaDoble> _back = nullptr;

};

#endif // QUEUE_H
