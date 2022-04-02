#include "queue.h"

Queue::Queue()
{

}

int Queue::size() const
{
    int idx=0;
    auto iterator=_front;
    while(iterator!=nullptr){
        iterator=iterator->next;
        idx++;
    }
    return idx;
}

bool Queue::empty() const
{
    return _front==nullptr;
}

Client &Queue::front() const
{
    return _front->dato;
}

Client &Queue::back() const
{
    return _back->dato;
}

void Queue::push(const Client &dato)
{
    auto elem=make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if(_front==nullptr){
       _front=elem;
       _back=elem;
    }else{
    elem->prev=_back;
    _back->next=elem;
    _back=elem;
    }
}

void Queue::pop()
{
    _front=_front->next;
    _front->prev=nullptr;
}
void Queue::foreach(function<void (Client &)> action)
{
    auto iterator=_front;
    while(iterator!=nullptr){
        action(iterator->dato);
        iterator=iterator->next;
    }
}
