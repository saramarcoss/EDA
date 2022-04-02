#ifndef WARDROBEELEMENT_H
#define WARDROBEELEMENT_H
#include<iostream>
#include<memory>

class WardrobeElement {
    public:
        // Members
        std::string owner;
        std::shared_ptr<WardrobeElement> next = nullptr;

    public:
        // Constructor
        WardrobeElement(const std::string& owner);
};
#endif // WARDROBEELEMENT_H
