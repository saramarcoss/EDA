#include <iostream>
#include "ropa.h"
#include "ElementoListaDoble.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    Ropa prenda1("zara", 29.99, "azul");
    Ropa prenda2("stradivarius", 40.20, "marron");
    Ropa prenda3("pull and bear", 30, "negro");
    cout<<prenda1<<"\n";

    LinkedList<Ropa> armario;
    armario.push_back(prenda1);
    armario.push_back(prenda2);

    function<void (const Ropa & )> f = [](const Ropa &ropa) {
        cout << ropa;
    };

    armario.for_each(f);

}
