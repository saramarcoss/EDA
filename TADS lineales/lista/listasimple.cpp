#include "listasimple.h"

ListaSimple::ListaSimple()
{

}

void ListaSimple::forEach(function<void (const TipoDato & dato)> action)
{
    auto iterator=front;
    while(iterator!=nullptr){
        action(iterator->dato);
        iterator=iterator->next;
    }
}
void ListaSimple::enumerate(function<void (int,const TipoDato & dato)> action)
{
    auto iterator=front;
    int count=0;
    while(iterator!=nullptr){
        action(count, iterator->dato);
        iterator=iterator->next;
        count++;
    }
}

int ListaSimple::size() const
{
    int count=0;
    auto iterator=front;
    while(iterator!=nullptr){
    iterator=iterator->next;
    count++;
    }
    return count;
}

bool ListaSimple::isempty() const
{
    auto iterator=front;
    if(iterator==nullptr){
        return true;
    }
    return false;
}

TipoDato ListaSimple::_front() const
{
    return front->dato;
}

TipoDato ListaSimple::_back() const
{
    return back->dato;
}

TipoDato ListaSimple::_at(int pos) const
{
    auto iterator=front;
    int idx=0;
    while(iterator!=nullptr){
        if(idx==pos){
            break;
        }
        iterator=iterator->next;
        idx++;
    }
    return iterator->dato;
}

void ListaSimple::push_back(const TipoDato &dato)
{
   shared_ptr<ElementoListaSimple>elem=make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
   if (front==nullptr){
       front=elem;
       back=elem;
   }
   back->next=elem;
   back=elem;
}

void ListaSimple::push_front(const TipoDato &dato)
{
    shared_ptr<ElementoListaSimple>elem=make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front==nullptr){
        front=elem;
        back=elem;
    }
    elem->next=front;
    front=elem;
}

void ListaSimple::insert(const TipoDato &dato, int pos)
{
    shared_ptr<ElementoListaSimple>elem=make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(pos==0){
        push_front(dato);
    }else{
        auto iterator = front;
        int idx = 0;
        while (idx != pos - 1) {
            iterator = iterator->next;
            idx++;
        }
        elem->next = iterator->next;
        iterator->next = elem;
    }
}

void ListaSimple::pop_back(){
    if(this->size()==0){
        return;
    }
    auto iterador=front;
    while(iterador->next->next!=nullptr){
        iterador=iterador->next;
    }
    iterador->next=nullptr;
    back=iterador;
}

void ListaSimple::pop_front()
{
    front=front->next;
}

void ListaSimple::clear()
{
    front=nullptr;
    back=nullptr;
}

void ListaSimple::erase(int pos)
{
    auto iterator=front;
    int idx=0;
    while(iterator!=nullptr){
    if(idx==pos-1){
        break;
    }
    iterator=iterator->next;
    idx++;
    }
    iterator->next=iterator->next->next;
}
bool ListaSimple::equal(const TipoDato& lhs, const TipoDato& rhs) {
    return lhs.name == rhs.name;
}
int ListaSimple::find(const TipoDato &dato)
{
    auto iterator=front;
    int found=-1;
    int idx=0;
    while(iterator!=nullptr){
        if(equal(iterator->dato,dato)){
            found=idx;
        }
        iterator=iterator->next;
        idx++;
    }
    return found;
}


