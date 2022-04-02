#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
using namespace std;

class Persona
{
public:
    Persona(string n,int a,string dn,string t):nombre{n},annac{a},dni{dn},telef{t}{}
    string getNombre() const;
    void setNombre(const string &value);

    int getAnnac() const;
    void setAnnac(int value);

    string getDni() const;
    void setDni(const string &value);

    string getTelef() const;
    void setTelef(const string &value);
    void print()const;
    int age(int year)const;
    bool isAdult(int year)const;

protected:
    string nombre;
    int annac;
    string dni;
    string telef;
};

#endif // PERSONA_H
