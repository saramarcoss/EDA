#include "doublelinkedList.h"
DoubleLinkedList::DoubleLinkedList()
{

}
void DoubleLinkedList::push_back(const TipoDato & dato){
    shared_ptr<ElementoListaDoble>elem=make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if(front==nullptr){
      front=elem;
      back=elem;
    }else{
        elem->prev=back;//dif entre lista simple y doble
        back->next=elem;
        back=elem;
    }
}

void DoubleLinkedList::push_front(const TipoDato &dato)
{
   shared_ptr<ElementoListaDoble>elem=make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
   if(front==nullptr){
       front=elem;
       back=elem;
   }
   front->prev=elem;
   front=elem;
}

void DoubleLinkedList::foreach(function<void (TipoDato &)> action)
{
    auto iterator=front;
    while(iterator!=nullptr){
        action(iterator->dato);
        iterator=iterator->next;
    }
}

void DoubleLinkedList::for_each_reverse(function<void (TipoDato &)> action) const
{
    auto iterator=back;
    while(iterator!=nullptr){
        action(iterator->dato);
        iterator=iterator->prev;
    }
}

void DoubleLinkedList::enumerate(function<void (int, TipoDato &)> action)
{
    int idx=0;
    auto iterator=front;
    while(iterator!=nullptr){
        action(idx,iterator->dato);
        iterator=iterator->next;
        idx++;
    }
}
int DoubleLinkedList::size()const{
    int idx=0;
    auto iterator=front;
    while(iterator!=nullptr){
        iterator=iterator->next;
        idx++;
    }
    return idx;
}

bool DoubleLinkedList::empty() const
{
    return front==nullptr;
}
