#include "persona.h"

Persona::Persona(const std::string& name, const std::string& dni, int gender)
   : name{name}, dni{dni}, gender{gender} {

}

const std::string& Persona::get_name() const { //Devuelve el nombre
    return name;
}

int Persona::get_gender() const { //Devuelve el genero
    return gender;
}

const std::string& Persona::get_dni() const { //Devuelve el DNI
    return dni;
}

bool Persona::operator==(const Persona& other) const {
    return (name == other.name) && (dni == other.dni) && (gender == other.gender);
}
