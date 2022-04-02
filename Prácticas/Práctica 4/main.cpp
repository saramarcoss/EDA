#include <iostream>
#include <fstream>
#include "printer.h"
using namespace std;

void lectura(){
    ifstream archivo;
    string texto;

    archivo.open("/home/arturo/Descargas/Apartado4.txt", ios::in);

    while(getline(archivo, texto)){
        cout << "Trabajo: ";
        cout << texto << endl;
    }
}

//Practica 4 por Arturo Requejo y David Gregorio

int main()
{

    lectura();
    PrintJob l1 {1619285669, 521, "Cien Años de Soledad"};
    Printer p {5,1000};
    cout << p.push(l1) << endl;



}
