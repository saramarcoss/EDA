#include<functional>
#include<iostream>
using namespace std;
#include "stack.h"

Stack::Stack()
{

}
void Stack::forEach(function<void (const TipoDato & dato)> action)
{
    auto iterator=front;
    while(iterator!=nullptr){
        action(iterator->dato);
        iterator=iterator->next;
    }
}

int Stack::size() const
{
    int idx=0;
    auto iterator=front;
    while(iterator!=nullptr){
        idx++;
        iterator=iterator->next;
    }
    return idx;
}

bool Stack::empty() const
{
    return (front==nullptr);
}

void Stack::push(const TipoDato &dato)
{
    auto elem=make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front==nullptr){
        front=elem;
    }
    else{
        elem->next=front;
        front=elem;
    }
}

void Stack::pop() {
    if (front != nullptr) {
        front = front->next;
    }
}

const TipoDato& Stack::top()const {
    return front->dato;
}

