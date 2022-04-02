#include <iostream>
#include"listasimple.h"
#include<vector>
#include"doublelinkedList.h"
using namespace std;

int main()
{
    ListaSimple lista;
    lista.push_back(TipoDato{"algo"});
    lista.push_back(TipoDato{"algomas"});
    lista.push_back(TipoDato{"holi"});
    lista.push_front(TipoDato{"holi"});

    auto print=[](const TipoDato &dato){
       cout<<dato.name<<"\n";
    };
    auto print2=[](int index,const TipoDato &dato){
       cout<<index<<":"<<dato.name<<"\n";
    };
    lista.forEach(print);
    lista.enumerate(print2);
    cout<<lista.size()<<"\n";
    cout<<lista.size()<<"\n";
    cout<<lista.isempty()<<"\n";
    lista.insert(TipoDato{"inserto"},3);
    lista.forEach(print);
    lista.pop_front();
    lista.forEach(print);
    cout<<"___________________\n";
    lista.erase(2);
    lista.forEach(print);
    cout<<lista.find(TipoDato{"holi"})<<"\n";

    DoubleLinkedList lista2;
    vector< string > datos{ "1" , "2" , "3" , "4" , "5" , "6" };
     for  (auto it: datos) {
           lista2.push_back (TipoDato{it});
     }
     auto  collect = [&]( TipoDato &   dato )  {  std::cout << dato.name << std::endl; };
     lista2.foreach(collect); // Iterate forwards
     lista2.for_each_reverse(collect);
    return 0;

}
