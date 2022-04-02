#ifndef ROPA_H
#define ROPA_H
#include <iostream>
using namespace std;

class Ropa
{
public:
    friend ostream &operator<<(ostream &os, const Ropa & ropa);
    Ropa(const string &_marca, float _precio, const string &_color);
    void set_precio(const float & _precio);
    void set_marca(const string &_marca);
public:
    string marca;
    float precio;
    string color;
};
ostream &operator<<(ostream &os, const Ropa & ropa);


#endif // ROPA_H
