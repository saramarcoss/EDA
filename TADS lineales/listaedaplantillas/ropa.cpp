#include "ropa.h"

Ropa::Ropa(const string &_marca, float _precio, const string &_color)
{
marca=_marca;
precio=_precio;
color=_color;
}

void Ropa::set_precio(const float & _precio)
{
    precio = _precio;
}

void Ropa::set_marca(const string &_marca)
{
    marca = _marca;
}

ostream &operator<<(ostream &os, const Ropa & ropa) {
    os << "Marca: " << ropa.marca << endl << "Precio: " << ropa.precio << endl << "Color: " << ropa.color << endl;
    return os;
}
