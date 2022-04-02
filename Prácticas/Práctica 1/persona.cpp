#include "persona.h"
string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const string &value)
{
    nombre = value;
}

int Persona::getAnnac() const
{
    return annac;
}

void Persona::setAnnac(int value)
{
    annac = value;
}

string Persona::getDni() const
{
    return dni;
}

void Persona::setDni(const string &value)
{
    dni = value;
}

string Persona::getTelef() const
{
    return telef;
}

void Persona::setTelef(const string &value)
{
    telef = value;
}

void Persona::print() const
{
    cout<<"nombre: "<<nombre<<" ano nacimiento: "<<annac<<" dni: "<<dni<<" telefono: "<<telef;
}

int Persona::age(int year) const
{
    return year-annac;
}

bool Persona::isAdult(int year) const
{
    return year-annac>18;
}
