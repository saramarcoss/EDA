#ifndef NAMECOUNTER_H
#define NAMECOUNTER_H


#include <string>
#include <functional>

#include "queue.h"

struct NameCount {
    int repeats;
    std::string name;
};

class ElementListaSimple {
    public:
        NameCount dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        ElementListaSimple(const NameCount& dato_);
};

class NameCounter {
    public:
        NameCounter();

        void add_name(const std::string& name);
        void sort();
        void for_each(std::function<void (const NameCount&)> action) const;
    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
};

NameCounter count_names(Queue& joy_slava);
#endif // NAMECOUNTER_H
