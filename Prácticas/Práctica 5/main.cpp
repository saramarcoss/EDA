#include <iostream>
#include <fstream>
#include <cstdlib>
#include "graphe.h"
using namespace std;

//Practica hecha por Arturo Requejo y David Gregorio

int main() {

    Graph<string , int, 23> grafo;

    ifstream infile("/home/arturo/Descargas/Ciudades.txt");
    string line;

    while (getline(infile, line)) {
        int separador = line.find(" ");
        string id = line.substr(0, separador);
        int numero = stoi(id);
        string name = line.substr(separador+1, line.size());

        grafo.add_node(numero, name);

    }

    ifstream infile1("/home/arturo/Descargas/Distancias.txt");
    while (getline(infile1, line)) {
        int separador = line.find(" ");
        string id1 = line.substr(0, separador);
        int numero1 = stoi(id1);

        int c = line.find(" ", separador+1);
        string id2 = line.substr(separador+1, c);
        int numero2 = stoi(id2);

        string distancia = line.substr(c + 1);

        int numero3 = stoi(distancia);

        grafo.add_edge(numero1, numero2, numero3);
    }

    cout << grafo << endl;

    cout << endl;

    cout << grafo.are_connected("Sevilla", "Granada") << endl;
    //Suma de todos los kilometros de carretera
    cout << grafo.sum_kilometers() << endl;




    return 0;

}
