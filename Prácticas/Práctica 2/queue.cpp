#include <queue.h>


Queue::Queue() {}

int Queue::size() const { //Devuelve el tamaño
    auto iterator = _front;
    int idx = 0;
    while (iterator != nullptr) {
        idx++;
        iterator = iterator->next;
    }
    return idx;
}

bool Queue::empty() const { //Comprueba si esta vacio
    return this->size() == 0;
}

Persona& Queue::front() const { //Devuelve el primer elemento
    return _front->dato;
}

Persona& Queue::back() const { //Devuelve el ultimo
    return _back->dato;
}

void Queue::push(const Persona& dato) { //Inserta un elemento y se añade al final
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (this->empty()) {
        _front = _back = elem;
    }
    else {
        _back->next = elem;
        _back = elem;
    }
}

void Queue::pop() { //Quita el primer elemento de la cola
    _front = _front->next;
    if (_front == nullptr) {
        _back = _front;
    }
}

//Colar en orden a los friends justo detrás del elemento contact
void Queue::sneak_in(const Persona& contact, Queue& friends) {
    auto iterator = _front;
    while (iterator != nullptr) {
        if (iterator->dato == contact) {
            auto sneaker = iterator;
            auto next_elem = sneaker->next;
            while (!friends.empty()) {
                auto next_friend = friends.front();
                friends.pop();
                sneaker->next = std::make_shared<ElementoListaDoble>(ElementoListaDoble{next_friend});
                sneaker = sneaker->next;
            }
            sneaker->next = next_elem;
            break;
        }
        iterator = iterator->next;
    }

}
