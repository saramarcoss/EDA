#include <iostream>
#include"queue.h"
using namespace std;

/*Queue extraer_elementos_pares(Queue input) {
    Queue elempares;
    while(!input.empty()){
      auto iterator=input.front();
      input.pop();
      if(iterator.name/2==0){
        elempares.push(iterator);
      }else{
    iterator++;
      }
      return elempares;
    }
}*/
int main()
{
    auto print=[](const TipoDato &dato){
       cout<<dato.name<<"\n";
    };
    Queue cola;
    cola.push(TipoDato{1});
    cola.push(TipoDato{2});
    cola.push(TipoDato{3});
    cola.foreach(print);
}
