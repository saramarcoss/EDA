#ifndef TIPODATO_H
#define TIPODATO_H
#include<iostream>
using namespace std;
struct TipoDato{
    int dato;
    bool operator>(const TipoDato& dato) const
    {
        return this->dato>dato.dato;
    }
    bool operator<(const TipoDato& dato) const
    {
        return this->dato<dato.dato;
    }
    bool operator==(const TipoDato& dato) const
    {
        return this->dato==dato.dato;
    }
};

#endif // TIPODATO_H
