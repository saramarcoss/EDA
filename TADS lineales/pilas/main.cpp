#include <iostream>
#include"stack.h"
using namespace std;

int main()
{
    auto print=[](const TipoDato &dato){
       cout<<dato.name<<"\n";
    };
   Stack pila;
   pila.push(TipoDato{"one"});
   pila.push(TipoDato{"two"});
   pila.push(TipoDato{"three"});
   pila.forEach(print);
   TipoDato const & data= pila.top();
   cout<<data.name<<"\n";
   pila.forEach(print);
}
