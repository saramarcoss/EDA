#include "wardrobe.h"
#include <memory>
using namespace std;
#include <iostream>

Wardrobe::Wardrobe() {}

int Wardrobe::size() const { //Devuelve el tamaño de la pila
    auto iterator = front;
    int idx = 0;
    while (iterator != nullptr) {
        idx++;
        iterator = iterator->next;
    }
    return idx;
}

bool Wardrobe::empty() const { //Compruba si esta vacia
    return this->size() == 0;
}

void Wardrobe::push(const std::string& dato) { //Inserte un elemento a la pila
    auto elem = std::make_shared<WardrobeElement>(WardrobeElement{dato});
    if (this->empty()) {
        front = elem;
    }
    else {
        elem->next = front;
        front = elem;
    }
}

void Wardrobe::pop() //Quita un elemento
{

    front = front->next;

}

std::string& Wardrobe::top() const { //Devuelve el primer elemento de la pila
    return front->owner;
}

//Crea dos pilas donde almacena hombre y mujeres
void wardrobe(Queue& joy_slava, Wardrobe& men, Wardrobe& women) {
    while (!joy_slava.empty()) {
        auto elem = joy_slava.front();
        joy_slava.pop();
        if (elem.get_gender() == 1) {
            women.push(elem.get_name());
        }
        else if (elem.get_gender() == 0) {
            men.push(elem.get_name());
        }
    }
}
